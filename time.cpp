#include <iostream>
#include <chrono>
using namespace std;

long get_time_since_epoch()
{
    long time = (long)chrono::high_resolution_clock::now().time_since_epoch().count();
    return time;
}

int main()
{
    for (int i=0; i<10; i++)
    {
        cout << get_time_since_epoch() << "\n";
    }
}


