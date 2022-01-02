#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "events.hpp"

int init_create_traffic_light_csv();

std::vector<Events> priority_to_vector_events(std::priority_queue<Events> events_pq);

int create_traffic_light_csv(std::vector<TrafficController*> tc_vec);

string format_icon_kml(string icon_name);

void write_end_kml();

int write_to_kml_icons();

string format_placemark_kml(string cnn, string description, string icon_name, string coordinates);

int write_placemarks_kml(string cnn, string description, string icon_name, string coordinates);

void add_placemarks_from_queue(std::priority_queue<Events> events_pq);