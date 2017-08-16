#pragma once

/*
 *  Created on: Apr 4, 2009
 *      Author: moux
 */

#include "CustomPaymData.h"
#include "ui_CustomPaymentDialog.h"

class CustomPayment : public QDialog, public Ui::CustomPaymentDialog
{
	Q_OBJECT

public:
	CustomPayment(QWidget *parent);
	virtual ~CustomPayment();

	bool validateForm();
	void setInvoiceAmount(double a);
	void init();

	CustomPaymData *custPaymData;

public slots:
	void okClicked();
	void amount1Changed(double a);
	void amount2Changed(double a);

private:
	double invoiceAmount;
};
