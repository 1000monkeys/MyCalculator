#ifndef _logic_h_
#define _logic_h_

#include <QObject>
#include <qjsvalue.h>
#include <QKeyEvent>

class Logic : public QObject
{
	Q_OBJECT
    Q_PROPERTY(QString inputString READ inputString WRITE setInput NOTIFY inputChanged)


public:
    explicit Logic(QObject* parent = nullptr);

    QString inputString();
    Q_INVOKABLE void setInput(const QString &input) noexcept;
    Q_INVOKABLE void pressedKey(QKeyEvent* event) noexcept;

    Q_INVOKABLE void memoryPlus() noexcept;
    Q_INVOKABLE void memoryMinus() noexcept;
    Q_INVOKABLE void memoryClear() noexcept;

    Q_INVOKABLE void clear() noexcept;
    Q_INVOKABLE void removeLast() noexcept;
    Q_INVOKABLE void preCalculate() noexcept;

    bool inArray(const QString& value, const std::vector<QString>& array) noexcept;
    QString listToString() noexcept;

    QString reverse(QString str) noexcept;
    std::array<float, 4> getNumbers(QString input, char op) noexcept;
    QString calculate(QString input, char op) noexcept;

signals:
    void inputChanged();

private:
    QString m_input;

    std::vector<QString> numbers;
    std::vector<QString> operators;
    
    QString inputMemory;
    std::list<QString> list;
};

#endif