#include "ball.h"
#include "config.h"

#include <QBrush>
#include <QTimer>
#include <QList>

Ball::Ball()
{
    setRect(0, 0, m_width, m_height);
    setBrush((QBrush)Qt::black);
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
    dx = -1;
    dy = -1;
    m_speed = 15;
}

void Ball::setPaddles(Paddle *player, Paddle *computer)
{
    m_player = player;
    m_computer = computer;
}

bool Ball::insideBoard()
{
    return true;
}

int Ball::width()
{
    return m_width;
}

int Ball::height()
{
    return m_height;
}

int Ball::speed()
{
    return m_speed;
}

void Ball::move()
{

    if(collidesWithItem(m_computer) || collidesWithItem(m_player)){
        dx = -dx;
        dy = -(rand() % 2) + 1;
    }
    else if(y()>BOARD_HEIGHT - PADDLE_HEIGHT) {
        dy = -dy;
    }
    else {
    }
    setPos(x() + (m_speed * dx), y() + (m_speed * dy));
    m_computer->randomMove(y());
}
