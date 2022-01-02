#include "csv_reader.hpp"

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::istringstream;
using std::stringstream;
using namespace std;

std::string csv_filename = "./Traffic_Signals_SF.csv";

//HELPER FUNCTION -> string delimiter
std::vector<string> string_delimiter(string str, string delimiter){
    std::vector<std::string> coords;
    std::istringstream iss(str);
    for(std::string str; iss>>str;)
        coords.push_back(str);
    return coords;
}

//HELPER FUNCTION "POINT (-122.40464 37.732944)" -> "-122.40464,37.732944"
string coordinate_parser(string point){
    std::string final_str= "";
    std::string chop = "";
    std::string cut = ""
;    try{
        cut = point.substr(0,point.length()-1);
        chop = cut.substr(8, cut.length()-1);
    } catch (exception e){
        cout<<"coordinate parser error"<<endl;
    }
    //STRING DELIMITER for space now
    std::vector<string> no_space_vec = string_delimiter(chop, " ");
    final_str = "-" + no_space_vec[0] + "," + no_space_vec[1];
    return final_str;
}

std::vector<TrafficController*> controller_read_csv(string filename){
    std::string column_name; 
    string myString;
    string line;
    ifstream myFileStream(filename);
    if(!myFileStream.is_open()){
        cout<<"File failed to open"<<endl;
        cout<<"controller_read_csv"<<endl;
        return {};
    }
    const char *column_names[COLUMN_NUM] = {};
    std::vector<string> cn_vec;
    //read column names
    if(myFileStream.good()){
        std::getline(myFileStream, line);
        std::stringstream ss(line);
        while(std::getline(ss, column_name, ',')){
            cn_vec.push_back({column_name});
        }
    }
    //all intersections
    std::vector<TrafficController*> tc_vec;
    int k=0;
    while (getline(myFileStream, line)){
        stringstream ss(line);
        for (int i=0;i<cn_vec.size();i++){
            getline(ss, cn_vec[i],',');
        };
        int point_pos = 0;
        int point_gps = 0;

        try{
            for (int i = 1; i<cn_vec.size();i++){
                if (cn_vec[i]=="GPS"){
                    point_gps=i;
                }
                if (cn_vec[i].substr(0,5)=="POINT"){
                    point_pos=i;
                } 
            }
        } catch (exception e){
            cn_vec[point_pos] = "shape";
        }

        if (cn_vec[point_pos]!="shape"){
            //create traffic light object
            std::string cnn = cn_vec[0]; //cnn
            std::string street_name = cn_vec[3]; //street name
            int lights_per_intersection = 0;
            std::string description = "";
            std::string coords = "";
            std::vector<string> street_name_vec = {cn_vec[3], cn_vec[4], cn_vec[6], cn_vec[8]};

            if (point_gps!=0 && cn_vec[point_pos]!=""){
                for (int i=0;i<street_name_vec.size();i++){
                    if (street_name_vec[i]!=""){
                        lights_per_intersection +=1;
                        if (i==street_name_vec.size()-1){
                            description = description + street_name_vec[i];
                        } else{
                            description = description + street_name_vec[i]+ " and  ";
                        }
                    }
                }
            }

            std::vector<TrafficLight> intersection_tls;

            // THINK ABOUT LATER
            int current_index=0;

            //traffic cycles based on descriptions
            // per traffic light
            if (lights_per_intersection>0){
                std::string coords = coordinate_parser(cn_vec[point_pos]);
                for (int i=0; i<lights_per_intersection; i++){
                    
                    if (street_name_vec[i]!=""){
                        TrafficLight tl_obj(street_name_vec[i], COLOR_CODES::RED, k);
                        intersection_tls.push_back(tl_obj);
                        k+=1;
                    }   
                }
                // per intersection
                // add to vector of intersections
                tc_vec.push_back(new TrafficController(intersection_tls, current_index, cnn, coords, description));                
            }
        }
    }
    myFileStream.close();
    return tc_vec;
}