#include "Logic.h"

#include <QtMath>
#include <QGuiApplication>
#include <QQmlEngine>
#include <iostream>
#include <QtDebug>

static void registerLogic()
{
	qmlRegisterType<Logic>("Logic", 1, 0, "Logic");
}

Q_COREAPP_STARTUP_FUNCTION(registerLogic);

Logic::Logic(QObject *parent) :
	QObject(parent)
{
	m_input = "0";

	numbers.push_back(QString("0"));
	numbers.push_back(QString("1"));
	numbers.push_back(QString("2"));
	numbers.push_back(QString("3"));
	numbers.push_back(QString("4"));
	numbers.push_back(QString("5"));
	numbers.push_back(QString("6"));
	numbers.push_back(QString("7"));
	numbers.push_back(QString("8"));
	numbers.push_back(QString("9"));

	operators.push_back(QString("/"));
	operators.push_back(QString("*"));
	operators.push_back(QString("+"));
	operators.push_back(QString("-"));
}

QString Logic::inputString()
{
	return m_input;
}

void Logic::memoryPlus() noexcept
{
	list.push_back("+");
	list.push_back(m_input);
	clear();
}

void Logic::memoryMinus() noexcept
{
	list.push_back("-");
	list.push_back(m_input);
	clear();
}

void Logic::memoryClear() noexcept
{
	list.clear();
}

void Logic::clear() noexcept
{
	m_input = "0";
	emit inputChanged();
}

void Logic::removeLast() noexcept
{
	if (m_input.length() > 0) {
		m_input = m_input.mid(0, m_input.size() - 1);
	}
	if (m_input.length() == 0) {
		m_input = "0";
	}
	emit inputChanged();
}

void Logic::calculate() noexcept
{
	qDebug() << m_input;
	qDebug() << listToString();
}

QString Logic::listToString() noexcept {
	QString string = "";
	for (const auto &item : list) {
		string += " | " + item;
	}
	return string;
}

void Logic::setInput(const QString &input) noexcept
{
	if (inArray(input, numbers)) {
		if (m_input == "0") {
			m_input = input;
		}
		else {
			m_input = m_input + input;
		}
	}
	else{
		QString lastSign = m_input.mid(m_input.size() - 1, m_input.size());
		if ((inArray(input, operators) && inArray(lastSign, numbers)) ||
			(input == "." && inArray(lastSign, numbers))) {
			m_input = m_input + input;
		}else if (inArray(input, operators) && inArray(lastSign, operators)) {
			m_input = m_input.mid(0, m_input.size() - 1) + input;
		}
	}
	if (m_input.length() > 20) {
		m_input = m_input.mid(0, 20);
	}

	//qDebug() << input;
	emit inputChanged();
}

bool Logic::inArray(const QString& value, const std::vector<QString>& array) noexcept
{
	return std::find(array.begin(), array.end(), value) != array.end();
}