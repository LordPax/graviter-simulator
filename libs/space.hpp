#ifndef SPACE_HPP
#define SPACE_HPP

#include "graviter.hpp"

class Space {
    private :
        std::vector<Planets> planets;
        int nb;

    public:
        Space(int nb, int masse);
        void update();
        void graviter();
};

#endif