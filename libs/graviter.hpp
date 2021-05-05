#ifndef GRAVITER_HPP
#define GRAVITER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <sys/types.h>
#include <unistd.h>

#define W 800
#define H 600
#define FPS_MS 50

struct Point {
    float x;
    float y;
};

bool sleep_every(uint16_t milliseconds);

#include "planets.hpp"
#include "space.hpp"

#endif