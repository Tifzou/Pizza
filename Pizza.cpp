#include "Pizza.h"

#include <iostream>
#include <fstream>

using namespace std;

Pizza::Pizza(string filename)
{
	ifstream inputFile;
	ofstream outputFile;
	string line;
	inputFile.open(filename);
	outputFile.open("easyPizza.txt");
	if(inputFile.is_open() && outputFile.is_open())
	{
		while ( getline (inputFile, line) )
	    {
	      cout << line << '\n';
	      outputFile << line << '\n';
	    }
	    inputFile.close();
	    outputFile.close();
	}
	else
	{
		cout << "Couldn't read " << filename << endl;
	}
}
