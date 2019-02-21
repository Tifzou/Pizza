#include "Pizza.h"

#include <iostream>
#include <fstream>

using namespace std;

Pizza::Pizza(string filename)
{
	grid = NULL;
	string line;
	
	ifstream inputFile;
	inputFile.open(filename);
	
	if(inputFile.is_open())
	{
		int lineCount = 0; // line counter
		while ( getline (inputFile, line) )
	    {
	    	if (lineCount==0)
	    	{
	    		string::size_type spacePosition = line.find(' ');
	    		string rowNb = line.substr(0, spacePosition);
	    		R = stoi(rowNb);
	    		grid = new int*[R];
	    		
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
	    		lineCount++;
	    	}
	    	else
	    	{
	    		grid[lineCount-1] = new int[C];
	    		for(int col = 0 ; col < C ; col++)
	    		{
	    			
	    			string cell = line.substr(col, 1);
	    			if(cell == "M")
	    			{
	    				grid[lineCount-1][col] = 0;
	    			}
	    			else // cell = "T"
	    			{
	    				grid[lineCount-1][col] = 1;
	    			}
	    		}
	    		lineCount++;
	    	}
	    }
	    inputFile.close();
	    printPizza();
	}
	else
	{
		cout << "Couldn't read " << filename << endl;
	}
}

Pizza::~Pizza()
{
	for(int row = 0 ; row < R ; row++)
	{
		delete [] grid[row];
	}
	delete [] grid;
}

void Pizza::printPizza()
{
	for(int row = 0 ; row < R ; row++)
	{
		for(int col = 0 ; col < C ; col++)
		{
			cout << grid[row][col];
		}
		cout << endl;
	}
}