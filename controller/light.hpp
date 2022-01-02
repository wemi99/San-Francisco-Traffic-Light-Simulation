#pragma once
#include <string>
#include <iostream>
#include <queue>
#include "../iconmaker/types.hpp"
using namespace std;

// one light
class TrafficLight{
    public:
        std::string street_name = "";
        COLOR_CODES color = COLOR_CODES::RED;
        int k;
        TrafficLight(std::string street_name, COLOR_CODES color, int k);
        COLOR_CODES getColor();
        void nextColor();
};
