#include "../libs/graviter.hpp"

Planets::Planets(int masse) {
    this->x = rand() % W;
    this->y = rand() % H;
    this->vx = 0;
    this->vy = 0;
    this->dirx = 0;
    this->diry = 0;
    this->masse = rand() % masse;
    this->r = sqrt(this->masse);
    this->distCrit = this->r * sqrt(2);
    this->exist = true;
}