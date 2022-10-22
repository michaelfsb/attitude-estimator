#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void extractVariables(string textLine, vector<string>& timeStamp, vector<string>& accelXaxis, vector<string>& accelYaxis, vector<string>& accelZaxis);

void creatOutputFile(vector<string> roll, vector<string> pitch);

int main(int, char**) {
    
    string textLine;
    vector<string> seglist, timeStamp, accelXaxis, accelYaxis, accelZaxis;
    vector<string> roll, pitch;
    
    ifstream inputFile("attitude_exam.log");

    
    while (getline (inputFile, textLine)) {
        seglist.push_back(textLine);
        extractVariables(textLine, timeStamp, accelXaxis, accelYaxis, accelZaxis);

    }

    inputFile.close();


    // test output file
    roll.push_back("1");
    pitch.push_back("2");
    roll.push_back("3");
    pitch.push_back("4");
    creatOutputFile(roll, pitch);
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

void creatOutputFile(vector<string> roll, vector<string> pitch) {
    ofstream outputFile("attitude_result.log");
    for (int i = 0; i < roll.size(); i++) {
        outputFile << roll[i] << "; " << pitch[i] << endl;
    }
    outputFile.close();
}