/*
 *  Created on: Mar 16, 2009
 *      Author: tpielech
 */

#include "ConvertAmount.h"
#include "Settings.h"

QString &ConvertAmount::descAmount(
	QString &countMoney,
	QString partMoney,
	QString ifOne,
	QString ifMore,
	QString ifBetween) const
{
	while (partMoney.length() < 3)
	{
		partMoney = QObject::trUtf8("0") + partMoney;
	}

	switch (partMoney.left(1).toInt())
	{
	case 1:
		countMoney += QObject::trUtf8(" ") + hundsList()[0];
		break;
	case 2:
		countMoney += QObject::trUtf8(" ") + hundsList()[1];
		break;
	case 3:
		countMoney += QObject::trUtf8(" ") + hundsList()[2];
		break;
	case 4:
		countMoney += QObject::trUtf8(" ") + hundsList()[3];
		break;
	case 5:
		countMoney += QObject::trUtf8(" ") + hundsList()[4];
		break;
	case 6:
		countMoney += QObject::trUtf8(" ") + hundsList()[5];
		break;
	case 7:
		countMoney += QObject::trUtf8(" ") + hundsList()[6];
		break;
	case 8:
		countMoney += QObject::trUtf8(" ") + hundsList()[7];
		break;
	case 9:
		countMoney += QObject::trUtf8(" ") + hundsList()[8];
		break;
	case 0:
		countMoney += QObject::trUtf8("");
		break;
	}

	if (partMoney.mid(1, 1).toInt() == 1)
	{
		switch (partMoney.right(1).toInt())
		{
		case 1:
			countMoney += QObject::trUtf8(" ") + endsTensList()[0];
			break;
		case 2:
			countMoney += QObject::trUtf8(" ") + endsTensList()[1];
			break;
		case 3:
			countMoney += QObject::trUtf8(" ") + endsTensList()[2];
			break;
		case 4:
			countMoney += QObject::trUtf8(" ") + endsTensList()[3];
			break;
		case 5:
			countMoney += QObject::trUtf8(" ") + endsTensList()[4];
			break;
		case 6:
			countMoney += QObject::trUtf8(" ") + endsTensList()[5];
			break;
		case 7:
			countMoney += QObject::trUtf8(" ") + endsTensList()[6];
			break;
		case 8:
			countMoney += QObject::trUtf8(" ") + endsTensList()[7];
			break;
		case 9:
			countMoney += QObject::trUtf8(" ") + endsTensList()[8];
			break;
		case 0:
			countMoney += QObject::trUtf8(" ") + endsTensList()[9];
			break;
		}
	}
	else
	{
		switch (partMoney.mid(1, 1).toInt())
		{
		case 2:
			countMoney += QObject::trUtf8(" ") + endsHundList()[0];
			break;
		case 3:
			countMoney += QObject::trUtf8(" ") + endsHundList()[1];
			break;
		case 4:
			countMoney += QObject::trUtf8(" ") + endsHundList()[2];
			break;
		case 5:
			countMoney += QObject::trUtf8(" ") + endsHundList()[3];
			break;
		case 6:
			countMoney += QObject::trUtf8(" ") + endsHundList()[4];
			break;
		case 7:
			countMoney += QObject::trUtf8(" ") + endsHundList()[5];
			break;
		case 8:
			countMoney += QObject::trUtf8(" ") + endsHundList()[6];
			break;
		case 9:
			countMoney += QObject::trUtf8(" ") + endsHundList()[7];
			break;
		case 0:
			countMoney += QObject::trUtf8("");
			break;
		}

		switch (partMoney.right(1).toInt())
		{
		case 1:
			countMoney += QObject::trUtf8(" ") + simpleNumbList()[0];
			break;
		case 2:
			countMoney += QObject::trUtf8(" ") + simpleNumbList()[1];
			break;
		case 3:
			countMoney += QObject::trUtf8(" ") + simpleNumbList()[2];
			break;
		case 4:
			countMoney += QObject::trUtf8(" ") + simpleNumbList()[3];
			break;
		case 5:
			countMoney += QObject::trUtf8(" ") + simpleNumbList()[4];
			break;
		case 6:
			countMoney += QObject::trUtf8(" ") + simpleNumbList()[5];
			break;
		case 7:
			countMoney += QObject::trUtf8(" ") + simpleNumbList()[6];
			break;
		case 8:
			countMoney += QObject::trUtf8(" ") + simpleNumbList()[7];
			break;
		case 9:
			countMoney += QObject::trUtf8(" ") + simpleNumbList()[8];
			break;
		case 0:
			countMoney += QObject::trUtf8("");
			break;
		}
	}

	if (!ifOne.isEmpty() && !ifOne.isNull())
	{
		if (partMoney.toInt() > 9)
		{
			countMoney += ifMore;
			qDebug() << "partMoney.toInt() > 9: " << partMoney.toInt();
		}
		else if ((partMoney.toInt() < 10) && (partMoney.toInt() > 0))
		{
			if ((partMoney.toInt() > 1) && (partMoney.toInt() < 5))
			{
				countMoney += ifBetween;
			}
			else if (partMoney.toInt() > 4)
			{
				countMoney += ifMore;
			}
			else
			{
				countMoney += ifOne;
			}
			qDebug() << "partMoney.toInt() >= 1: " << partMoney.toInt();
		}
	}

	return countMoney;
}

QStringList ConvertAmount::hundsList() const
{
	QStringList hundredsPL;
	hundredsPL << QObject::trUtf8("sto") << QObject::trUtf8("dwieście")
			   << QObject::trUtf8("trzysta") << QObject::trUtf8("czterysta")
			   << QObject::trUtf8("pięćset") << QObject::trUtf8("sześćset")
			   << QObject::trUtf8("siedemset") << QObject::trUtf8("osiemset")
			   << QObject::trUtf8("dziewięćset");

	return hundredsPL;
}

QStringList ConvertAmount::endsHundList() const
{
	QStringList hundEndsPL;
	hundEndsPL << QObject::trUtf8("dwadzieścia") << QObject::trUtf8("trzydzieści")
			   << QObject::trUtf8("czterdzieści") << QObject::trUtf8("pięćdziesiąt")
			   << QObject::trUtf8("sześdziesiąt") << QObject::trUtf8("siedemdziesiąt")
			   << QObject::trUtf8("osiemdziesiąt") << QObject::trUtf8("dziewięćdziesiąt");

	return hundEndsPL;
}

QStringList ConvertAmount::endsTensList() const
{
	QStringList tenEndsPL;
	tenEndsPL << QObject::trUtf8("jedenaście") << QObject::trUtf8("dwanaście")
			  << QObject::trUtf8("trzynaście") << QObject::trUtf8("czternaście")
			  << QObject::trUtf8("piętnaście") << QObject::trUtf8("szesnaście")
			  << QObject::trUtf8("siedemnaście") << QObject::trUtf8("osiemnaście")
			  << QObject::trUtf8("dziewiętnaście") << QObject::trUtf8("dziesięć");

	return tenEndsPL;
}

QStringList ConvertAmount::simpleNumbList() const
{
	QStringList nineNumbs;
	nineNumbs << QObject::trUtf8("jeden") << QObject::trUtf8("dwa") << QObject::trUtf8("trzy")
			  << QObject::trUtf8("cztery") << QObject::trUtf8("pięć") << QObject::trUtf8("sześć")
			  << QObject::trUtf8("siedem") << QObject::trUtf8("osiem")
			  << QObject::trUtf8("dziewięć");

	return nineNumbs;
}

QString ConvertAmount::convertPL(QString input, QString currency) const
{
	QString in = input.remove(sett().getTPointStr());
	qDebug() << "in: " << in;

	QString tmp = in.remove(in.indexOf(sett().getDecimalPointStr()), 3);
	qDebug() << "temp: " << tmp;

	QString hundreds = tmp.right(3);
	QString thousands = QString();
	QString millions = QString();
	QString billions = QString();

	switch (tmp.length())
	{
	case 4:

		thousands = tmp.left(1);
		millions = QObject::trUtf8("");
		billions = QObject::trUtf8("");
		break;

	case 5:

		thousands = tmp.left(2);
		millions = QObject::trUtf8("");
		billions = QObject::trUtf8("");
		break;

	case 6:

		thousands = tmp.left(3);
		millions = QObject::trUtf8("");
		billions = QObject::trUtf8("");
		break;

	case 7:

		millions = tmp.left(1);
		thousands = tmp.mid(1, 3);
		billions = QObject::trUtf8("");
		break;

	case 8:

		millions = tmp.left(2);
		thousands = tmp.mid(2, 3);
		billions = QObject::trUtf8("");
		break;

	case 9:

		millions = tmp.left(3);
		thousands = tmp.mid(3, 3);
		billions = QObject::trUtf8("");
		break;

	case 10:

		billions = tmp.left(1);
		millions = tmp.mid(1, 3);
		thousands = tmp.mid(4, 3);
		break;

	case 11:

		billions = tmp.left(2);
		millions = tmp.mid(2, 3);
		thousands = tmp.mid(5, 3);
		break;

	case 12:

		billions = tmp.left(3);
		millions = tmp.mid(3, 3);
		thousands = tmp.mid(6, 3);
		break;

	default:

		thousands = QObject::trUtf8("");
		millions = QObject::trUtf8("");
		billions = QObject::trUtf8("");
		break;
	}

	qDebug() << "billions' value: " << billions;
	qDebug() << "millions' value: " << millions;
	qDebug() << "thousands' value: " << thousands;

	QString out = QString();

	descAmount(
		out,
		billions,
		QObject::trUtf8(" miliard"),
		QObject::trUtf8(" miliardów"),
		QObject::trUtf8(" miliardy"));
	descAmount(
		out,
		millions,
		QObject::trUtf8(" milion"),
		QObject::trUtf8(" milionów"),
		QObject::trUtf8(" miliony"));
	descAmount(
		out,
		thousands,
		QObject::trUtf8(" tysiąc"),
		QObject::trUtf8(" tysięcy"),
		QObject::trUtf8(" tysiące"));
	descAmount(out, hundreds);

	in = input;
	QString change = in.remove(0, in.indexOf(sett().getDecimalPointStr()) + 1);

	return out + QObject::trUtf8(" ") + change + QObject::trUtf8("/100 ") + currency;
}
