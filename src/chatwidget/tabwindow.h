#ifndef TABWINDOW_H
#define TABWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QString>
#include <QMap>
#include <QTimer>
#include <QVariant>

#include "core/talkable.h"

namespace Ui
{
	class TabWindow;
};

class Talkable;
class QQChatDlg;

class TabWindow : public QMainWindow
{
	Q_OBJECT
signals:
	void activatedPageChanged(QQChatDlg *before, QQChatDlg *after);

public:
	TabWindow();
	~TabWindow();

public:
	void addTab(QQChatDlg *page, const QString &label);
	void removeTab(QWidget *page);

	int indexOf(QWidget *page) const;
	QWidget *widget(int index) const;
	int pageCount() const;
	void activatedTab(QString id);

	void blink(QQChatDlg *dlg);
	void stopBlink(QQChatDlg *dlg);

private slots:
	void closeTab(int index);
	void onPageClosting(QQChatDlg *page);
	void onTalkableDataChanged(QVariant data, TalkableDataRole role);
	void onCurrentTabChanged(int index);
	void onBlinkTimeout();

private:
	Ui::TabWindow *ui;
	QTimer blink_timer_;
	QList<QQChatDlg *> blinking_dlg_;

	int current_index_;
	QMap<QString, QQChatDlg *> pages_;
};

#endif //TABWINDOW_H
