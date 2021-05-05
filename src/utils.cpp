#include "../libs/graviter.hpp"

bool sleep_every(uint16_t milliseconds) {
	static sf::Clock clock;
	
	if (clock.getElapsedTime() >= sf::milliseconds(milliseconds)) {
		clock.restart();
		return true;
	}
	else
		return false;
}