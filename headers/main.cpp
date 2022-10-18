#include <iostream>
#include "csv.h"

using namespace std;

int main (void) {
    csv csv_contacts("/Users/scarpma/Downloads/contacts.csv");
    for (int i=1; i < csv_contacts.nLines - 1; i++) {
        csv_contacts.printRow(i);
        cout << endl;
    }

    return 0;
}
