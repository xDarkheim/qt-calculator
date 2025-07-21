#include "Calculator.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QApplication>


Calculator::Calculator(QWidget *parent) : QWidget(parent)
{
    setupUI(); // Set up the user interface
    connectSignals(); // Connect signals and slots
    setWindowTitle("Calculator"); // Set the window title
    resize(300, 400); // Resize the window to a reasonable size
}

void Calculator::setupUI()
{
    auto *mainLayout = new QVBoxLayout(this);

    // Display setup
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setStyleSheet("font-size: 18px; padding: 10px;");
    mainLayout->addWidget(display);

    // Button grid
    auto *gridLayout = new QGridLayout();

    // Clear button
    clearBtn = new QPushButton("C");
    gridLayout->addWidget(clearBtn, 0, 0, 1, 4);

    // Number buttons
    for (int i = 1; i <= 9; ++i)
    {
        auto *btn = new QPushButton(QString::number(i));
        int row = 3 - (i - 1) / 3;
        int col = (i - 1) % 3;
        gridLayout->addWidget(btn, row, col);
        connect(btn, &QPushButton::clicked, this, &Calculator::digitClicked);
    }

                    // Zero button
                    auto *zeroBtn = new QPushButton("0");
                    gridLayout->addWidget(zeroBtn, 4, 0, 1, 2);
                    connect(zeroBtn, &QPushButton::clicked, this, &Calculator::digitClicked);

                    // Decimal point button
                    auto *dotBtn = new QPushButton(".");
                    gridLayout->addWidget(dotBtn, 4, 2);
                    connect(dotBtn, &QPushButton::clicked, this, &Calculator::digitClicked);

                    // Operator buttons
                    auto *addBtn = new QPushButton("+");
                    auto *subBtn = new QPushButton("-");
                    auto *mulBtn = new QPushButton("*");
                    auto *divBtn = new QPushButton("/");
                    equalBtn = new QPushButton("=");

                    gridLayout->addWidget(divBtn, 1, 3);
                    gridLayout->addWidget(mulBtn, 2, 3);
                    gridLayout->addWidget(subBtn, 3, 3);
                    gridLayout->addWidget(addBtn, 4, 3);
                    gridLayout->addWidget(equalBtn, 5, 0, 1, 4);

                    mainLayout->addLayout(gridLayout);

                    // Store buttons for connections
                    operatorButtons = {addBtn, subBtn, mulBtn, divBtn};
    }

    void Calculator::connectSignals()
    {
    for (auto *btn : operatorButtons)
    {
        connect(btn, &QPushButton::clicked, this, &Calculator::operatorClicked);
    }

    connect(clearBtn, &QPushButton::clicked, this, &Calculator::clearDisplay);
    connect(equalBtn, &QPushButton::clicked, this, &Calculator::calculateResult);
    }

    void Calculator::digitClicked()
    {
    const auto *button = qobject_cast<QPushButton *>(sender());
    const QString digit = button->text();

    if (waitingForOperand) {
        display->clear();
        waitingForOperand = false;
    }

    if (display->text() == "0" && digit != ".") {
        display->clear();
    }

    display->setText(display->text() + digit);
    }

    void Calculator::operatorClicked()
    {
    auto *button = qobject_cast<QPushButton *>(sender());
    const QString op = button->text();

    if (!waitingForOperand && !operation.isEmpty()) {
        calculateResult();
    }

    firstNumber = display->text().toDouble();
    operation = op;
    waitingForOperand = true;
    }

    void Calculator::calculateResult()
    {
    if (waitingForOperand || operation.isEmpty()) {
        return; // No operation to perform
    }

    double secondNumber = display->text().toDouble();
    double result = 0.0;

    if (operation == "+")
        result = firstNumber + secondNumber;
    else if (operation == "-")
        result = firstNumber - secondNumber;
    else if (operation == "*")
        result = firstNumber * secondNumber;
    else if (operation == "/")
    {
        if (secondNumber != 0)
            result = firstNumber / secondNumber;
        else
        {
            display->setText("Error");
            clearDisplay();
            return;
        }
    }

    display->setText(QString::number(result));
    operation.clear();
    waitingForOperand = true;
    }

    void Calculator::clearDisplay()
    {
    display->setText("0");
    firstNumber = 0.0;
    operation.clear();
    waitingForOperand = true;
    }

