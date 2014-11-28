#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QtNetwork>
#include <QList>
#include <QVariant>
#include <QIODevice>
#include <QFileDialog>
#include <QJsonObject>

#include "cookieread.h"
#include "usermanager.h"
#include "livedata.h"
#include "strabstractor.h"
#include "NicoLiveManager/nicolivemanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	void onReceiveStarted();
	void onReceiveEnded();

	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
  void insComment(int num, bool prem, QString user, QString comm, QString date, bool is_184, bool broadcaster, bool after_open);
  void insLog(QString log = "");

	QString getUserSession();

	void setWatchCount(QString num);
	void setHousouID(QString text);
	void refleshLiveWaku();

	bool isNextWaku();

	UserManager* userManager;

  // command setting
  bool isCommandCommentChecked();
  QString getCommandComment();
  bool isCommandNextWakuChecked();
  QString getCommandNextWaku();

  QString getCookieName();

public slots:
	// ui slots
	void on_receive_clicked();
	void on_disconnect_clicked();

	void getWatchCount();

	void on_cookiesetting_file_open_button_clicked();
	void on_cookiesetting_apply_clicked();
	void on_cookiesetting_browserCombo_currentIndexChanged(int index);

	void on_clear_clicked();

	void on_actionSave_triggered();
	void on_actionLoad_triggered();

private slots:
	void on_commentView_itemDoubleClicked(QTreeWidgetItem *item, int column);
	void on_cookiesetting_usersession_textChanged();
	void on_commentView_currentItemChanged(QTreeWidgetItem *current);
	void on_live_waku_list_activated(int index);
	void on_user_data_OK_clicked();
	void updateElapsedTime();

private:
	void getComment();
	void getSessionFromCookie();

	void bodyClear();

	Ui::MainWindow* ui;
	QByteArray m_data;

	NicoLiveManager* nicolivemanager;

	QTimer* watch_count_timer;
	QTimer* elapsed_time_timer;

};

#endif // MAINWINDOW_H
