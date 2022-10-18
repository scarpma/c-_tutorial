#ifndef GRID_H
#define GRID_H

#include <vector>
#include <sstream>
#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>

using namespace std;

class grid {
    private:
    public:
        int Nx, Ny;
        float dx, dy;
        vector<float> X;
        vector<float> Y;
        vector<vector<float> > XX;
        vector<vector<float> > YY;
        grid(int Nx, int Ny, float dx, float dy);
        void allocate();
        void init();
        string toStr(vector<vector<float> > array);
        string toStr(vector<float> array);
};

#endif
