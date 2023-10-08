#include <QApplication>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QString>

class MainWindow : public QWidget {
public:
    MainWindow() {
        countLineEdit = new QLineEdit(this);
        countLineEdit->setReadOnly(true);

        QPushButton* countButton = new QPushButton("Count", this);
        QPushButton* resetButton = new QPushButton("Reset", this);

        connect(countButton, &QPushButton::clicked, this, &MainWindow::incrementCount);
        connect(resetButton, &QPushButton::clicked, this, &MainWindow::resetCount);

        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(countLineEdit);
        layout->addWidget(countButton);
        layout->addWidget(resetButton);

        setLayout(layout);
    }

private slots:
    void incrementCount() {
        count++;
        countLineEdit->setText(QString::number(count));
    }

    void resetCount() {
        count = 0;
        countLineEdit->setText(QString::number(count));
    }

private:
    int count{0};
    QLineEdit* countLineEdit;
};


int main(int argc, char *argv[])
{


    QApplication app(argc, argv);

    MainWindow w;
    w.show();

    return app.exec();

}
