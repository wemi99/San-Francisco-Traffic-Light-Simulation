#include "controller_helper.hpp"

//responsible for single intersection
//constructor function
//create traffic lights vector with the given size
TrafficController::TrafficController(std::vector<TrafficLight> tls, int current_tl_index, std::string cnn, std::string coords, std::string description):traffic_lights(tls){
    this->current_tl_index=current_tl_index;
    this->cnn=cnn;
    this->coords=coords;
    this->description=description;
};


// change lights to next step in cycle and returns event -> next 
int TrafficController::transition(){
    int time_left = 0;
    int time_green = 0;
    int time_yellow = 10;
    int time_red = 0;

    //current light
    TrafficLight& current_tl = traffic_lights[current_tl_index];

    if (current_tl.color==COLOR_CODES::YELLOW){
        current_tl.nextColor();
        current_tl_index +=1;
        traffic_lights[current_tl_index].nextColor();

        int k = traffic_lights[current_tl_index].k;

        if (k%25==0){
            time_green = 90;
        } else if (k%25<15){
            time_green = 60;
        } else {
            time_green = 30;
        }
    } else if (current_tl.color==COLOR_CODES::RED){
        traffic_lights[current_tl_index].nextColor();

        int k = traffic_lights[current_tl_index].k;

        if (k%25==0){
            time_green = 90;
        } else if (k%25<15){
            time_green = 60;
        } else {
            time_green = 30;
        }
    } else if (current_tl.color==COLOR_CODES::GREEN){
        traffic_lights[current_tl_index].nextColor();

        int k = traffic_lights[current_tl_index].k;

        time_green = 10;
    }
    return time_green;
}
