/* Here in the .cpp you should define and implement everything declared in the .h file.
 */

#include "maze.h"


void get_identity(string &my_id)
{
	my_id = "jpgdg6";
}


string * build_matrix(int rows)
{
	string *arr = new string[rows];
	return arr;
}


void fill_matrix(string *matrix, int rows)
{
	cin.ignore();
	for(int i = 0; i < rows; i++) {
		string line;
		getline(cin, line);
		matrix[i] = line;
	}
}


void print_matrix(string *matrix, int rows)
{
	for(int i = 0; i < rows; i++)
		cout << matrix[i] << endl;
}


void delete_matrix(string *&matrix)
{
	delete []matrix;
	matrix = nullptr;
}


void find_start(string *matrix, int rows, int &row, int &col)
{
	for(int r = 0; r < rows; r++) {
		char c;
		int index = 0;
		while ((c = matrix[r][index])) {
			if (matrix[r][index] == 'N') {
				row = r;
				col = index;
			}
			index++;
		}
	}
}


bool find_exit(string *matrix, int row, int col)
{	
	string directions[4] = {"NORTH", "SOUTH", "EAST", "WEST"};
	if (!at_end(matrix, row, col)) { // If we are NOT at the end, then
		if(!(matrix[row][col] == 'N')) matrix[row][col] = '@'; // set our position to @ sign (if we aren't at the beginning)
		for(int i = 0; i < 4; i++) { // And explore all directions
			if (directions[i] == "NORTH" && valid_move(matrix, row, col, "NORTH")) { // If we're looking north and it's a blank or an E
				if (find_exit(matrix, row-1, col)) return true;
			} else if (directions[i] == "EAST" && valid_move(matrix, row, col, "EAST")) { // If we're looking east and it's a blank or an E
				if (find_exit(matrix, row, col+1)) return true;
			} else if (directions[i] == "SOUTH" && valid_move(matrix, row, col, "SOUTH")) { // If we're looking south and it's a blank or an E
				if (find_exit(matrix, row+1, col)) return true;
			} else if (directions[i] == "WEST" && valid_move(matrix, row, col, "WEST")) { // If we're looking west and it's a blank or an E
				if (find_exit(matrix, row, col-1)) return true;
			}
		}
	} else { // Otherwise return true
		return true;
	}
	if (!(matrix[row][col] == 'N')) matrix[row][col] = ' '; // When backtracking, reset the position
	return false;
}


bool at_end(string *matrix, int row, int col)
{
	if (matrix[row][col] == 'E') return true;
	return false;
}


bool valid_move(string *matrix, int row, int col, string direction)
{
	if (direction == "NORTH") row--;
	else if (direction == "SOUTH") row++;
	else if (direction == "EAST") col++;
	else if (direction == "WEST") col--;
	if (matrix[row][col] == ' ' || matrix[row][col] == 'E') return true;
	return false;
}

