#ifndef PIZZA_H
#define PIZZA_H

#include <string>

using namespace std;

class Pizza
{
    // attributes
public:
    static int R; // nb of rows in the pizza
    static int C; // nb of columns in the pizza
    int** grid; // pizza cells
    
    // methods
public:
    Pizza(string filename);
	
};

#endif // PIZZA_H
