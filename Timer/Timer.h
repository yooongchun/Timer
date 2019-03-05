#pragma once

#include "ui_Timer.h"

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include<QDateTime>
#include<QMessageBox>
#include<QDateTime>
#include<QFileDialog>

#include <fstream>
#include<string>
#include<regex>
#include<thread>
#include<chrono>
#include<unordered_map>
#include<algorithm>
#include<direct.h>
#include <windows.h>
#include <shlobj.h>
#include<codecvt>
#include<locale>

#include<boost/archive/text_oarchive.hpp>
#include<boost/archive/text_iarchive.hpp>
#include<boost/serialization/string.hpp>
#include<boost/serialization/unordered_map.hpp>

class Timer : public QMainWindow
{
	Q_OBJECT

public:
	Timer(QWidget *parent = Q_NULLPTR);
public:
	struct Project {
		unsigned long totalTime = 0;
		unsigned long preTime = 0;
		std::string name = "";
		std::string author = "";
		std::string startTime = []()->std::string {char tmp[64]; time_t now = time(0); strftime(tmp, sizeof(tmp), "%y-%m-%d %H:%M:%S", localtime(&now)); return tmp; }();
		std::unordered_map <std::string, std::pair<unsigned long, time_t>> workTimeList;//detail-lastTime-startTime
		friend class boost::serialization::access;
		template <typename Archive>
		friend void serialize(Archive &ar, Project &p, const unsigned int version);
	};
private:
	Project proj;
	typedef std::pair<std::string, std::pair<unsigned long, time_t>> P;
	std::string baseDir = []()->std::string {CHAR my_documents[MAX_PATH];HRESULT result = SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, my_documents);if (result != S_OK)return "";else {std::string path = (std::string)(char*)my_documents + "/timer";int res = _mkdir((char*)path.c_str());return path;}}();
	std::string settingFile = baseDir + "/timer.setting";
	QTimer *pTimer = new QTimer(this);
	enum Name
	{
		START_BTN,
		PAUSE_BTN,
		FINISH_BTN,
		IMPORT_BTN,
		NEW_BTN,
		SAVE_BTN,
		PROJ_NAME_LINE,
		DETAIL_LINE,
		AUTHOR_LINE,
		LOG_LINE
	};
	std::string getPath(std::string projName) { return baseDir + "/" + projName + ".dat"; }
	void saveData(Project proj, std::string path);
	Project readData(std::string path);
	void loadData();
	void setBtnState(Name n);
	void update_to_proj();
	void update_to_ui();
	std::string time_stamp_to_str(time_t now);

private slots:
	int StartBtnClick();
	int PauseBtnClick();
	int FinishBtnClick();
	int importData();
	void save();
	void onTimeOut();
	int newProj();
	void OnAbout();
	void export_data();
private:
	Ui::TimerClass ui;
};
