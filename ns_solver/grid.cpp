/*

    o-------> x (second dim j in matrix form)
    |
    |
    |
    |
    \/
    y (first dim i in matrix form)

    e.g.

    |(0,0)  (0,1)  ...|
    |                 |
    |(1,0)  (1,1)  ...|
    |  .      .   .   |
    |  .      .     . |
    |  .      .      .|


*/

#include "grid.h"

using namespace std;

grid::grid(int Nx, int Ny, float dx, float dy) {
    this->Nx = Nx;
    this->Ny = Ny;
    this->dx = dx;
    this->dy = dy;
    this->allocate();
    this->init();
}
void grid::allocate() {
    this->X.resize(this->Ny);
    this->Y.resize(this->Nx);
}
void grid::init() {
    for (int i=0; i<this->Ny; i++) {
        this->X[i] = i*this->dy;
    }
    for (int j=0; j<this->Nx; j++) {
        this->Y[j] = j*this->dx;
    }
}

string grid::toStr(vector<float> array) {
    int N;
    stringstream buffer;
    N = array.size();
    for (int i=0; i<N; i++) {
        buffer << array[i] << " ";
    }
    buffer << endl;
    return buffer.str();
}
