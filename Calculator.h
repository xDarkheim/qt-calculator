#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QList>


class Calculator final : public QWidget{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator() override = default;

    Calculator(const Calculator &) = delete;
    Calculator &operator=(const Calculator &) = delete;
    Calculator(Calculator &&) = delete;
    Calculator &operator=(Calculator &&) = delete;

private slots:
    void digitClicked();
    void operatorClicked();
    void calculateResult();
    void clearDisplay();

private:
    void setupUI();
    void connectSignals();

    QLineEdit *display;
    QPushButton *clearBtn;
    QPushButton *equalBtn;
    QList<QPushButton *> operatorButtons;

    double firstNumber = 0.0;
    QString operation;
    bool waitingForOperand = true;
};



#endif //CALCULATOR_H
