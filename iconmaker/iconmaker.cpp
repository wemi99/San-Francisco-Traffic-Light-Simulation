// PURPOSE: https://github.com/pngwriter/pngwriter/blob/master/examples/pngtest.cc
#include "./pngwriter.hpp"
#include <string>
#include <iostream>
#include <array>
#include <fstream>
#include "./types.hpp"
using namespace std;

const int MAX_COLOR_VALUE = 65535;

const std::array<COLOR_CODES,3> ALL_COLORS = {RED,YELLOW,GREEN};  

struct rgb {
  int r_comp;
  int g_comp;
  int b_comp;

  char name[2];
};

void two_drawing_tool(int num_lights, rgb x_color, rgb y_color){
    // CREATING IMAGE NAME
    std::string img_n = std::string("./files/i2") + x_color.name + y_color.name + ".png";

    // write file names
    ofstream myfile("../controller/icon_names.txt", ios_base::app);
    string file_entry = std::string("i2") + x_color.name + y_color.name + std::string("\n");
    myfile << file_entry;
    myfile.close();


    // start drawing
    pngwriter image2(64,64,0, img_n.c_str());

    // horizontal
    image2.line(0,34,64,34,x_color.r_comp,x_color.g_comp, x_color.b_comp);
    image2.line(0,33,64,33,x_color.r_comp,x_color.g_comp, x_color.b_comp);
    image2.line(0,32,64,32,x_color.r_comp,x_color.g_comp, x_color.b_comp);
    image2.line(0,31,64,31,x_color.r_comp,x_color.g_comp, x_color.b_comp);
    image2.line(0,30,64,30,x_color.r_comp,x_color.g_comp, x_color.b_comp);

    // vertical
    image2.line(34,0,34,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);
    image2.line(33,0,33,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);
    image2.line(32,0,32,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);
    image2.line(31,0,31,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);
    image2.line(30,0,30,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);

    // end drawing
    image2.close();
}

void three_drawing_tool(int num_lights, rgb x_color, rgb y_color, rgb z_color){
    std::string img_n = std::string("./files/i3") + x_color.name + y_color.name + z_color.name + ".png";
    // write file names
    ofstream myfile("../controller/icon_names.txt", ios_base::app);
    string file_entry = std::string("i3") + x_color.name + y_color.name + z_color.name + std::string("\n");
    myfile << file_entry;
    myfile.close();

    // start drawing
    pngwriter image3(64,64,0,img_n.c_str());
    // horizontal
    image3.line(0,34,64,34,x_color.r_comp,x_color.g_comp, x_color.b_comp);
    image3.line(0,33,64,33,x_color.r_comp,x_color.g_comp, x_color.b_comp);
    image3.line(0,32,64,32,x_color.r_comp,x_color.g_comp, x_color.b_comp);
    image3.line(0,31,64,31,x_color.r_comp,x_color.g_comp, x_color.b_comp);
    image3.line(0,30,64,30,x_color.r_comp,x_color.g_comp, x_color.b_comp);
    // vertical
    image3.line(34,0,34,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);
    image3.line(33,0,33,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);
    image3.line(32,0,32,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);
    image3.line(31,0,31,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);
    image3.line(30,0,30,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);
    // diagonal
    image3.line(0,3,61,64,z_color.r_comp,z_color.g_comp,z_color.b_comp);
    image3.line(0,2,62,64,z_color.r_comp,z_color.g_comp,z_color.b_comp);
    image3.line(0,1,63,64,z_color.r_comp,z_color.g_comp,z_color.b_comp);
    image3.line(0,0,64,64,z_color.r_comp,z_color.g_comp,z_color.b_comp);
    image3.line(1,0,64,63,z_color.r_comp,z_color.g_comp,z_color.b_comp);
    image3.line(2,0,64,62,z_color.r_comp,z_color.g_comp,z_color.b_comp);
    image3.line(3,0,64,61,z_color.r_comp,z_color.g_comp,z_color.b_comp);
    //close image
    image3.close();

}

void four_drawing_tool(int num_lights, rgb x_color, rgb y_color, rgb z_color, rgb i_color){
    std::string img_n = std::string("./files/i4") + x_color.name + y_color.name + z_color.name + i_color.name + ".png";

    // write file names
    ofstream myfile("../controller/icon_names.txt", ios_base::app);
    string file_entry = std::string("i4") + x_color.name + y_color.name + z_color.name + i_color.name +std::string("\n");
    myfile << file_entry;
    myfile.close();

    pngwriter image4(64,64,0,img_n.c_str());

    // horizontal
    image4.line(0,34,64,34,x_color.r_comp,x_color.g_comp, x_color.b_comp);
    image4.line(0,33,64,33,x_color.r_comp,x_color.g_comp, x_color.b_comp);
    image4.line(0,32,64,32,x_color.r_comp,x_color.g_comp, x_color.b_comp);
    image4.line(0,31,64,31,x_color.r_comp,x_color.g_comp, x_color.b_comp);
    image4.line(0,30,64,30,x_color.r_comp,x_color.g_comp, x_color.b_comp);
    // vertical
    image4.line(34,0,34,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);
    image4.line(33,0,33,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);
    image4.line(32,0,32,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);
    image4.line(31,0,31,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);
    image4.line(30,0,30,64,y_color.r_comp,y_color.g_comp, y_color.b_comp);
    // diagonal
    image4.line(0,3,61,64,z_color.r_comp,z_color.g_comp,z_color.b_comp);
    image4.line(0,2,62,64,z_color.r_comp,z_color.g_comp,z_color.b_comp);
    image4.line(0,1,63,64,z_color.r_comp,z_color.g_comp,z_color.b_comp);
    image4.line(0,0,64,64,z_color.r_comp,z_color.g_comp,z_color.b_comp);
    image4.line(1,0,64,63,z_color.r_comp,z_color.g_comp,z_color.b_comp);
    image4.line(2,0,64,62,z_color.r_comp,z_color.g_comp,z_color.b_comp);
    image4.line(3,0,64,61,z_color.r_comp,z_color.g_comp,z_color.b_comp);
    // diagonal2
    image4.line(3,64,64,3,i_color.r_comp,i_color.g_comp,i_color.b_comp);
    image4.line(2,64,64,2,i_color.r_comp,i_color.g_comp,i_color.b_comp);
    image4.line(1,64,64,1,i_color.r_comp,i_color.g_comp,i_color.b_comp);
    image4.line(0,64,64,0,i_color.r_comp,i_color.g_comp,i_color.b_comp);
    image4.line(0,63,63,0,i_color.r_comp,i_color.g_comp,i_color.b_comp);
    image4.line(0,62,62,0,i_color.r_comp,i_color.g_comp,i_color.b_comp);
    image4.line(0,61,61,0,i_color.r_comp,i_color.g_comp,i_color.b_comp);

    image4.close();
}

rgb code_to_color(COLOR_CODES color_coding) {
    switch(color_coding) {
        case RED:
            return rgb {MAX_COLOR_VALUE, 0, 0, "r"};
        case YELLOW:
            return rgb {MAX_COLOR_VALUE, MAX_COLOR_VALUE, 0, "y"};
        case GREEN:
            return rgb {0, MAX_COLOR_VALUE, 0, "g"};
    };
    // covering for an error
    return rgb {MAX_COLOR_VALUE, 0, 0, "r"};
}

void two_light_helper(){
    for(COLOR_CODES x : ALL_COLORS) {
        rgb x_color = code_to_color(x);
        for(COLOR_CODES y : ALL_COLORS) {
            rgb y_color = code_to_color(y);
        two_drawing_tool(2, x_color, y_color);
        };
    };
}

void three_light_helper(){
    for(COLOR_CODES x : ALL_COLORS) {
        rgb x_color = code_to_color(x);
        for(COLOR_CODES y : ALL_COLORS) {
            rgb y_color = code_to_color(y);
            for (COLOR_CODES z : ALL_COLORS){
                rgb z_color = code_to_color(z);
                three_drawing_tool(3, x_color, y_color, z_color);
            };
        };
    };
}

void four_light_helper(){
    for(COLOR_CODES x : ALL_COLORS) {
        rgb x_color = code_to_color(x);
        for(COLOR_CODES y : ALL_COLORS) {
            rgb y_color = code_to_color(y);
            for (COLOR_CODES z : ALL_COLORS){
                rgb z_color = code_to_color(z);
                for (COLOR_CODES i : ALL_COLORS){
                    rgb i_color = code_to_color(i);
                    four_drawing_tool(3, x_color, y_color, z_color, i_color);
                }       
            };
        };
    };
}

int main(){
    // clear text file to ensure empty
    std::ofstream ofs;
    ofs.open("../controller/icon_names.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    two_light_helper();
    three_light_helper();
    four_light_helper();
    cout<<"\nIcons created!\n";
    return 0;
} 