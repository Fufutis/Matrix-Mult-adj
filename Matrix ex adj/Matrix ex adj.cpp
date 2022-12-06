#include<iostream>						//mtrx[row][col][0] will be the first input
using namespace std;					//mtrx[row][col][1] will be the second input				
const int row = 10;						//mtrx[row][col][2] will be the output
const int col = 10;						
int main() {
	int rows, cols, sum = 0, prio;
	int mtrx[row][col][3];               
	cout << "Enter the number of rows = "; cin >> rows;						//even though we have row and col as constant they exist to fill the requirement of an array
	cout << "Enter the number of column = "; cin >> cols;					//here we give the actual size of the matrix array
	cout << "\nEnter the numbers for a " << rows << " X " << cols << " matrix " << endl;
	if (rows == cols) {														//if rows and cols are the same there wont be any need of adjusting 
		for (int z = 0; z < 2; z++) {										//z acts as a layer counter x y z
			for (int x = 0; x < rows; x++) {
				for (int y = 0; y < cols; y++) {
					cin >> mtrx[x][y][z];									//if z is 0 u input the first matrix then z turns into 1 and u input the second matrix
				}
			}
			if (z == 0) {													//while inputting a message will appear when you are done with the first matrix
				cout << "\nEnter the numbers for the second " << rows << " X " << cols << " matrix " << endl;
			}
		}
	}
	else {																	//this is when the rows and cols are not the same like 2x3 this will run									
		for (int x = 0; x < rows; x++) {									//didnt loop z<2 like before because i want matrix one to be the opposite array range
			for (int y = 0; y < cols; y++) {								//so if we give 2x3 the other matrix will be 3x2 
				cin >> mtrx[x][y][0];										
			}
					
		}
		cout << "\nEnter the numbers for the second " << cols  << " X " << rows  << " matrix " << endl;
		for (int x = 0; x < cols; x++) {									//like i said about the opposite array range we set the x as cols and y as rows
			for (int y = 0; y < rows; y++) {
				cin >> mtrx[x][y][1];	
			}
		}
	}
	if (rows==cols) {														//the proccess for the multiplication and output for the matrixes
		for (int z = 0; z < 2; z++) {							
			for (int x = 0; x < rows; x++) {
				for (int y = 0; y < cols; y++) {
					mtrx[x][y][2] = 0;
					for (int r = 0; r < rows; r++) {									
						mtrx[x][y][2] += mtrx[x][r][0] * mtrx[r][y][1];		//self note: more col less outputs more rows more outputs 2x3=2x2 || 3x2=3x3
					}
				}
			}
		}
		cout << "\nMultiplication Result of Two Given Matrix is:\n";		//this is the end if rows and cols 
		for (int x = 0; x < rows; x++) {
			for (int y = 0; y < rows; y++) {
				cout << mtrx[x][y][2] << " ";
			}
			cout << endl;
		}
	}
	else if (rows >= cols) {
		prio = rows;
		for (int z = 0; z < 2; z++) {							//the proccess for the multiplication and output to mtrx 2
			for (int x = 0; x < prio; x++) {
				for (int y = 0; y < prio; y++) {
					mtrx[x][y][2] = 0;
					for (int r = 0; r < cols; r++) { // check this
						mtrx[x][y][2] += mtrx[x][r][0] * mtrx[r][y][1];
					}
				}
			}
		}
		cout << "\nMultiplication Result of Two Given Matrix is:\n";
		for (int x = 0; x < prio; x++) {
			for (int y = 0; y < prio; y++) {
				cout << mtrx[x][y][2] << " ";
			}
			cout << endl;
		}
	}
	else {
		prio = rows;
		for (int z = 0; z < 2; z++) {							//the proccess for the multiplication and output to mtrx 2
			for (int x = 0; x < prio; x++) {
				for (int y = 0; y < prio; y++) {
					mtrx[x][y][2] = 0;
					for (int r = 0; r < cols; r++) { // check this
						mtrx[x][y][2] += mtrx[x][r][0] * mtrx[r][y][1];
					}
				}
			}
		}
		cout << "\nMultiplication Result of Two Given Matrix is:\n";
		for (int x = 0; x < prio; x++) {
			for (int y = 0; y < prio; y++) {
				cout << mtrx[x][y][2] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
//2 3 2 3 4 2 4 1 3 2 1 4 3 2