#include <iostream>

using namespace std;

typedef struct struct_name {
    int number;
    float number2;
}struct_name;

int main(void) {
    struct_name boh;
    boh.number2 = 1.3;
    cout << boh.number2 << endl;
    return 0;
}
