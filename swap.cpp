#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// // the following does not work
// // because a and b are copies
// // of x and y
// void swap(int a, int b) {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }

int main(void) {
    int x = 0, y = 1;
    printf("x is %i y is %i\n", x, y);
    swap(&x,&y);
    printf("x is %i y is %i\n", x, y);
}
