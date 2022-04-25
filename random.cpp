#include <iostream>
#include <stdlib.h> //srand, rand
#include <random> //default_random_engine, uniform_int_distribution
#include <chrono>
using namespace std;

long get_time_since_epoch()
{
    long time = (long)chrono::high_resolution_clock::now().time_since_epoch().count();
    return time;
}

int main()
{
    // random int between 0 and RAND_MAX
    srand(get_time_since_epoch());
    int a = rand();

    // random int according to distribution
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> distrib(0, 9);
    int b = distrib(gen);
    cout << a << "\n";
    cout << b << "\n";
}


