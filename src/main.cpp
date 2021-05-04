#include "../libs/graviter.hpp"

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage : " << argv[0] << " <nb> <mass>" << std::endl;
        return EXIT_FAILURE;
    }

    int nb = atoi(argv[1]);
    int mass = atoi(argv[2]);

    sf::RenderWindow window(sf::VideoMode(W, H), "Graviter Simulator");
    window.setFramerateLimit(60);
    Space space(&window, nb, mass);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        space.drawPlanets();
        window.display();

        space.updatePlanets();
    }

    return EXIT_SUCCESS;
}