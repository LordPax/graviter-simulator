#include "../libs/graviter.hpp"

Space::Space(sf::RenderWindow *win, int nb, int masse) {
    srand(time(NULL));
    for (int i = 0; i < nb; i++)
        this->planets.push_back(Planets(win, masse));
    this->nb = nb;
}

void Space::updatePlanets() {
    int dt = 1;
    for (auto& p : this->planets) {
        if (p.isExist()) {
            for (auto& p2 : this->planets)
                if (p2.isExist())
                    p.graviter(&p2);

            p.setCoord(p.getCoord().x + (p.getVelocity().x * dt), p.getCoord().y + (p.getVelocity().y * dt));
        }
    }
}

void Space::drawPlanets() {
    for (auto& p : this->planets) {
        if (p.isExist())
            p.draw();
    }
}