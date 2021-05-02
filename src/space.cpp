#include "../libs/graviter.hpp"

Space::Space(int nb, int masse) {
    srand(time(NULL));
    for (int i = 0; i < nb; i++)
        this->planets.push_back(Planets(masse));
    this->nb = nb;
}

void Space::update() {
    for (auto& p : this->planets) {
        std::cout << "planets test" << std::endl;
    }
}

void Space::graviter() {

}