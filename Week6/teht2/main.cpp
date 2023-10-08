#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

class LaskinApp : public QWidget {
public:
    LaskinApp() {
        num1Label = new QLabel("", this);
        num2Label = new QLabel("", this);
        resultLabel = new QLabel("", this);

        createNumberButtons();
        createOperationButtons();

        // Clear ja Enetr -napit
        QPushButton* clearButton = new QPushButton("Clear", this);
        QPushButton* enterButton = new QPushButton("Enter", this);

        connect(clearButton, &QPushButton::clicked, this, &LaskinApp::clear);
        connect(enterButton, &QPushButton::clicked, this, &LaskinApp::calculate);

        // layoutti
        QGridLayout* layout = new QGridLayout;

        int row = 1, col = 0;
        for (int i = 1; i <= 9; ++i) {
            layout->addWidget(numButtons[i], row, col);
            ++col;
            if (col > 2) {
                col = 0;
                ++row;
            }
        }

        layout->addWidget(numButtons[0], 4, 0);
        layout->addWidget(addButton, 4, 1);
        layout->addWidget(subButton, 4, 2);
        layout->addWidget(mulButton, 5, 0);
        layout->addWidget(divButton, 5, 1);
        layout->addWidget(clearButton, 5, 2);
        layout->addWidget(enterButton, 6, 0, 1, 3);

        layout->addWidget(num1Label, 0, 0);
        layout->addWidget(num2Label, 0, 1);
        layout->addWidget(resultLabel, 0, 2);

        setLayout(layout);
    }

private slots:
    void clear() {
        num1 = "";
        num2 = "";
        result = "";
        updateLabels();
    }

    void calculate() {
        bool ok1, ok2;
        double parsedNum1 = num1.toDouble(&ok1);
        double parsedNum2 = num2.toDouble(&ok2);

        if (ok1 && ok2) {
            if (sender() == addButton)
                result = QString::number(parsedNum1 + parsedNum2);
            else if (sender() == subButton)
                result = QString::number(parsedNum1 - parsedNum2);
            else if (sender() == mulButton)
                result = QString::number(parsedNum1 * parsedNum2);
            else if (sender() == divButton) {
                if (parsedNum2 != 0)
                    result = QString::number(parsedNum1 / parsedNum2);
                else
                    result = "Ei nollalla jakoa!";
            }
        } else {
            result = "Virhe inputissa";
        }

        updateLabels();
    }

    void appendToCurrentLineEdit() {
        QPushButton* button = qobject_cast<QPushButton*>(sender());
        if (button) {
            if (result.isEmpty()) {
                if (num1.isEmpty())
                    num1 = button->text();
                else
                    num2 = button->text();
            }
            updateLabels();
        }
    }

    void updateLabels() {
        num1Label->setText("Numero 1: " + num1);
        num2Label->setText("Numero 2: " + num2);
        resultLabel->setText("Tulos: " + result);
    }

private:
    QString num1;
    QString num2;
    QString result;
    QPushButton* numButtons[10];
    QPushButton* addButton;
    QPushButton* subButton;
    QPushButton* mulButton;
    QPushButton* divButton;
    QLabel* num1Label;
    QLabel* num2Label;
    QLabel* resultLabel;

    void createNumberButtons() {
        for (int i = 0; i <= 9; ++i) {
            numButtons[i] = new QPushButton(QString::number(i), this);
            connect(numButtons[i], &QPushButton::clicked, this, &LaskinApp::appendToCurrentLineEdit);
        }
    }

    void createOperationButtons() {
        addButton = new QPushButton("+", this);
        subButton = new QPushButton("-", this);
        mulButton = new QPushButton("*", this);
        divButton = new QPushButton("/", this);

        connect(addButton, &QPushButton::clicked, this, &LaskinApp::calculate);
        connect(subButton, &QPushButton::clicked, this, &LaskinApp::calculate);
        connect(mulButton, &QPushButton::clicked, this, &LaskinApp::calculate);
        connect(divButton, &QPushButton::clicked, this, &LaskinApp::calculate);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    LaskinApp laskin;
    laskin.setWindowTitle("Laskimen otsikko testi!");
    laskin.show();

    return app.exec();
}
