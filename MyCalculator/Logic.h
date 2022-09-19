#pragma once
#include <QObject>

class Logic : public QObject
{
	Q_OBJECT
	Logic(QObject* const qParent) noexcept;
};