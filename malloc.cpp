#include <iostream>
#include <cstdlib>

using namespace std;

int main(void) {
    char *s = (char*)malloc(8);
    for (int i=0;i<8;i++) {
        cin >> *(s+i);
    }
    cout << s << endl;
    free(s);
}
