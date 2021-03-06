#include "detector.h"
#if _pragma_once_support
#pragma once
#endif
#ifndef SETTING_H
#define SETTING_H

#include "ui_setting.h"

#include "fwd.hpp"

// class for creating window with settings with GUI
class Setting final : public QDialog, public Ui::Setting
{
    Q_OBJECT

public:
    Setting(QWidget *parent);
    ~Setting();

public slots:

    void apply();
    void okButtonClick();
    void addLogoBtnClick();
    void addStempBtnClick();
    void addSignBtnClick();
    void currAddBtnClick();
    void currDelBtnClick();
    void corAddBtnClick();
    void corDelBtnClick();
    void vatAddBtnClick();
    void vatDelBtnClick();
    void vatUpBtnClick();
    void vatDownBtnClick();
    void currencyAddBtnClick();
    void currencyDelBtnClick();
    void paymUpBtnClick();
    void paymDownBtnClick();
    void paymDelBtnClick();
    void saveBtnEnable();
    void paymAddBtnClick();
    void defTextBtnClick();
    void setDefaultClick();
    void workingDirBtnClick();
    void checkCurrCsvFormat(bool);
    void blockCsvCheckboxPath(int);
    void blockBackupCheckboxPath(int);
    void blockBackupCheckbox(int);
    void checkOnlyOneInterval(bool);
    void fillPath(bool);

private:
    bool read;
    void init();
    void sumSize();
    void saveSettings();
    void readSettings();
    void getEncodings();
    void helpFuncAddNr(QLineEdit *, QListWidget *, QString const &);
    void helpFuncDelNr(QListWidget *, QString const &);
    void helpFuncAp(QListWidget *);
    void helpFuncDown(QListWidget *);
    QStringList getTemplates();
    QStringList getTranslations();
    QStringList getStyles();
    QString getAll(QListWidget *lb);
    QVector<QTextCodec *> codecs;

    inline QString settWriteBackup();

    inline void settReadBackup(QString settValue);

    inline void uncheckRadio(QRadioButton *btn);
};
#endif
