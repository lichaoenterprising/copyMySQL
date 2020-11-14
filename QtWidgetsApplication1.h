#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include <qfiledialog.h>
#include <qprocess.h>
#include <qdebug.h>
#include <qmessagebox.h>
#include <iostream>

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = Q_NULLPTR);
	~QtWidgetsApplication1();
	QString file_full;
	QString srcDB;
	QString srcDBpwd;
	QString dstDB;
	QString dstDBpwd;
	QString judgeTrue;

	QString QStringDriveLetter;//»ñÈ¡ÅÌ·û

	QProcess *clipProcess;


	private slots:

	void on_pushButton_openpathlc_clicked();
	void on_pushButton_2_newdblc_clicked();
	void on_pushButton_3_truelc_clicked();


	void read_slot();

private:
    Ui::QtWidgetsApplication1Class ui;

};
