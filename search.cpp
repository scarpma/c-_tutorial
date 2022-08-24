#include <iostream>
#include <stdlib.h> //srand, rand
#include <random> //default_random_engine, uniform_int_distribution
#include <chrono>
using namespace std;

long get_time_since_epoch()
{
    unsigned time = chrono::high_resolution_clock::now().time_since_epoch().count();
    return time;
}

class rand_uniform
{
    public:

        rand_uniform(int bottom_lim, int top_lim)
        {
            random_device rd;  //Will be used to obtain a seed for the random number engine
            mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
            uniform_int_distribution<int> distrib(0, 9);
        }

        //~rand_uniform(); // destructor

        int generate()
        {
            return distrib(gen);
        }

};

int main()
{
    rand_uniform test(10,12);
    cout << test.generate() << endl;
}


