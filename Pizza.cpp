#include "Pizza.h"

#include <iostream>
#include <fstream>

using namespace std;

Pizza::Pizza(string filename)
{
	ifstream inputFile;
	string line;
	inputFile.open(filename, ios::in);
	if(inputFile.is_open())
	{
		while ( getline (inputFile, line) )
	    {
	      cout << line << '\n';
	    }
	    inputFile.close();
	}
	else
	{
		cout << "Couldn't read " << filename << endl;
	}
}
