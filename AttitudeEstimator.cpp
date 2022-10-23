#include "AttitudeEstimator.h"

using namespace std;

int main()
{
    position pos;
    attitude att;

    readIputFile(pos);

    att = calculateAttitude(pos);

    creatOutputFile(att);
	
	return 0;
}

void extractVariables(string textLine, position& pos) {
    int pos1 = textLine.find(";");
    int pos2 = textLine.find(";", pos1 + 1);
    int pos3 = textLine.find(";", pos2 + 1);
    pos.timeStamp.push_back(textLine.substr(0, pos1));
    pos.accelXaxis.push_back(textLine.substr(pos1 + 1, pos2 - pos1 - 1));
    pos.accelYaxis.push_back(textLine.substr(pos2 + 1, pos3 - pos2 - 1));
    pos.accelZaxis.push_back(textLine.substr(pos3 + 1, textLine.length() - pos3 - 1));
}

void readIputFile(position& pos) {
    string textLine;
    vector<string> seglist;

    ifstream inputFile("attitude_exam.log");

    while (getline(inputFile, textLine)) {
        seglist.push_back(textLine);
        extractVariables(textLine, pos);
    }

    inputFile.close();
}

void creatOutputFile(attitude& att) {
    ofstream outputFile("attitude_result.log");

    for (int i = 0; i < att.timeStamp.size(); i++) {
        outputFile << att.timeStamp[i] << "; " << att.roll[i] << "; " << att.pitch[i] << endl;
    }

    outputFile.close();
}

attitude calculateAttitude(position& pos) {
    attitude att;
    double roll, pitch;

    for (int i = 0; i < pos.timeStamp.size(); i++) {
        att.timeStamp.push_back(pos.timeStamp[i]);
        roll = atan2(stof(pos.accelYaxis[i]), stof(pos.accelZaxis[i])) * 180 / M_PI;
        pitch = atan2(-stof(pos.accelXaxis[i]), sqrt(pow(stof(pos.accelYaxis[i]), 2) 
            + pow(stof(pos.accelYaxis[i]), 2))) * 180 / M_PI;
        att.roll.push_back(to_string(roll));
        att.pitch.push_back(to_string(pitch));
    }

    return att;
}
