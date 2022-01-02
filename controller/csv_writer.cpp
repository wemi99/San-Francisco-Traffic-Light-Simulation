#include "csv_writer.hpp"

int init_create_traffic_light_csv(){
    string traffic_light_csv_name = "./myfile.csv";
    ifstream myFileStream(traffic_light_csv_name);
    myFileStream.is_open();
    ofstream myfile(traffic_light_csv_name);
    myfile<<"CNN,STREET,COLOR\n";
    myfile.close();
    return 1;
}

std::vector<Events> priority_to_vector_events(std::priority_queue<Events> events_pq){
    std::vector<Events> events_vec = {};
    while (!events_pq.empty()){
        Events event = events_pq.top();
        events_pq.pop();
        events_vec.push_back(event);
    }
    return events_vec;
}

int create_traffic_light_csv(std::vector<TrafficController*> tc_vec){
    string traffic_light_csv_name = "./myfile.csv";
    ifstream myFileStream(traffic_light_csv_name);
    if (!myFileStream.is_open()){
        cout<<"File failed to open"<<endl;
        cout<<"create traffic light csv"<<endl;
        return 0;
    }
    //write file names
    ofstream myfile(traffic_light_csv_name, ios_base::app);
    // iterate through the objects
    for (int i=0; i<tc_vec.size();i++){
        std::string file_entry = "";
        TrafficController tc_at_i = *tc_vec[i];

        std::string color_str = "";
        for (int j=0;j<tc_at_i.traffic_lights.size();j++){
            if (tc_at_i.traffic_lights[j].color==COLOR_CODES::RED){
                color_str = "RED";
            } else if (tc_at_i.traffic_lights[j].color==COLOR_CODES::YELLOW){
                color_str = "YELLOW";
            } else if (tc_at_i.traffic_lights[j].color==COLOR_CODES::GREEN){
                color_str = "GREEN";
            }
            file_entry = tc_at_i.cnn + "," + tc_at_i.traffic_lights[j].street_name + "," + color_str + "\n";
            myfile<<file_entry;
        }

    }
    myfile.close();
    return 1;
}

string format_icon_kml(string icon_name){
    string icon_kml = "";
    icon_kml = icon_kml + "<Style id=\"" + icon_name +"\">\n";
    icon_kml = icon_kml + "\t<IconStyle id=\"" + icon_name +"\">\n";
    icon_kml = icon_kml + "\t\t<Icon>\n";
    icon_kml = icon_kml + "\t\t\t<href>files/"+icon_name+".png</href>\n";
    icon_kml = icon_kml + "\t\t\t<scale>1.0</scale>\n";
    icon_kml = icon_kml + "\t\t</Icon>\n";
    icon_kml = icon_kml + "\t</IconStyle>\n";
    icon_kml = icon_kml + "</Style>\n";
    return icon_kml;
}

void write_end_kml(){
    std::ofstream ofs;
    ofs.open("./myfile.kml", ios_base::app);
    ofs<<"</Document>\n</kml>";
    ofs.close();
}

int write_to_kml_icons(){
    string filename1 = "./myfile.kml";
    string filename2 = "icon_names.txt";
    //clear text file to ensure empty
    std::ofstream ofs;
    ofs.open(filename1, std::ofstream::out | std::ofstream::trunc);
    ofs<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    ofs<<"<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n";
    ofs<<"<Document>\n";
    ofs.close();

    ifstream myFileStream(filename2);
    if (!myFileStream.is_open()){
        cout<<"File failed to open"<<endl;
        cout<<"write to kml icons"<<endl;
        return 0;
    }
    string icon_name;
    string myString;
    string line;
    while(getline(myFileStream, line)){
        stringstream ss(line);
        getline(ss, icon_name);
        //write file names
        ofstream myfile(filename1, ios_base::app);
        string file_entry = format_icon_kml(icon_name);
        myfile << file_entry;
        myfile.close();
    }
    return 1;
}

string format_placemark_kml(string cnn, string description, string icon_name, string coordinates){
    string placemark_kml = "";
    placemark_kml = "<Placemark>\n";
    placemark_kml = placemark_kml + "\t<name>"+cnn+"</name>\n";
    placemark_kml = placemark_kml + "\t<description>"+description+"</description>\n";
    placemark_kml = placemark_kml + "\t<styleUrl>#"+icon_name+"</styleUrl>\n";
    placemark_kml = placemark_kml + "\t<Point>\n";
    placemark_kml = placemark_kml + "\t\t<coordinates>"+coordinates+"</coordinates>\n";
    placemark_kml = placemark_kml + "\t</Point>\n";
    placemark_kml = placemark_kml + "</Placemark>\n";
    return placemark_kml;
}

int write_placemarks_kml(string cnn, string description, string icon_name, string coordinates){
    string filename = "./myfile.kml";
    ifstream myFileStream(filename);
    if (!myFileStream.is_open()){
        cout<<"File failed to open"<<endl;
        cout<<"write placemarks kml"<<endl;
        return 0;
    }
    //write file names
    ofstream myfile(filename, ios_base::app);
    //would insert icon name here
    string file_entry = format_placemark_kml(cnn, description, icon_name, coordinates);
    myfile << file_entry;
    myfile.close();
    return 1;
}

void add_placemarks_from_queue(std::priority_queue<Events> events_pq){
    std::vector<Events> events_vec = priority_to_vector_events(events_pq);
    for (int i=0;i<events_vec.size();i++){
        TrafficController tc = *events_vec[i].traffic_controller_pointer;
        std::string img_name = "i" + std::to_string(tc.traffic_lights.size());
        std::vector<TrafficLight> tls = tc.traffic_lights;
        for (int j=0;j<tls.size();j++){
            if (tls[j].color==COLOR_CODES::RED){
                img_name = img_name + "r";
            } else if (tls[j].color==COLOR_CODES::YELLOW){
                img_name = img_name + "y";
            } else if (tls[j].color==COLOR_CODES::GREEN){
                img_name = img_name + "g";
            }
        }
        std::string cnn = tc.cnn;
        std::string description = tc.description;
        std::string coords = tc.coords;
        write_placemarks_kml(cnn, description, img_name, coords);
    }
}