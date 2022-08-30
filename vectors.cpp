#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <typename T>
vector<T> operator+(const vector<T>& a, const vector<T>& b)
{
    assert(a.size() == b.size());

    vector<T> result;
    result.reserve(a.size()); // reserve memory of the size of a

    for (int i=0;i<a.size();i++) {
        result.push_back(a[i] + b[i]); // append to result (without reallocating)
    }

    //std::transform(a.begin(), a.end(), b.begin(), 
    //               std::back_inserter(result), std::plus<T>());
    
    return result;
}

template <typename T>
vector<T> operator*(const vector<T>& a, const vector<T>& b)
{
    assert(a.size() == b.size());

    vector<T> result;
    result.reserve(a.size()); // reserve memory of the size of a

    for (int i=0;i<a.size();i++) {
        result.push_back(a[i] * b[i]); // append to result (without reallocating)
    }
    
    return result;
}

void print(vector<int> a) {
    cout << "size " << a.size() << endl;
    for (int i=0;i<a.size();i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


int main(void) {
    
    vector<int> a = {0,1,2};
    vector<int> b = {2,2,2};
    vector<int> c = a+b;
    print(c);
    c = a * b;
    print(c);

    return 0;
}
