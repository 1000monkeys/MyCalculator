#include "Logic.h"

#include <QGuiApplication>
#include <QQmlEngine>
#include <iostream>
#include <QtDebug>
#include <cmath>

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
	m_input = "";
	for (const auto& item : list) {
		m_input += item;
	}
	preCalculate();
	list.clear();
}

void Logic::pressedKey(QKeyEvent *event) noexcept
{
	m_input += event->text();
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

void Logic::preCalculate() noexcept
{
	qDebug() << m_input;
	qDebug() << listToString();

	std::string input = m_input.toStdString();
	QString result = "";
	while (
		input.find("*") != std::string::npos ||
		input.find("/") != std::string::npos ||
		input.find("+") != std::string::npos ||
		input.find("-") != std::string::npos
	) {
		if (input.find("*") != std::string::npos || input.find("/") != std::string::npos) {
			// * AND /
			if (input.find("/") < input.find("*")) {
				qDebug() << "eerst / dan *";

				QString inputQ = QString::fromStdString(input);
				inputQ = calculate(inputQ, '/');
				input = inputQ.toStdString();

				qDebug() << inputQ;
				result = inputQ;

			}
			else if (input.find("/") > input.find("*")) {
				qDebug() << "eerst * dan /";

				QString inputQ = QString::fromStdString(input);
				inputQ = calculate(inputQ, '*');
				input = inputQ.toStdString();

				qDebug() << inputQ;
				result = inputQ;
			}
		}
		else if (input.find("+") != std::string::npos || input.find("-") != std::string::npos) {
			// + AND -
			if (input.find("+") < input.find("-")) {
				qDebug() << "eerst + dan -";

				QString inputQ = QString::fromStdString(input);
				inputQ = calculate(inputQ, '+');
				input = inputQ.toStdString();

				qDebug() << inputQ;
				result = inputQ;
			}
			else if (input.find("-") < input.find("+")) {
				qDebug() << "eerst - dan +";

				QString inputQ = QString::fromStdString(input);
				inputQ = calculate(inputQ, '-');
				input = inputQ.toStdString();

				qDebug() << inputQ;
				result = inputQ;
			}
		}
	}

	m_input = result;
	emit inputChanged();
}

std::array<float, 4> Logic::getNumbers(QString inputQ, char op) noexcept
{
	std::string input = inputQ.toStdString();

	QString first_number = "";
	QString second_number = "";

	int count = 0;

	int startPos = input.find(op);
	startPos--;
	while (startPos > 0 && (isdigit(input[startPos]) || input[startPos] == '.')) {
		startPos--;
	}
	if (startPos < 0) {
		startPos = 0;
	}
	qDebug() << QString::fromStdString("Startpos: " + startPos);

	for (int i = startPos; i < input.find(op); i++) {
		first_number += input[i];
		count++;
	}

	count++;

	for (int i = input.find(op) + 1; isdigit(input[i]) || input[i] == '.'; i++) {
		second_number += input[i];
		count++;
	}

	qDebug() << QString::fromStdString("first ") + first_number;
	qDebug() << QString::fromStdString("second ") + second_number;
	qDebug() << QString::fromStdString("count " + std::to_string(count));

	std::array<float, 4> numbers = {first_number.toFloat(), second_number.toFloat(), static_cast<float>(startPos), static_cast<float>(count) };
	return numbers;
}

QString Logic::calculate(QString inputQ, char op) noexcept
{
	std::array<float, 4> numbers = getNumbers(inputQ, op);

	std::string input = inputQ.toStdString();
	std::string inputBuild = "";

	inputBuild += input.substr(0, numbers[2]);
	if (op == '-') {
		inputBuild += std::to_string(numbers[0] - numbers[1]);
	}
	else if (op == '+') {
		inputBuild += std::to_string(numbers[0] + numbers[1]);
	}
	else if (op == '/') {
		inputBuild += std::to_string(numbers[0] / numbers[1]);
	}
	else if (op == '*') {
		inputBuild += std::to_string(numbers[0] * numbers[1]);
	}
	inputBuild += input.substr(numbers[2] + numbers[3], input.length());

	QString result = QString::fromStdString(inputBuild);

	return result;
}

QString Logic::reverse(QString str) noexcept
{
	QString reverseStr = "";
	for (int i = str.length() - 1; i >= 0; i--) {
		reverseStr = reverseStr + str[i];
	}
	return reverseStr;
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