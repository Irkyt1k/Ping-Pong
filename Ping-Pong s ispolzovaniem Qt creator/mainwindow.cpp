#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paddle.h"
#include "ball.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);       //Указывает габариты площадки(из config.h)
    scene->setSceneRect(0, 0, width(), height());

    Paddle *player = new Paddle();                          //Создание и настройка ракетки игрока
    player->setPos(5, (height() / 2.0) - player->height());
    player->setBrush(Qt::blue);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    Paddle *computer = new Paddle();                        //Создание и настройка ракетки компьютера
    computer->setPos(width() - computer->width() - 5, (height() / 2) - computer->height());

    Ball *ball = new Ball();                                //Создание мячика
    ball->setPaddles(player, computer);                     //Связь мячика и ракеток
    ball->setPos(player->x() + ball->width() + 12, player->y() + player->height() / 2);    //Начальное положение мячика

    scene->addItem(player);         //Добавление ракетки игрока на игровую площадку
    scene->addItem(computer);       //Добавление ракетки компьютера на игровую площадку
    scene->addItem(ball);           //Добавление мячика на игровую площадку


    ui->gameView->setScene(scene);
    ui->gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gameView->setGeometry(0, 0, width(), height());
    ui->gameView->setFixedSize(width(), height());
}

MainWindow::~MainWindow()
{
    delete ui;              //Освобождение памяти
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "Об игре", "Игра была разработана для КР по программированию", "OK");
}

void MainWindow::on_actionHow_to_play_triggered()
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setWindowTitle("Как играть?");
    msgBox->setText("Используйте клавиши со стрелками ВВЕРХ и ВНИЗ для перемещения ракетки, чтобы попасть по мячу");
    msgBox->setInformativeText("Вы выигрываете, когда мяч проходит мимо ракетки противника");
    msgBox->exec();
}
