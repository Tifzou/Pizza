#ifndef PIZZA_H
#define PIZZA_H

#include <string>

using namespace std;

class Pizza
{
/* attributes*/
private:
    int R; // nb of rows in the pizza
    int C; // nb of columns in the pizza
    int L; // minimum ingredient per cell
    int H; // max nb of cells per slice
    int** grid; // pizza cells 0 if mushroom (M) and 1 if tomato (T)
    
    int nbM; // nb Mushrooms
    int nbT; // nb Tomatoes
    int nbSlices;
    int** slices;
    
/*methods*/
public:
    Pizza(string filename);
    ~Pizza();

    void printPizza();

private:
	void cutSlices();
	void printSlices();
};

#endif // PIZZA_H
