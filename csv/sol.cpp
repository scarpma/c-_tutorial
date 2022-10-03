#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class csv {
    private:
        string filename;
        ifstream file;
        vector<string> header;
    public:
        vector< vector<string> > lines;
        csv(string filename) {
            this->filename = filename;
            this->file.open(filename);
            this->readAll();
            this->header = lines[0];
        }
        void readAll() {
            string line;
            while (getline(this->file, line)) {
                vector<string> lineVec;
                lineVec = this->parseCommaSepString(line);
                this->lines.push_back(lineVec);
            }
            this->file.close();
            return;
        }
        vector<string> parseCommaSepString(string s) {
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
        void printRow(int lineNum) {
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
};

int main (void) {
    csv csv_contacts("/Users/scarpma/Downloads/contacts.csv");
    for (int i=1; i<csv_contacts.lines.size()-1; i++) {
        csv_contacts.printRow(i);
        cout << endl;
    }

    return 0;
}
