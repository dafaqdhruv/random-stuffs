#include <iostream>
#include <vector>
#include <math.h>
#include <unistd.h>

using namespace std;

int NUM_1 = 0;

bool rowValid(vector<int> temp, int val, int row, int col){

	for(int i = 0; i<9; i++){
		if(temp[row*9+i] == val){

			// cout<<"ROW INVALID with "<< val<<" "<<row<<" "<<i<<"\n";
			if(i != col)	return false;	
		} 
	}
	return true;
}

	
bool colValid(vector<int> temp, int val, int row, int col){

	for(int i = 0; i<9; i++){
		if(temp[i*9+col] == val){

			// cout<<"COL INVALID with "<< val<<" "<<iz<<" "<<col<<"\n";
			if(i != row) 	return false;
		}
	}
	return true;
}

	
bool boxValid(vector<int> temp, int val, int row, int col){

	//
	// BOX NUMBER FORMULA /*(row - row%3 + col/3)*/
	//

	int r = row - row%3;
	int c = col - col%3;

	for(int i = r; i<r+3; i++){
		for(int j = c; j<c+3; j++){
			if(temp[i*9 + j] == val) {
				// cout<<"BOX INVALID with "<< val<<" "<<row<<" "<<col<<"\n";
				if( i!= row && j!=col)	return false;
			}
		}
	}
	return true;

}



void reset_pos (vector<int>& grid, int temp){

	grid[temp] = -1;
	NUM_1++;
	return;
}

void prntGrid(vector<int> A){
	
		for( int i = 0 ; i < 9; i++){
			for(int j = 0; j < 9; j++){

				if(A[i*9+ j] != -1)
					cout<<A[i*9+ j]<<" ";
				else cout<<"  ";


				if((j+1)%3 ==0 && j!=8 )
					cout<<"| ";
			}
			cout<<"\n";
			if((i+1)%3 == 0 && i!=8){
				for(int i =0; i< 22; i++){
					cout<<"-";
				}
				cout<<"\n";
			}
		}

		cout<<"\n\n";
}

void fetch(vector<int> grid, int curr_R, int curr_C, int& new_R, int& new_C) {

	int temp = curr_R*9 + curr_C +1;
	if(grid[temp-1] == -1){
		new_C = curr_C;
		new_R = curr_R;
	}

	else{
		while(grid[temp] != -1 && temp <81){
			temp++;
		}
		
		new_R = temp/9;
		new_C = temp%9;
	}
}

void backtrack( int row, int col, vector<int>& Placed, vector<int>& Final){

	int temp = row*9+col;


					
	for(int val = 1; val<10; val++){

					Placed[temp] = val;
					NUM_1--;


					// cout<<"\033[H\033[J";
					// prntGrid(Placed);
					// usleep(25000);

				// IF NUMBER VALID, PLACE NUMBER AND RECURSE WITH THESE PLACEMENTS 
				if(colValid(Placed, val, row, col) && rowValid(Placed, val, row, col) && boxValid(Placed, val, row, col)){
						

					// WIN CONDITION
					if(!NUM_1){
							Final  = Placed;
							return;
						
					}

					// CONTINUE CONDITION
					else {

						int temp_r, temp_c;
						fetch(Placed, row, col, temp_r, temp_c);
						backtrack(temp_r, temp_c, Placed, Final);
					}
				}


				reset_pos(Placed, temp);
	}

}



void getGrid(vector<int>& A){

	int in = 0, row,col;
	cout<<"Please enter atleast 17 clues for a unique solution.\nPress 69 to advance.\n";

	while(1){

		prntGrid(A);
		cout<<"Row : ";
		cin>>row;
		cout<<"Col : ";
		cin>>col;
		cout<<"Val : ";
		cin>>in;

		if(in == 69) break;

		A[row*9+col] = in;
	}
}

int main(){

	vector<int> grid(81,-1);
	vector<int> Placed(81,-1);
	vector<int> Final(81,-1);

	vector<int> tempGrid = {
							-1,  7, -1,   -1, -1,  8,   -1, -1, -1,
							 1, -1,  5,   -1, -1, -1,   -1,  3, -1,
							-1, -1, -1,   -1, -1, -1,    2,  5,  7,

							-1, -1,  3,    7, -1, -1,   -1, -1, -1,
							-1,  6, -1,   -1,  5, -1,   -1,  9, -1,
							-1, -1, -1,   -1, -1,  9,    1, -1, -1,

							 7,  4,  2,   -1, -1, -1,   -1, -1, -1,
							-1,  3, -1,   -1, -1, -1,    6, -1,  5,
							-1, -1, -1,    4, -1, -1,   -1,  1, -1,
							};

	vector<int> tempGrid2 = {
								-1, -1, -1,   -1, -1, -1,   -1, -1, -1,
								-1, -1, -1,   -1, -1, -1,   -1, -1, -1,
								-1, -1, -1,   -1, -1, -1,   -1, -1, -1,

								-1, -1, -1,   -1, -1, -1,   -1, -1, -1,
								-1, -1, -1,   -1, -1, -1,   -1, -1, -1,
								-1, -1, -1,   -1, -1, -1,   -1, -1, -1,

								-1, -1, -1,   -1, -1, -1,   -1, -1, -1,
								-1, -1, -1,   -1, -1, -1,   -1, -1, -1,
								-1, -1, -1,   -1, -1, -1,   -1, -1, -1,
								};



	vector<int> tempGrid3 = {
								 7, -1,  8,   -1, -1,  1,   -1, -1,  3,
								-1, -1, -1,   -1,  5,  3,   -1,  6, -1,
								-1,  1, -1,   -1, -1, -1,   -1, -1, -1,

								-1, -1,  7,   -1, -1, -1,   -1, -1,  2,
								 3, -1, -1,    9,  4,  7,   -1, -1,  8,
								 5, -1, -1,   -1, -1, -1,    9, -1, -1,

								-1, -1, -1,   -1, -1, -1,   -1,  8, -1,
								-1,  9, -1,    1,  7, -1,   -1, -1, -1,
								 8, -1, -1,    3, -1, -1,    4, -1,  6,
								};


	// getGrid(grid);
	Placed = tempGrid;

	for(int i =0; i<81; i++){
		if(Placed[i]==-1)	NUM_1++;
	}

	cout<<"Input sudoku : \n";
	prntGrid(Placed);
	cout<<NUM_1<<" ONES IN THIS GRID\n";

	int r, c;
	fetch(Placed, 0,0,r,c);
	backtrack(r,c, Placed,Final);

	// cout<<"\033[H\033[J";
	cout<<"FINAL SOLUTION\n\n\n";
	prntGrid(Final);
	return 0;
}