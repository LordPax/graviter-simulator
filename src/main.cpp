#include "../libs/graviter.hpp"

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(W, H), "Graviter Simulator");

    Space space(10, 10);
    // space.update();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // space.update();
        window.clear();
        window.display();
    }

    return EXIT_SUCCESS;
}