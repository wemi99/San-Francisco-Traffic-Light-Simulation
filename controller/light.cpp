#include "light.hpp"

TrafficLight::TrafficLight(std::string street_name, COLOR_CODES color, int k){
    this->street_name = street_name;
    this->color = color;
    this->k = k;
}

COLOR_CODES TrafficLight::getColor(){
    return this->color;
}

// red -> green -> yellow -> red
void TrafficLight::nextColor(){
    if (this->color==COLOR_CODES::RED){
        this->color = GREEN;
    } else if (this->color==COLOR_CODES::YELLOW){
        this->color = RED;
    } else if (this->color==COLOR_CODES::GREEN){
        this->color = YELLOW;
    }
}
