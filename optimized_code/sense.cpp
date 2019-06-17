#include "headers/sense.h"

using namespace std;

// OPTIMIZATION: Pass larger variables by reference
vector< vector <float> > sense(char color, 
                               vector< vector <char> > &grid, 
                               vector< vector <float> > &beliefs,  
                               float p_hit, 
                               float p_miss) 
{
	// OPTIMIZATION: Is the newGrid variable necessary?
  	// Could the beliefs input variable be updated directly?
//   	vector< vector <float> > newGrid;
// 	vector<float> row, newRow;

// 	float p;

// 	char cell;
// 	int i, j;
//   , height, width;
// 	int height = grid.size();
// 	int width = grid.size();

	for (int i=0; i<grid.size(); i++) {
// 		newRow.clear();
		for (int j=0; j<grid[0].size(); j++) {
          	// OPTIMIZATION: Which of these variables are 					needed?
// 			prior = ;
			char cell = grid[i][j];
			if (cell == color) {
				beliefs[i][j] = beliefs[i][j] * p_hit;
			}
            // OPTIMIZATION: if else statements might be 
          	// 	faster than two if statements
			else{
				beliefs[i][j] = beliefs[i][j] * p_miss;
			}
// 			beliefs[i][j]=p;
          
//           newRow.push_back(p);
		}
// 		beliefs.push_back(newRow);
	}
	return beliefs;
}
