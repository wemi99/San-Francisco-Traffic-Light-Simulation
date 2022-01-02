#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "light.hpp"
#include "controller_helper.hpp"

class Events{

    public:
        int event_id;
        int time_of_occurrence;
        TrafficController* traffic_controller_pointer;
        Events(int event_id, int time_of_occurrence, TrafficController* traffic_controller_pointer);
        bool operator<(const Events& e1) const;
};