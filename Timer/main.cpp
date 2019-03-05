#include "stdafx.h"
#include "Timer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Timer w;
	w.show();
	return a.exec();
}
