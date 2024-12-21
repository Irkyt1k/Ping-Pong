#include "mainwindow.h"
#include "config.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QMessageBox *msgBox = new QMessageBox(&w);
    msgBox->setWindowTitle("Как играть?");                  //настройка окна подсказки
    msgBox->setText("Используйте клавиши со стрелками ВВЕРХ и ВНИЗ для перемещения ракетки, чтобы попасть по мячу");
    msgBox->setInformativeText("Вы выигрываете, когда мяч проходит мимо ракетки противника");
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setModal(true);
    w.setFixedSize(BOARD_WIDTH, BOARD_HEIGHT);
    w.show();

    return a.exec();
}
