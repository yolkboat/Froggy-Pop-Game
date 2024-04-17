#include "Balloon.hpp"

Balloon::Balloon(const Balloon& copy)
{
    this->type = copy.type;
    this->color = copy.color;
    this->speed = copy.speed;
    this->direct = copy.direct;
    this->reachedEnd = copy.reachedEnd;
    this->setPosition(copy.getPosition());
}

int Balloon::getType() const
{
    return type;
}

void Balloon::setType(int type)
{
    this->type = type;
}

bool Balloon::getReachedEnd() const
{
    return reachedEnd;
}

void Balloon::setReachedEnd(bool reachedEnd)
{
    this->reachedEnd = reachedEnd;
}

void Balloon::moveBalloon(const vector<Checkpoint>& checkpoints, int& lives)
{
    for (int i = 0; i < checkpoints.size(); ++i)
    {
        if (getGlobalBounds().intersects(checkpoints[i].getGlobalBounds()))
        {
            direct = checkpoints[i].getDirection();
        }
    }

    if (!reachedEnd && getPosition().y > 525)
    {
        reachedEnd = true;
        lives -= type;
        cout << lives << endl;
    }

    if (direct == UP)
    {
        this->move(0, speed * -1);
    }
    else if (direct == RIGHT)
    {
        this->move(speed, 0);
    }
    else if (direct == DOWN)
    {
        this->move(0, speed);
    }
    else if (direct == LEFT)
    {
        this->move(speed * -1, 0);
    }
}

void bloonWave(BloonWave& wave)
{
}

void spawnBalloon(int type, vector<Balloon*>& bloons)
{
    Balloon* temp = new Balloon(type, 15, Vector2f(-30, 210));

    bloons.push_back(temp);
}
