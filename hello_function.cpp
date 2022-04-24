#include <iostream>

void helloWorld(int n) {
    for (int i = 0; i < n; i++) {
        printf("%2d hello, world!\n", i);
    }
}

int main() {
    helloWorld(10);
    return 0;
}

