#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <queue>
#include "light.hpp"

//responsible for single intersection
class TrafficController{
    
    public:
        //traffic controller constructor
        std::vector<TrafficLight> traffic_lights;
        int current_tl_index;
        std::string cnn;
        std::string coords;
        std::string description;

        TrafficController(std::vector<TrafficLight> tls, int current_tl_index, std::string cnn, std::string coords, std::string description);

        int transition();
};