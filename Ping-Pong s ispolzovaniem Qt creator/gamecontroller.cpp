#include "gamecontroller.h"

GameController::GameController()
{
    m_speed = 9999999999;   //задаём начальную скорость
}

void GameController::move(Paddle *computer)
{
    qreal dy = -(rand() % 2); //генерация случайного направления движения ракетки

    computer->setPos(computer->x(), computer->y() + (GameController::m_speed * dy));
}                                                   //если dy = 0, ракетка не движется
                                                    // если dy = 1, ракетка движется вверх со скоростью m_speed
