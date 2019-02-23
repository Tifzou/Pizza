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
	    
	    cutSlices();
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
		//cout << "nbSlices : " << nbSlices << endl;
		//for (int row = 0 ; row < R ; row++)
		for (vector<vector<int>>::iterator it = vector_slices.begin() ; it != vector_slices.end() ; ++it)
		{
			for(vector<int>::iterator it2 = it->begin() ; it2 != it->end() ; ++it2)
			{
				outputFile << *it2 << " ";
				//cout << *it2 << " ";
				//outputFile << slices[row][col] << " ";
				//cout << slices[row][col] << " ";
			}
			outputFile << endl;
			//cout << endl;
		}
		outputFile.close();
	}
}

void Pizza::cutSlices()
{
	for (int row = 0 ; row < R ; row++)
	{
		int t_count = 0;
		int m_count = 0;
		int slice_begin = 0;
		int slice_end = 0;

		while(slice_end < C)
		{
			if(grid[row][slice_end] == 0) // M
			{
				m_count++;
				//cout << m_count <<"th mushroom, in coord " << row << " " << slice_end << endl;
			}
			else if(grid[row][slice_end] == 1) // T
			{
				t_count++;
				//cout << t_count <<"th tomato in coord " << row << " " << slice_end << endl;

			}
			slice_end++;
			//cout << "slice_end ++ ==> " << slice_end << endl;

			if(slice_end - slice_begin > H)
			{
				//cout << "slice too big" << endl;
				if(grid[row][slice_begin] == 0) // M
				{
					m_count--;
					//cout << "take away 1 mushroom ==> " << m_count << endl;
				}
				else if(grid[row][slice_begin] == 1) // T
				{
					t_count--;
					//cout << "take away 1 tomato ==> " << t_count << endl;
				}
				slice_begin++;
				//cout << "slice_begin ++ ==> " << slice_begin << endl;
			}
			if(slice_end - slice_begin <= H
				&& m_count >= L
				&& t_count >= L)
			{
				//cout << "slice is valid!" << endl;
				vector<int> sliceDetails;
				sliceDetails.push_back(row);
				sliceDetails.push_back(slice_begin);
				sliceDetails.push_back(row);
				sliceDetails.push_back(slice_end-1);

				vector_slices.push_back(sliceDetails);
				
				nbSlices++;
				
				slice_begin = slice_end;
				t_count = 0;
				m_count = 0;
			}
		}
	}
}