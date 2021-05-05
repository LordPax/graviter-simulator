#include "../libs/graviter.hpp"

Planets::Planets(sf::RenderWindow *win, int masse) {
    this->coord.x = rand() % W;
    this->coord.y = rand() % H;
    this->velocity.x = 0;
    this->velocity.y = 0;
    this->dir.x = 0;
    this->dir.y = 0;
    this->mass = rand() % masse;
    this->r = sqrt(this->mass);
    this->distCrit = this->r * sqrt(2);
    this->exist = true;
    this->win = win;

    // sf::Font font;
    // font.loadFromFile("font/source_sans_pro_400.ttf");

    // this->info.setFont(font);
    // this->info.setCharacterSize(20);
}

void Planets::graviter(Planets *p) {
    Point coord = this->coord;
    Point pCoord = p->getCoord();
    Point velo = this->velocity;
    Point pVelo = p->getVelocity();
    float mass = this->mass;
    float pMass = p->getMass();
    float radius = this->r;
    float pRadius = p->getRadius();

    int dx = coord.x - pCoord.x;
    int dy = coord.y - pCoord.y;
    int dist = dx * dx + dy * dy;
    int dt = 1;

    if (dist != 0) {
        dist = sqrt(dist);
        if (dist < (radius + pRadius)) {
            if (pMass < mass) {
                this->mass += pMass;
                this->coord.x = (coord.x * mass + pCoord.x * pMass) / (mass + pMass);
                this->coord.y = (coord.y * mass + pCoord.y * pMass) / (mass + pMass);
                this->velocity.x = (mass * velo.x + pMass + pVelo.x) / (mass + pMass) * dt;
                this->velocity.y = (mass * velo.y + pMass + pVelo.y) / (mass + pMass) * dt;

                p->setExist(false);
                this->r = sqrt(mass);
            }
        }
        else {
            float force = pMass / dist;
            float angle = atan2(pCoord.y - coord.y, pCoord.x - coord.x);
            float dirx = force * cos(angle);
            float diry = force * sin(angle);

            this->dir.x = dirx;
            this->dir.y = diry;
            this->angle = angle;

            this->velocity.x += dirx;
            this->velocity.y += diry;
        }
    }
}

// bool operator==(const Planets &p1, const Planets &p2) {
//     return true; // TODO faire opérateur ==
// }

// bool operator!=(const Planets &p1, const Planets &p2) {
//     return true; // TODO faire opérateur !=
// }

void Planets::draw() {
    this->circle.setRadius(this->r);
    this->circle.setFillColor(sf::Color::Black);
    this->circle.setPosition(this->coord.x, this->coord.y);
    this->win->draw(circle);
}

void Planets::drawInfo() {
    sf::Font font;
    font.loadFromFile("font/source_sans_pro_400.ttf");

    sf::Text info("test", font, 10);
    info.setFillColor(sf::Color::Black);
    info.setPosition(this->coord.x + this->r + 10, this->coord.y);
    this->win->draw(info);
}

bool Planets::isExist() { return this->exist; }
void Planets::setExist(bool exist) { this->exist = exist; }

Point Planets::getCoord() { return this->coord; }
void Planets::setCoord(float x, float y){
    this->coord.x = x;
    this->coord.y = y;
}

Point Planets::getVelocity() { return this->velocity; }
void Planets::setVelocity(float x, float y){
    this->velocity.x = x;
    this->velocity.y = y;
}

float Planets::getMass() { return this->mass; }
float Planets::getRadius() { return this->r; }