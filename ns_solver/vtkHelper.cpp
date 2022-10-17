#include "vtkHelper.h"

using namespace std;

void writeVTK(grid G, ostream& os) {

    os << "# vtk DataFile Version 3.0\n\
vtk output\nASCII\nDATASET RECTILINEAR_GRID\n";
    os << "DIMENSIONS " << G.Nx << " " << G.Ny << " 1" << endl;
    os << "X_COORDINATES " << G.Nx << " float" << endl;
    os <<  G.toStr(G.X);
    os << "Y_COORDINATES " << G.Ny << " float" << endl;
    os <<  G.toStr(G.Y);
    os << "Z_COORDINATES " << 1 << " float" << endl;
    os << 0 << endl;

}
