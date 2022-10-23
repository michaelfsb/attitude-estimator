#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

struct attitude {
    vector<string> timeStamp, roll, pitch;
};

struct position {
    vector<string> timeStamp, accelXaxis, accelYaxis, accelZaxis;
};

void extractVariables(string textLine, position& pos); \

void readIputFile(string fileName, position& pos);

void creatOutputFile(attitude& att);

attitude calculateAttitude(position& pos);
