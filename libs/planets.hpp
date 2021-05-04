#ifndef PLANETS_HPP
#define PLANETS_HPP

#include "graviter.hpp"

class Planets {
    private :
        Point coord;
        Point velocity;
        float r; // rayon de la planete
        float mass; // masse de la planete
        float distCrit; // distance critique de collision
        Point dir; // direction en x, y
        float angle;
        bool exist;
        sf::RenderWindow *win;
        sf::CircleShape circle;

    public:
        Planets(sf::RenderWindow *win, int masse);
        void draw();
        bool isExist();
        void setExist(bool exist);
        void graviter(Planets *p);

        // bool operator==(const Planets &p1, const Planets &p2);
        // bool operator!=(const Planets &p1, const Planets &p2);

        Point getCoord();
        void setCoord(float x, float y);

        Point getVelocity();
        void setVelocity(float x, float y);

        float getRadius();
        void setRadius(float r);

        float getMass();
};

#endif