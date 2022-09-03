#include <iostream>
#include <chrono>
#include <thread>

int main() {
    for (int i = 0; i<100; i++) {
        //std::cout << i << " hello, world!\n";
        printf("%2d hello, world!\n", i);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}
