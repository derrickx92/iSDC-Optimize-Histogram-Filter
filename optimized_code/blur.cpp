#include "headers/blur.h"
#include "headers/zeros.h"

using namespace std;

// OPTIMIZATION: Pass large variable by reference
vector < vector <float> > blur(vector < vector < float> > &grid, float blurring) {

	// OPTIMIZATION: window, DX and  DY variables have the 
    // same value each time the function is run.
  	// It's very inefficient to recalculate the vectors
    // every time the function runs. 
    // 
    // The const and/or static operator could be useful.
  	// Define and declare window, DX, and DY using the
    // bracket syntax: vector<int> foo = {1, 2, 3, 4} 
    // instead of calculating these vectors with for loops 
    // and push back

  	int height;
	int width;

	height = grid.size();
	width = grid[0].size();
  
	vector < vector <float> > newGrid = zeros(height, width);
	vector <float> row;
	vector <float> newRow;



	static float center = 1.0 - blurring;
	static float corner = blurring / 12.0;
	static float adjacent = blurring / 6.0;

  	static vector < vector <float> > window = {
      {corner, adjacent, corner},
      {adjacent, center, adjacent},
      {corner, adjacent, corner}
    };
  
// 	int i, j;
// 	float val;

// 	for (i=0; i<3; i++) {
// 		row.clear();
// 		for (j=0; j<3; j++) {
// 			switch (i) {
// 				case 0: 
// 				switch (j) {
// 					case 0: 
// 					val = corner;
// 					break;

// 					case 1: 
// 					val = adjacent;
// 					break;

// 					case 2: 
// 					val = corner;
// 					break;
// 				}
// 				break; 

// 				case 1:
// 				switch (j) {
// 					case 0: 
// 					val = adjacent;
// 					break;

// 					case 1: 
// 					val = center;
// 					break;
					
// 					case 2: 
// 					val = adjacent;
// 					break;
// 				}
// 				break;

// 				case 2:
// 				switch(j) {
// 					case 0: 
// 					val = corner;
// 					break;

// 					case 1: 
// 					val = adjacent;
// 					break;
					
// 					case 2: 
// 					val = corner;
// 					break;
// 				}
// 				break;
// 			}
// 			row.push_back(val);
// 		}
// 		window.push_back(row);
// 	}


// 	vector <int> DX;
// 	vector <int> DY;

// 	DX.push_back(-1); DX.push_back(0); DX.push_back(1);
// 	DY.push_back(-1); DY.push_back(0); DY.push_back(1);

  	static vector<int> DX = {-1, 0, 1};
//   	static vector<int> DY = {-1, 0, 1}
  
	int dx;
	int dy;
// 	int ii;
// 	int jj;
	int new_i;
	int new_j;
	float multiplier;
	float newVal;

	// OPTIMIZATION: Use your improved zeros function
// 	for (i=0; i<height; i++) {
// 		newRow.clear();
// 		for (j=0; j<width; j++) {
// 			newRow.push_back(0.0);
// 		}
// 		newGrid.push_back(newRow);
// 	}
  
  
	for (int i=0; i< height; i++ ) {
		for (int j=0; j<width; j++ ) {
// 			val = ;
			newVal = grid[i][j];
			for (int ii=0; ii<3; ii++) {
				dy = DX[ii];
				for (int jj=0; jj<3; jj++) {
                    dx = DX[ii];
                    new_i = (i + dy + height) % height;
                    new_j = (j + dx + width) % width;
                    multiplier = window[ii][jj];
                    newGrid[new_i][new_j] += newVal * multiplier;
				}
			}
		}
	}

	return newGrid;
}
