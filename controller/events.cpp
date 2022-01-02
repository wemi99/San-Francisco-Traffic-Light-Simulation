#include "controller_helper.hpp"
#include "events.hpp"

Events::Events(int event_id, int time_of_occurrence, TrafficController* traffic_controller_pointer){
    this->event_id=event_id;
    this->time_of_occurrence=time_of_occurrence;
    this->traffic_controller_pointer=traffic_controller_pointer;
}

bool Events::operator<(const Events& e1) const{
    if (this->time_of_occurrence>e1.time_of_occurrence){
        return true;
    } else{
        return false;
    }
}