#pragma once

#include "ui_User.h"

class User : public QDialog, public Ui::User
{
	Q_OBJECT

public:
	User(QWidget *parent);

public slots:

	void init();
	void okClick();
	bool checkAll();

private slots:
	void on_nextSeller_clicked();
	void delcurrSel();

private:
	QList<QWidget *> sellersWidgets;
};
