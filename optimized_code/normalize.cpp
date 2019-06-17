#include "headers/normalize.h"
using namespace std;

// OPTIMIZATION: Pass variable by reference
vector< vector<float> > normalize(vector< vector <float> > &grid) {

  	// OPTIMIZATION: Avoid declaring and defining 				// intermediate variables that are not needed.
	float total;
	int i;
	int j;
// 	vector<float> row;
//	vector<float> newRow;
// 	float oldProb;
	for (i = 0; i < grid.size(); i++)
	{
// 		row = grid[i];
		for (j=0; j< grid[0].size(); j++)
		{
// 			oldProb = ;
			total += grid[i][j];
		}
	}

// 	vector< vector<float> > newGrid;

	for (i = 0; i < grid.size(); i++) {
// 		vector<float> row = grid[i];
// 		newRow.clear();
		for (j=0; j< grid[0].size(); j++) {
// 			float oldProb = row[j];
			grid[i][j] = grid[i][j] / total;
// 			newRow.push_back(newProb);
		}
// 		newGrid.push_back(newRow);
	}

	return grid;
}
