#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void extractVariables(string textLine, vector<string>& timeStamp, vector<string>& accelXaxis, vector<string>& accelYaxis, vector<string>& accelZaxis);

int main(int, char**) {
    
    string textLine;
    vector<string> seglist, timeStamp, accelXaxis, accelYaxis, accelZaxis;
    
    // Read from the text file
    ifstream inputFile("attitude_exam.log");

    
    while (getline (inputFile, textLine)) {
        seglist.push_back(textLine);
        extractVariables(textLine, timeStamp, accelXaxis, accelYaxis, accelZaxis);

    }

    // Close the file
    inputFile.close();
}

void extractVariables(string textLine, vector<string>& timeStamp, vector<string>& accelXaxis, vector<string>& accelYaxis, vector<string>& accelZaxis) {
        int pos1 = textLine.find(";");
        int pos2 = textLine.find(";", pos1+1);
        int pos3 = textLine.find(";", pos2+1);
        timeStamp.push_back(textLine.substr(0, pos1));
        accelXaxis.push_back(textLine.substr(pos1+1, pos2-pos1-1));
        accelYaxis.push_back(textLine.substr(pos2+1, pos3-pos2-1));
        accelZaxis.push_back(textLine.substr(pos3+1, textLine.length()-pos3-1));
}