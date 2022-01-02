#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "light.hpp"
#include "controller_helper.hpp"

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::istringstream;
using std::stringstream;
using namespace std;

const int COLUMN_NUM = 40;

//helper: string delimiter
std::vector<string> string_delimiter(string str, string delimiter);

//helper: parse coordinates -> "POINT (x, y)" -> "x,y"
string coordinate_parser(string point);

//read csv
std::vector<TrafficController*> controller_read_csv(string filename);