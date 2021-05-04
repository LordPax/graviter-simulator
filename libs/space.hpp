#ifndef SPACE_HPP
#define SPACE_HPP

#include "graviter.hpp"

class Space {
    private :
        std::vector<Planets> planets;
        int nb;

    public:
        Space(sf::RenderWindow *win, int nb, int masse);
        void updatePlanets();
        void drawPlanets();
};

#endif