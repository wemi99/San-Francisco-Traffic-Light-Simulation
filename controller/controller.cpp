#include <iostream>
#include <string>
#include "controller_helper.hpp"
#include "light.hpp"
#include "csv_reader.hpp"
#include "events.hpp"
#include "csv_writer.hpp"


int main(int argc, char** argv){
    string t_input;
    int t_int_input = 0;
    try{
        if (argc<2){
            cout<<"wrong number of arguments";
            return 0;
        }
        std::string arg(argv[1]);
        
        if (arg.substr(0,3)=="-t="){
            string after_equals = arg.substr(3);
            t_int_input = stoi(after_equals);
        } else{
            cout<<"Invalid value for t"<<endl;
            return 1;}
    } catch (exception e){
        cout<<"CAUGHT ERROR IN SIMULATION";
    }
    
    std::string csv_filename = "./Traffic_Signals_SF.csv";
    //create traffic controller vectors from csv
    std::vector<TrafficController*> tc_vec = controller_read_csv(csv_filename);

    // dealing with priority queues here
    priority_queue<Events> events_pq;
    // create event
    int counter =0;
    for (int i=0;i<tc_vec.size();i++){
        // init priority queue for each intersection
        counter +=1;
        Events event(counter,0, tc_vec[i]);
        events_pq.push(event);
    }
    int count = 0;
    while (count<=t_int_input && !events_pq.empty()){
        Events e1 = events_pq.top();
        count = e1.time_of_occurrence;
        events_pq.pop();
        int time_left = e1.traffic_controller_pointer->transition();
        Events e_push(e1.event_id, count+time_left, e1.traffic_controller_pointer);
        events_pq.push(e_push);
    }

    //WRITING TO ./myfile.csv for TAs to check
    init_create_traffic_light_csv();
    create_traffic_light_csv(tc_vec);

    // CREATING KML FILE
    write_to_kml_icons(); //writing icons to kml
    
    // 
    add_placemarks_from_queue(events_pq);
    write_end_kml();
    
    return 0;

}