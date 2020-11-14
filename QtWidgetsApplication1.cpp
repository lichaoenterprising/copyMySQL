#include "QtWidgetsApplication1.h"

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{
}

void QtWidgetsApplication1::on_pushButton_openpathlc_clicked()
{

	//打开数据库下的bin文件夹
	QString  file_name, file_path;
	QString titleName = QStringLiteral("选择数据库文件夹下的bin目录");
	QFileInfo fi;
	//file_full = QFileDialog::getOpenFileName(this);
	//file_full = QFileDialog::getOpenFileName(this);
	file_full = QFileDialog::getExistingDirectory(this,titleName, "./" );

	fi = QFileInfo(file_full);
	file_name = fi.fileName();
	file_path = fi.absolutePath();
	ui.lineEdit_inputopenpathlc->setText(file_full);
	QStringList QStringListFilePath = file_path.split('/');
	QStringDriveLetter = QStringListFilePath.at(0);
	qDebug() << QStringDriveLetter;

	//打开具有管理员权限的cmd窗口

	//QProcess *poc = new QProcess;
	//QString password = "root";
	////QString Cmd = QString("mysqldump.exe --add-drop-table -u%1 -p%2 test").arg("UsrName", "UsrPsd");
	//QString Cmd = QString("mysql -u root -p%1").arg(password);
	////QString Path = QString("%1").arg("d://backup.Sql");
	//poc->setStandardOutputFile(file_full);
	//poc->start(Cmd);

	//在cmd窗口下跳转到指定路径

}

void QtWidgetsApplication1::on_pushButton_2_newdblc_clicked()
{
	//输入mysql -u root -p加密码命令进入数据库
	QProcess *poc = new QProcess;
	QString password = ui.lineEdit->text();
	//QString Cmd = QString("mysqldump.exe --add-drop-table -u%1 -p%2 test").arg("UsrName", "UsrPsd");
	QString Cmd = QString("mysql -u root -p%1").arg(password);
	//QString Path = QString("%1").arg("d://backup.Sql");
	poc->setStandardOutputFile(file_full);
	poc->start(Cmd);

	//在数据库中输入create database 数据库名创建新数据库


}

void QtWidgetsApplication1::on_pushButton_3_truelc_clicked()
{

	//QProcess *poc1 = new QProcess;
	QString Cmd1 = QString("cd \ ");
	QString Cmd2 = QString(QStringDriveLetter);
	QString Cmd3 = QString("cd " + file_full);
	//poc1->start(Cmd1);
	//poc1->start(Cmd2);
	//poc1->start(Cmd3);
	//poc1->waitForStarted();
	//poc1->waitForFinished();



	//QProcess *poc = new QProcess;
	QString password = ui.lineEdit->text();
	srcDB = ui.lineEdit_3inputdbsrclc->text();
	srcDBpwd = ui.lineEdit_4_inputdbsrcpwdlc->text();
	dstDB = ui.lineEdit_5_inputdbdstlc->text();
	dstDBpwd = ui.lineEdit_6_inputdbdstpwdlc->text();
	////QString Cmd = QString("mysqldump.exe --add-drop-table -u%1 -p%2 %3").arg(srcDB, srcDBpwd,dstDB);
	QString Cmd = QString("mysqldump %1 -u root -p%2 --add-drop-table | mysql %3 -u root -p%4").arg(srcDB,srcDBpwd,dstDB,dstDBpwd);

	//QString Cmd4 = QString("ping www.baidu.com");
	////mysqldump ceshicopy -u root -proot --add-drop-table | mysql newdb -u root -proot
	////QString Path = QString("%1").arg("d://backup.Sql");
	//qDebug() << Cmd3;
	//qDebug() << Cmd;
	//qDebug() << file_full;
	//poc->setStandardOutputFile(file_full);
	////poc->start(Cmd);
	//poc->start(Cmd4);
	//poc->waitForStarted();
	//poc->waitForFinished();

	////将收到的回复显示出来
	//QString strTemp = QString::fromLocal8Bit(poc->readAllStandardOutput());
	//QMessageBox testMassage;
	//testMassage.setText(strTemp);
	//testMassage.exec();

	//QProcess p(0);

	////p.start("cmd", QStringList() << "/c" << "ping www.baidu.com");
	////p.start("cmd", QStringList() <<"/c"<< Cmd1 << Cmd2 << Cmd3 << Cmd);
	//p.start("cmd", QStringList() << "/c" << "cd \ "<<"d:"<<"cd D:\mysql\mysql-8.0.19-winx64\mysql-8.0.19-winx64\bin"<< "mysqldump ceshicopy -u root -proot --add-drop-table | mysql newdb -u root -proot");
	//p.waitForStarted();
	//p.waitForFinished();
	//QList<QString> user;
	//user << "/c" << "cd \ " << "/c" << "d:" << "/c" << "cd D:\mysql\mysql-8.0.19-winx64\mysql-8.0.19-winx64\bin" << "/c" << "mysqldump ceshicopy -u root -proot --add-drop-table | mysql newdb -u root -proot";
	//for (int i = 0; i< user.size(); ++i)
	//{
	//	QString tmp = user.at(i);
	//	qDebug() << "tmp =" << tmp;
	//}

	//qDebug() << QStringList();

	//QString strTemp = QString::fromLocal8Bit(p.readAllStandardOutput());

	//QMessageBox testMassage;
	//testMassage.setText(strTemp);
	//testMassage.exec();

	clipProcess = new QProcess(this);
	clipProcess->setProcessChannelMode(QProcess::MergedChannels);
	connect(clipProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(read_slot()));
	connect(clipProcess, SIGNAL(readyReadStandardError()), this, SLOT(read_error()));
	clipProcess->start("cmd.exe");
	if (!clipProcess->waitForStarted())
		qDebug() << "Make failed:" << clipProcess->errorString();
	else
	{
		qDebug() << "clipProcess： " << clipProcess->readAll();
	}

	//clipProcess->write("cd D:/mysql/mysql-8.0.19-winx64/mysql-8.0.19-winx64/bin/\r\n");
	
	file_full = QDir::toNativeSeparators(file_full);
	//QString name1 = "cd " + file_full + "\\r\\n";
	QString name1 = QString("cd %1").arg(file_full);
	//QString name1 = "cd " + file_full ;

	std::string str1 = name1.toStdString();
	const char *mvFileName1 = str1.c_str();

	//name1 = QDir::toNativeSeparators(name1);
	//const char*  ch1;
	//QByteArray ba1 = name1.toLatin1(); 
	//ch1 = ba1.data();

	clipProcess->write(mvFileName1);
	clipProcess->write("\r\n");
	clipProcess->waitForBytesWritten(1000);
	qDebug() << "name1 = " << name1;
	qDebug() << "ch1 = " << mvFileName1;
	qDebug() << "name1.toLatin1().data() = " << name1.toLatin1().data();

	Cmd = QDir::toNativeSeparators(Cmd);
	//QString name2 = Cmd+"\\r\\n";
	QString name2 = QString("%1").arg(Cmd);
	std::string str2 = name2.toStdString();
	const char *mvFileName2 = str2.c_str();

	
	//const char*  ch2;
	//QByteArray ba2 = name2.toLatin1();
	//ch2 = ba2.data();
	clipProcess->write(mvFileName2);
	clipProcess->write("\r\n");
	//clipProcess->write("mysqldump ceshicopy -u root -proot --add-drop-table | mysql newdb -u root -proot\r\n");
	clipProcess->waitForBytesWritten(1000);
	qDebug() << "name2 = " << name2;
	qDebug() << "ch2 = " << mvFileName2;

	if (judgeTrue == "mysql: [Warning] Using a password on the command line interface can be insecure.\r\n") {
		QMessageBox::about(this, "About", "\n成功复制数据库");
	}

	//将收到的回复显示出来
	QString strTemp = QString::fromLocal8Bit(clipProcess->readAllStandardOutput());
	QMessageBox testMassage;
	testMassage.setText(strTemp);
	testMassage.exec();
	


}
void QtWidgetsApplication1::read_slot()
{
	while (clipProcess->canReadLine())
	{
		char output[1024];
		int ret = clipProcess->readLine(output, 1023);
		qDebug() << "ret = "<<ret;
		qDebug() << "output = "<<output;

		QString tmpstr;
		tmpstr = output;
		qDebug() <<"tmpstr = "<< tmpstr;
		judgeTrue = output;
		qDebug() << "chenggong = " << judgeTrue;
	}
	qDebug() << "read slot";
}

