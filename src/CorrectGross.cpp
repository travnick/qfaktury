/*
 *  Created on: Apr 3, 2009
 *      Author: moux
 */

#include "CorrectGross.h"
#include "GoodsGrossList.h"
#include "MainWindow.h"

/* Constructor
 */

CorrectGross::CorrectGross(QWidget *parent, IDataLayer *dl, QString in_form, bool edMode)
	: Correction(parent, dl, in_form, edMode)
{
}

QString CorrectGross::getInvoiceTypeAndSaveNr()
{
	sett().setValue("korNr", invNr->text());
	return "kbrutto";
}

/** Caclulate Discount
 */

void CorrectGross::calculateOneDiscount(int i)
{
	// qDebug() << __FUNCTION__ << __LINE__ << __FILE__;
	double discount = 0;

	double price = sett().stringToDouble(tableGoods->item(i, 7)->text());

	if (constRab->isChecked())
	{
		discount = discountVal->value() * 0.01;
	}
	else
	{
		discount = (tableGoods->item(i, 6)->text()).toInt() * 0.01;
	}

	double quantity = sett().stringToDouble(tableGoods->item(i, 4)->text());
	price = price * quantity;
	double discountValue = price * discount;

	double gross = price - discountValue;
	auto vatValue = sett().stringToDouble(tableGoods->item(i, 9)->text());
	double vat = (gross * vatValue) / (100 + vatValue);

	double net = gross - vat;

	// qDebug() << price << quantity << net << discount << discountValue << vat << gross;

	tableGoods->item(i, 6)->setText(sett().numberToString(discount * 100, 'f', 0)); // discount
	tableGoods->item(i, 8)->setText(sett().numberToString(net)); // net
	tableGoods->item(i, 10)->setText(sett().numberToString(gross)); // gross
}

/** Slot
 *  Add new towar
 */

void CorrectGross::addGoods()
{
	GoodsGrossList goodsWindow(this);

	if (goodsWindow.exec() == QDialog::Accepted)
	{
		MainWindow::insertRow(tableGoods, tableGoods->rowCount());
		QStringList row = goodsWindow.getRetVal().split("|");
		int rowNum = tableGoods->rowCount() - 1;

		tableGoods->item(rowNum, 0)->setText(sett().numberToString(tableGoods->rowCount())); // id

		int i = 0;

		while (i < tableGoods->columnCount())
		{
			tableGoods->item(rowNum, i + 1)->setText(row[i]);
			i++;
		}

		canClose = false;

		if (constRab->isChecked())
		{
			calculateDiscount();
		}

		calculateSum();
	}
}
