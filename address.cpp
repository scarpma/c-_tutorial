#include <iostream>

using namespace std;

int main(void) {
    int n[3] = {1,2,3}; // array of 3 ints
    int * p = &n[0];    // pointer to first element of the array

    printf("%p\n", p);  // print address of n[0]
    printf("%p\n", n);  // print array identifier
    cout << "They are the same !! n is actually a pointer to its first element" << endl;

    cout << endl << "Now lets print the address of every element" << endl;
    printf("%p\n", &n[0]);
    printf("%p\n", &n[1]);
    printf("%p\n", &n[2]);
    printf("%p\n", &n[3]);
    cout << "it adds 4 every time. Because each int occupies 4 bytes !!" << endl;
    cout << "outstanding !!" << endl;
}
