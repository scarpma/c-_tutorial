/*
   This is a csv parser library. This was written
   for learning and practicing purposes by Martino 
   Andrea Scarpolini (scarpma@gmail.com)
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "csv.h"

using namespace std;

// constructor

csv::csv(string filename) {
    this->filename = filename;
    this->file.open(filename);
    this->readAll();
    this->nLines = this->lines.size();
    this->header = lines[0];
}

// member functions

void csv::readAll() {
    string line;
    while (getline(this->file, line)) {
        vector<string> lineVec;
        lineVec = this->parseCommaSepString(line);
        this->lines.push_back(lineVec);
    }
    this->file.close();
    return;
}

vector<string> csv::parseCommaSepString(string s) {
    vector<string> result;
    stringstream ss(s);
    while (ss.good()) {
        // if (ss.peek() == ',') { // decomment to ignore empty fields
        //     ss.ignore();
        // } else {
            string substr;
            getline( ss, substr, ',');
            result.push_back(substr);
        // }
    }
    return result;
}

void csv::printRow(int lineNum) {
    if (lineNum > this->lines.size()) {
        return;
    }
    cout << "ROW " << lineNum << endl;
    for (int i=0; i<this->lines[lineNum].size();i++) {
        if (this->lines[lineNum][i] != "") { 
        cout << i << ", " << this->header[i] << " : " << this->lines[lineNum][i] << endl;
        }
    }
    return;
}
