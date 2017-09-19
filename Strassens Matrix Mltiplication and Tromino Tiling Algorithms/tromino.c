#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int global = 0;
void trominoTile(int board_size, int missing_x_values, int missing_y_values, int x_board, int y_board, int size, int (*matrix)[size]);
// print matrix
void printMatrix(int coloumn, int (*ptr_arr)[coloumn]) {
	int i = 0,j = 0;
	while(i < coloumn) {
		j = 0;
		while(j < coloumn) {
			if(ptr_arr[i][j]==(-1)) {
				printf("X\t");
			} else {
				printf("%d\t", ptr_arr[i][j]);
			}
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
}
//main function
int main(int argc, char *args[]){
	srand((unsigned)time( NULL ));

	//check board size
	if(atoi(args[1]) < 1) {
		printf("No Support for this input...!!!\n");
	}else{
		int board_size = pow(2, atoi(args[1]));
		int i = 0, j = 0, x, y;
		global = 0;
		x= atoi(args[2]);
		y= atoi(args[3]);
		if(x >=board_size && y>=board_size) {
			printf("Invalid Input\n");
			exit(0);
		}
		int matrix[board_size][board_size];
		while(i < board_size)  {
			while(j < board_size) {
				matrix[i][j] = 0;
				j++;
			}
			i++;
		}
		matrix[x][y] = -1; // adding the random hole into the matrix
		trominoTile(board_size, x, y, 0, 0, board_size, matrix); // calling the trominoTile function
		printMatrix(board_size, matrix);
	}
	return 0;
}

//tromino function
void trominoTile(int board_size, int missing_x_values, int missing_y_values, int x_board, int y_board, int size, int (*matrix)[size]){ // trominoTile implemenation
	if(board_size == 2) {
		global++;
		int i = x_board;
		while(i < (x_board+board_size)) {
			int j = y_board;
			while(j < (y_board + board_size)) {
				if(!(i == missing_x_values && j == missing_y_values)) {
					matrix[i][j] = global;
				}
				j++;
			}
			i++;
		}
		return;
	}
	global++;
	int half_size = board_size / 2, x_center, y_center;
	int urx, ury, ulx, uly, lrx, lry, llx, lly;
	x_center = x_board + half_size;
	y_center = y_board + half_size;

	if(missing_x_values < x_center && missing_y_values < y_center) {
		matrix[x_center - 1][y_center] = matrix[x_center][y_center - 1] = matrix[x_center][y_center] = global;

		ulx = missing_x_values;
		uly = missing_y_values;

		urx = x_center - 1;
		ury = y_center;

		llx = x_center;
		lly = y_center - 1;

		lrx = x_center;
		lry = y_center;

	} else if(missing_x_values < x_center && missing_y_values >= y_center) {

		matrix[x_center - 1][y_center - 1] = matrix[x_center][y_center - 1] = matrix[x_center][y_center] = global;

		ulx = x_center - 1;
		uly = y_center - 1;

		urx = missing_x_values;
		ury = missing_y_values;

		llx = x_center;
		lly = y_center - 1;

		lrx = x_center;
		lry = y_center;

	} else if(missing_x_values >= x_center && missing_y_values < y_center) {

		matrix[x_center - 1][y_center - 1] = matrix[x_center - 1][y_center] = matrix[x_center][y_center] = global;

		ulx = x_center - 1;
		uly = y_center - 1;

		urx = x_center - 1;
		ury = y_center;

		llx = missing_x_values;
		lly = missing_y_values;

		lrx = x_center;
		lry = y_center;

	} else if(missing_x_values >= x_center && missing_y_values >= y_center) {
		matrix[x_center - 1][y_center - 1] = matrix[x_center - 1][y_center] = matrix[x_center][y_center - 1] = global;

		ulx = x_center - 1;
		uly = y_center - 1;

		urx = x_center - 1;
		ury = y_center;

		llx = x_center;
		lly = y_center - 1;

		lrx = missing_x_values;
		lry = missing_y_values;

	}
	//4 recursive calls
	trominoTile(half_size, ulx, uly, x_board, y_board, size, matrix);
	trominoTile(half_size, urx, ury, x_board, y_board + half_size, size, matrix);
	trominoTile(half_size, llx, lly, x_board + half_size, y_board, size, matrix);
	trominoTile(half_size, lrx, lry, x_board + half_size, y_board + half_size, size, matrix);
}
