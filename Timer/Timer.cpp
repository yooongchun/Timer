#include "stdafx.h"
#include "Timer.h"

Timer::Timer(QWidget *parent)
	: QMainWindow(parent)
{	
	ui.setupUi(this);
	connect(ui.start, SIGNAL(clicked()), this, SLOT(StartBtnClick()));
	connect(ui.pause, SIGNAL(clicked()), this, SLOT(PauseBtnClick()));
	connect(ui.finish, SIGNAL(clicked()), this, SLOT(FinishBtnClick()));
	connect(ui.import_2, SIGNAL(clicked()),this, SLOT(importData()));
	connect(ui.new_2, SIGNAL(clicked()), this,SLOT(newProj()));
	connect(ui.save, SIGNAL(clicked()),this, SLOT(save()));
	connect(ui.about, SIGNAL(triggered()), this, SLOT(OnAbout()));
	connect(ui.export_2,SIGNAL(clicked()),this,SLOT(export_data()));

	pTimer->setInterval(1000);
	connect(pTimer, SIGNAL(timeout()), this, SLOT(onTimeOut()));

	ui.time_counter->setDigitCount(9);//设置显示位数
	ui.time_counter->setMode(QLCDNumber::Dec);//设置显示数制
	ui.time_counter->setSegmentStyle(QLCDNumber::Flat);//设置显示外观
	//ui.time_counter->setStyleSheet("");//设置样式
	loadData();
}

template <typename Archive>
void serialize(Archive &ar, Timer::Project &p, const unsigned int version)
{
	ar & p.name;
	ar &p.author;
	ar &p.startTime;
	ar &p.totalTime;
	ar &p.preTime;
	ar &p.workTimeList;
}

void Timer::OnAbout() {
	QMessageBox::information(this, "关于", "项目计时器\nCopyright by Yongchun Zha;\n联系方式：yooongchun@foxmail.com");
}

int Timer::importData() {
	setBtnState(IMPORT_BTN);
	QString filename = QFileDialog().getOpenFileName(this, tr("action"), "", "file(*.dat)");
	proj = readData(filename.toStdString());
	update_to_ui();
	return 1;
}

int Timer::newProj() {
	setBtnState(NEW_BTN);
	Project proj_new;
	proj = proj_new;
	update_to_ui();
	return 1;
}

int Timer::StartBtnClick() {
	QString proj_name = ui.project_name->text();
	QString user_name = ui.author->text();
	QString detailInfo = ui.detail->text();

	if (proj_name == "") {
		QMessageBox::information(this,"警告", "请输入项目名称");
	}
	else if (user_name == "") {
		QMessageBox::information(this, "警告", "请输入作者名称");
	}
	else {
		setBtnState(START_BTN);
		std::string file_name = getPath(proj_name.toStdString()); 
		std::ofstream out(settingFile, std::ios::out);
		if (out) { out << file_name; out.close(); }
		std::ifstream infile(file_name, std::ios::in);
		if (!infile) {//文件不存在，创建新工程
			infile.close();
			ui.log->append("新建日志：" + proj_name);
			update_to_proj();
			saveData(proj, file_name);
		}
		else {//文件存在，加载工程
			proj = readData(file_name);
			update_to_proj();
			update_to_ui();
		}
		pTimer->start();
	}
	return 1;
}

void Timer::loadData() {
	/*加载数据*/
	std::string fileName = "";
	std::ifstream in(settingFile, std::ios::in);
	if (in) { std::getline(in, fileName); }
	if (fileName == "") {
		ui.pause->setEnabled(false);
		ui.finish->setEnabled(false);
		ui.save->setEnabled(false);
		ui.log->append("当前没有项目日志");
		return;
	}
	setBtnState(IMPORT_BTN);
	proj = readData(fileName);
	update_to_ui();
}

void Timer::onTimeOut() {
	proj.totalTime++;
	unsigned long hours = proj.totalTime / 3600;
	unsigned long minutes = (proj.totalTime - hours * 3600) / 60;
	unsigned long seconds = proj.totalTime - hours * 3600 - minutes * 60;
	char h[] = "000";
	char m[] = "00";
	char s[] = "00";
	sprintf(h, "%03d", hours);
	sprintf(m, "%02d", minutes);
	sprintf(s, "%02d", seconds);
	QString hStr = QString::fromStdString(h);
	QString mStr = QString::fromStdString(m);
	QString sStr = QString::fromStdString(s);
	ui.time_counter->display(hStr + ":" + mStr + ":" + sStr);
	
}

int Timer::PauseBtnClick() {
	setBtnState(PAUSE_BTN);
	pTimer->stop();
	update_to_proj();
	update_to_ui();
	ui.log->append("暂停当前工作计时！");
	save();
	return 1;
}

int Timer::FinishBtnClick() {
	setBtnState(FINISH_BTN);
	pTimer->stop();
	update_to_proj();
	update_to_ui();
	ui.log->append("结束当前项目工作计时!");
	save();
	return 1;
}

void Timer::save() {
	update_to_proj();
	update_to_ui();
	saveData(proj, getPath(proj.name));
}

void Timer::saveData(Project proj, std::string path) {
	std::ofstream out(path, std::ios::binary);
	if (out) {
		boost::archive::text_oarchive oa(out);
		oa << proj;
		out.close();
	}
	else ui.log->append("无法写出文件！");
}

Timer::Project Timer::readData(std::string path) {
	std::ifstream in(path, std::ios::binary);
	Timer::Project proj;
	if (in) {
		boost::archive::text_iarchive ia(in);
		ia >> proj;
		in.close();
	}
	else ui.log->append("无法读取文件");
	return proj;
}

void Timer::setBtnState(Name name) {
	ui.start->setEnabled(false);
	ui.pause->setEnabled(false);
	ui.finish->setEnabled(false);
	ui.import_2->setEnabled(false);
	ui.save->setEnabled(false);
	ui.new_2->setEnabled(false);
	ui.project_name->setEnabled(false);
	ui.detail->setEnabled(false);
	ui.author->setEnabled(false);

	switch (name) {
	case START_BTN:
		ui.pause->setEnabled(true);
		ui.finish->setEnabled(true);
		ui.save->setEnabled(true);
		break;
	case PAUSE_BTN:
		ui.start->setEnabled(true);
		ui.finish->setEnabled(true);
		ui.detail->setEnabled(true);
		break;
	case FINISH_BTN:
		ui.import_2->setEnabled(true);
		ui.new_2->setEnabled(true);
		ui.project_name->setEnabled(true);
		ui.detail->setEnabled(true);
		ui.author->setEnabled(true);
		break;
	case NEW_BTN:
		ui.start->setEnabled(true);
		ui.import_2->setEnabled(true);
		ui.project_name->setEnabled(true);
		ui.detail->setEnabled(true);
		ui.author->setEnabled(true);
		break;
	case IMPORT_BTN:
		ui.start->setEnabled(true);
		ui.import_2->setEnabled(true);
		ui.detail->setEnabled(true);
		ui.new_2->setEnabled(true);
		break;
	case SAVE_BTN:
		ui.start->setEnabled(true);
		ui.pause->setEnabled(true);
		ui.finish->setEnabled(true);
		ui.import_2->setEnabled(true);
		ui.save->setEnabled(true);
		ui.new_2->setEnabled(true);
		ui.project_name->setEnabled(true);
		ui.detail->setEnabled(true);
		ui.author->setEnabled(true);
		break;
	}
}

void Timer::update_to_proj() {
	proj.name=ui.project_name->text().toStdString();
	proj.author = ui.author->text().toStdString();
	std::string d=ui.detail->text().toStdString();
	time_t now=time(0);
	if (proj.workTimeList.count(d) == 1) {
		proj.workTimeList[d].first += proj.totalTime-proj.preTime;
	}
	else {
		proj.workTimeList[d] = std::make_pair(proj.totalTime-proj.preTime,now);
	}
	proj.preTime = proj.totalTime;
	
}

void Timer::update_to_ui() {
	ui.project_name->setText(QString::fromStdString(proj.name));
	ui.author->setText(QString::fromStdString(proj.author));
	ui.log->setText("");
	std::unordered_map<std::string, std::pair<unsigned long, time_t>>::iterator it = proj.workTimeList.begin();
	std::vector<P> vec;
	for (; it != proj.workTimeList.end(); it++)
		vec.push_back(*it);
	std::sort(vec.begin(), vec.end(), [](P p1, P p2)->bool {return p1.second.second < p2.second.second; });
	for (int i = 0; i < vec.size(); i++){
		std::string s = time_stamp_to_str(vec[i].second.second) + "  " + std::to_string(vec[i].second.first/3600.0) +"h  "+ vec[i].first;
		ui.log->append(QString::fromStdString(s));
	}
	onTimeOut();
}

std::string Timer::time_stamp_to_str(time_t now) {
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%y-%m-%d %H:%M:%S", localtime(&(now)));
	return tmp;
}

void Timer::export_data() {
	QString path = QFileDialog().getExistingDirectory(this, tr("action"), "选择导出文件夹");
	std::ofstream out(path.toStdString()+"/"+proj.name+".csv",std::ios::out);
	if (out) {
		char utfBomHeader[4];
		utfBomHeader[0] = 0xEF;
		utfBomHeader[1] = 0xBB;
		utfBomHeader[2] = 0xBF;
		utfBomHeader[3] = '\0';
		out << utfBomHeader;
		out << "开始,时间(h),备注" << std::endl;
		std::unordered_map<std::string, std::pair<unsigned long, time_t>>::iterator it = proj.workTimeList.begin();
		std::vector<P> vec;
		for (; it != proj.workTimeList.end(); it++)
			vec.push_back(*it);
		std::sort(vec.begin(), vec.end(), [](P p1, P p2)->bool {return p1.second.second < p2.second.second; });
		for(int i=0;i<vec.size();i++)
			out<< time_stamp_to_str(vec[i].second.second) +","+std::to_string(vec[i].second.first/3600.0)+","+vec[i].first<<std::endl;
		out<<"合计,"<<(double)proj.totalTime / 3600<<" 小时,"<<(double)proj.totalTime/3600/8<<" 天";
		out.close();
		ui.log->append("保存完成！");
	}
	else ui.log->append("无法导出数据");
}