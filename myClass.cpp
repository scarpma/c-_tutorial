#include <iostream>
#include <string.h>
using namespace std;

class MyClass
{
    public:
        // static attribute
        int const myNum = 121;
        string myString = "ciao";
};


class cpuFloatTensor
{
    public:
        int const ndim;
        int const size[];
        cpuFloatTensor(int ndim, int size[])
        {
            data = new 
        }



};


int main()
{
    MyClass myObj;
    cout << myObj.myNum << "\n";
    cout << myObj.myString << "\n";
    myObj.myString = "booh";
    cout << myObj.myString << "\n";
}
