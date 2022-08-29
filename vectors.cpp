#include <iostream>
#include <vector>
using namespace std;

template <typename T>
vector<T> operator+(const vector<T>& a, const vector<T>& b)
{
    assert(a.size() == b.size());

    vector<T> result;
    result.reserve(a.size());

    //std::transform(a.begin(), a.end(), b.begin(), 
    //               std::back_inserter(result), std::plus<T>());

    for (int i=0;i<a.size();i++) {
        result[i] = a[i] + b[i];
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


    return 0;
}
