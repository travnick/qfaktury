#pragma once

#include "Invoice.h"
#include "Setting.h"
#include "owncalendar.h"
#include "ui_MainWindow.h"

#include <QKeyEvent>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	static void insertRow(QTableWidget *t, int row);
	void newInvoice(Invoice *invoice, QString windowTitle);
	int getMaxSymbol() const;
	// FIXME: remove this buggy instance() thing
	static MainWindow *instance();
	static bool shouldHidden;

public slots:
	void tableClear(QTableWidget *tab);
	void tabChanged();
	void rereadHist(bool if_clicked);
	void aboutQt();
	void aboutProg();
	void editFHist();
	void delFHist();
	void userDataClick();
	void settClick();
	void buyerClick();
	void buyerDel();
	void buyerEd();
	void newInv();
	void newInvRR();
	void newPForm();
	void newCor();
	void newDuplicate();
	void newInvGross();
	void newInvBill();
	bool close();
	void help();
	void openHideOrganizer();
	void noteDownTask(const QDate &);
	void reportBug();
	void goodsAdd();
	void goodsDel();
	void goodsEdit();
	void mainUpdateStatus(QTableWidgetItem *item);
	void showTableMenuT(QPoint p);
	void showTableMenuK(QPoint p);
	void showTableMenuH(QPoint p);
	void pluginSlot();
	void pluginInfoSlot();
	void keyPressEvent(QKeyEvent *event);
	void openWebTableK(int, int);
	void printBuyerList();
	void printList(QPrinter *);
	void cancelTaskWidget();
	void addTaskToList();
	void addNextTask();
	void delTasksFromDay();
	QString changeIfEmpty(QString text) const;
	void sendEmailToBuyer();

protected:
	virtual void loadPlugins();

private:
	IDataLayer *dl;
	Ui::MainWindow *ui;
	QWidget *windBack;
	QLineEdit *fileComboBox;
	QLineEdit *directoryComboBox;

	QVector<QAction *> plugActions;
	QString workingDir;
	QMap<int, QString> customActions;
	QTimer *timer;
	QList<int> allSymbols;
	QWidget *windowTask;
	QPushButton *cancelTaskBtn;
	QPushButton *addTaskBtn;
	QDate markedDate;
	ownCalendarWidget *calendar;
	static MainWindow *m_instance;

	void saveColumnWidth();
	void init();
	void saveAllSett();
	void saveAllSettAsDefault();
	void setupDir();
	void readHist();
	void readBuyer();
	void readGoods();
	void categorizeYears();
	void checkTodayTask(QString whatToDo = QString("append"));
	void createEmergTemplate();
	bool ifEmergTemplateExists();
	bool applyFiltr(QString);
	bool firstRun();
	bool ifpdfDirExists();
	void createPdfDir();
	void generatePdfFromList();

	void calendarNoteJustify(QString text)
	{
		ui->todayExercise->append(text);

		QTextCursor cursor = ui->todayExercise->textCursor();
		QTextBlockFormat textBlockFormat = cursor.blockFormat();
		textBlockFormat.setAlignment(Qt::AlignHCenter);
		cursor.mergeBlockFormat(textBlockFormat);
		ui->todayExercise->setTextCursor(cursor);
	}
};
