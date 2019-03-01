#include "stdafx.h"
#include "Timer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication::addLibraryPath("C:\Qt\Qt5.12.1\5.12.1\msvc2017_64\plugins");
	QApplication::addLibraryPath("C:\Qt\Qt5.12.1\5.12.1\msvc2017_64\lib");
	QApplication a(argc, argv);
	Timer w;
	w.show();
	return a.exec();
}
