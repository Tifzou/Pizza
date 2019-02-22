#include "Pizza.h"

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

Pizza::Pizza(string filename)
{
	grid = NULL;
	nbM = 0;
	nbT = 0;
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
	    				nbM++;
	    			}
	    			else // cell = "T"
	    			{
	    				grid[lineCount-1][col] = 1;
	    				nbT++;
	    			}
	    		}
	    		lineCount++;
	    	}
	    }
	    inputFile.close();
	    
	    nbSlicesMax = min(nbM, nbT)/L;
	    
	    printPizza();
	    
	    printSlices();
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

	for(int row = 0 ; row < R ; row++)
	{
		delete [] slices[row];
	}
	delete [] slices;
}

void Pizza::printPizza()
{
	cout << "Pizza : " << endl;
	for(int row = 0 ; row < R ; row++)
	{
		for(int col = 0 ; col < C ; col++)
		{
			cout << grid[row][col];
		}
		cout << endl;
	}
}

void Pizza::printSlices()
{
	ofstream outputFile;
	outputFile.open("slices.out");
	
	if(outputFile.is_open())
	{
		outputFile << nbSlices << endl;
		cout << "nbSlices : " << nbSlices << endl;
		for (int row = 0 ; row < R ; row++)
		{
			for(int col = 0 ; col < 4 ; col++)
			{
				outputFile << slices[row][col] << " ";
				//cout << slices[row][col] << " ";
			}
			outputFile << endl;
			cout << endl;
		}
		outputFile.close();
	}
}

void Pizza::cutSlices()
{
	
}