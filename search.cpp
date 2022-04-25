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

class rand_uniform
{
    public:
        rand_uniform(int bottom_lim, int top_lim)
        {
            std::random_device rd;  //Will be used to obtain a seed for the random number engine
            std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
            std::uniform_int_distribution<int> distrib(0, 9);
        }
        int generate()
        {
            distrib(gen);
        }

};

int main()
{
    rand_uniform generator(0, 9);
    cout << generator.generate() << "\n";
}


