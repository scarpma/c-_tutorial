#include <iostream>
#include <ostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Tensor{
    private:
        int* arr;
        int rows;
        int cols;
    public:

        Tensor(int rows, int cols) {
            arr = (int*)malloc(sizeof(int)*rows*cols);
            for (int i=0; i<rows*cols; i++) {
                arr[i] = 0;
            }
            this->rows = rows;
            this->cols = cols;
        }

        vector<int> shape() {
            vector<int> s = {this->rows, this->cols};
            return s;
        }

        void set(int i, int j, int num) {
            this->arr[i*cols+j] = num;
        }

        void free() {
            ::free(this->arr); // refers to the top level namespace (global)
        }

        int operator() (int i) {return this->arr[i];}

        int operator() (int i, int j) {
            return this->arr[i*cols+j];
        }

};

ostream& operator<<(ostream& out, Tensor& t) {

    int last_i, last_j;
    last_i = t.shape()[0]-1;
    last_j = t.shape()[1]-1;
    
    for (int i=0; i < last_i; i++) {
        for (int j=0; j < last_j; j++) {
            out << t(i,j) << " ";
        }
        out << t(i,last_j) << endl;
    }
    for (int j=0; j < last_j; j++) {
        out << t(last_i,j) << " ";
    }
    out << t(last_i, last_j);

    return out;
}

int main(void) {
    
    Tensor t(16,16);

    for (int i=0; i < t.shape()[0]; i++) {
        for (int j=0; j < t.shape()[1]; j++) {
            t.set(i,j,i*t.shape()[1]+j);
        }
    }

    cout << t << endl;
    t.free();
    return 0;
}
