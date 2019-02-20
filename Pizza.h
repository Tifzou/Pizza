#ifndef PIZZA_H
#define PIZZA_H

#include <string>

using namespace std;

class Pizza
{
    // attributes
public:
    int R; // nb of rows in the pizza
    int C; // nb of columns in the pizza
    int L; // minimum ingredient per cell
    int H; // max nb of cells per slice
    int** grid; // pizza cells
    
    // methods
public:
    Pizza(string filename);
};

#endif // PIZZA_H
