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
	if(inputFile.is_open() && outputFile.is_open())
	{
		int i = 0; // line counter
		while ( getline (inputFile, line) )
	    {
	    	if (i==0)
	    	{
	    		string::size_type spacePosition = line.find(' ');
	    		string rowNb = line.substr(0, spacePosition);
	    		R = stoi(rowNb);
	    		
	    		string::size_type newSpacePosition = line.find(' ', spacePosition);
	    		string colNb = line.substr(spacePosition+1, newSpacePosition + 1 - spacePosition );
	    		C = stoi(colNb);

	    		spacePosition = newSpacePosition+1;
	    		newSpacePosition = line.find(' ', spacePosition);
	    		string miniIngr = line.substr(spacePosition+1, newSpacePosition + 1 - spacePosition);
	    		L = stoi(miniIngr);

	    		size_t lineLength = line.length();
	    		spacePosition = newSpacePosition+2;
	    		string maxiCells = line.substr(spacePosition, lineLength - spacePosition);
	    		H = stoi(maxiCells);
	    		i++;
	    	}
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

void Pizza::slices()
{

}
