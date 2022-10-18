/*
   This is a csv parser library. This was written
   for learning and practicing purposes by Martino 
   Andrea Scarpolini (scarpma@gmail.com)
*/

#ifndef CSV_H       // make sure that this header has not been included already
#define CSV_H

#include <string>
#include <vector>
#include <fstream>
using namespace std;

class csv {
    private:
        string filename;
        ifstream file;
        vector<string> header;
    public:
        vector<vector<string>> lines;
        csv(string filename);
        vector<string> parseCommaSepString(string s);
        void printRow(int lineNum);
        void readAll();
        int nLines;
        
};

#endif
