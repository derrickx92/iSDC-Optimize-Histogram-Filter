#include "headers/initialize_beliefs.h"

using namespace std;

// OPTIMIZATION: pass large variables by reference
vector< vector <float> > initialize_beliefs(int height, int width) {

	// OPTIMIZATION: Which of these variables are necessary?
	// OPTIMIZATION: Reserve space in memory for vectors
  	vector< vector <float> > newGrid;
	vector<float> newRow;
  	newGrid.reserve(height);
  	newRow.reserve(width);
// 	int i, j;
//   , height, width, area
  
// 	float prob_per_cell;
// total,
// 	height = grid.size();
// 	width = grid[0].size();
 
// 	area = height * width;

  	float prob_per_cell = 1.0 / float(height*width) ;

  	// OPTIMIZATION: Is there a way to get the same results 	// without nested for loops?
	
  	newRow.assign(width, prob_per_cell);
  
  for (int i=0; i<height; i++) {
		newGrid.push_back(newRow);
	}
	return newGrid;
}