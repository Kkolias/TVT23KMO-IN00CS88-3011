#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QMessageBox>
#include <QTimer>
#include <iostream>

class ShakkiKello : public QWidget {
public:
    ShakkiKello(QWidget *parent = nullptr) : QWidget(parent), player1Time(0), player2Time(0), currentPlayer(0) {
        QGridLayout *layout = new QGridLayout(this);

        QPushButton *btn120Sec = new QPushButton("120 sekuntia", this);
        QPushButton *btn600Sec = new QPushButton("5 min", this);
        QPushButton *btnStartGame = new QPushButton("START GAME", this);
         QPushButton *btnStopGame = new QPushButton("STOP GAME", this);
        btnPlayer1 = new QPushButton("Switch player", this);
        btnPlayer2 = new QPushButton("Switch player", this);

        progressBar1 = new QProgressBar(this);
        progressBar2 = new QProgressBar(this);

        // layoutti
        layout->addWidget(btn120Sec, 2,0);
        layout->addWidget(btn600Sec, 2, 1);
        layout->addWidget(btnPlayer1, 1, 0);
        layout->addWidget(btnPlayer2, 1, 1);
        layout->addWidget(btnStartGame, 3,0);
         layout->addWidget(btnStopGame, 3, 1);
        layout->addWidget(progressBar1, 0, 0);
        layout->addWidget(progressBar2, 0, 1);

        connect(btn120Sec, &QPushButton::clicked, this, &ShakkiKello::setPlayerTime120);
        connect(btn600Sec, &QPushButton::clicked, this, &ShakkiKello::setPlayerTime300);
        connect(btnStartGame, &QPushButton::clicked, this, &ShakkiKello::startGame);
         connect(btnStopGame, &QPushButton::clicked, this, &ShakkiKello::stopGame);
        connect(btnPlayer1, &QPushButton::clicked, this, &ShakkiKello::switchToPlayer1);
        connect(btnPlayer2, &QPushButton::clicked, this, &ShakkiKello::switchToPlayer2);

        progressBar1->setRange(0, 100);
        progressBar2->setRange(0, 100);
    }

private slots:
    void setPlayerTime120() {
        player1Time = player2Time = 120;
        player1InitialTime = 120;
        player2InitialTime = 120;
        progressBar1->setValue(100);
        progressBar2->setValue(100);
    }

    void setPlayerTime300() {
        player1Time = player2Time = 300;
        player1InitialTime = 300;
        player2InitialTime = 300;
        progressBar1->setValue(100);
        progressBar2->setValue(100);
    }

    void startGame() {
        if (player1Time == 0 || player2Time == 0) {
            QMessageBox::information(this, "Virhe", "Valitse ensin peliaika.");
            return;
        }

        currentPlayer = 1;
        progressBar1->setValue(100);
        progressBar2->setValue(100);

        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &ShakkiKello::updateTime);
        timer->start(1000);
    }

    void updateTime() {
        if (currentPlayer == 1 && player1Time > 0) {
            player1Time--;
            progressBar1->setValue((player1Time * 100) / player1InitialTime);

            if (player1Time == 0) {
                timer->stop();
                QMessageBox::information(this, "Voittaja", "Pelaaja 2 voittaa!");
            }
        } else if (currentPlayer == 2 && player2Time > 0) {
            player2Time--;
            progressBar2->setValue((player2Time * 100) / player2InitialTime);

            if (player2Time == 0) {
                timer->stop();
                QMessageBox::information(this, "Voittaja", "Pelaaja 1 voittaa!");
            }
        }
    }

    void stopGame() {
            timer->stop();
            player1Time = player2Time = 0;
            progressBar1->setValue(0);
            progressBar2->setValue(0);
    }

    void switchToPlayer1() {
        currentPlayer = 1;
    }

    void switchToPlayer2() {
        currentPlayer = 2;
    }

private:
    int player1Time;
    int player2Time;
    int player1InitialTime;
    int player2InitialTime;
    int currentPlayer;
    QPushButton *btnPlayer1;
    QPushButton *btnPlayer2;
    QProgressBar *progressBar1;
    QProgressBar *progressBar2;
    QTimer *timer;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ShakkiKello c;
    c.show();

    return app.exec();
}
