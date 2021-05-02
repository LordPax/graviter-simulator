#ifndef PLANETS_HPP
#define PLANETS_HPP

#include "graviter.hpp"

class Planets {
    private :
        float x;
        float y; // coordonnée x, y
        float vx;
        float vy; // vitesse vx, vy
        float r; // rayon de la planete
        float masse; // masse de la planete
        float distCrit; // distance critique de collision
        float dirx, diry; // direction en x, y
        float angle;
        bool exist;

    public:
        Planets(int masse);

};

#endif