#include <iostream>
#include <fstream>

#include "vtkHelper.h"
#include "grid.h"

using namespace std;


int main (void) {

    ofstream file;
    file.open("prova.vtk");
    grid G(100,100,1.0,1.0);
    writeVTK(G, file);
    file.close();

}
