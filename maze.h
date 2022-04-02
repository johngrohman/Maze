#include <iostream>

#ifndef MAZE
#define MAZE

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;

/**
Creates a dynamically allocated array of std::string elements.
Returns a pointer to that array.
**/
string * build_matrix(int rows);


/**
Fills the matrix with one line per string in the array.
**/
void fill_matrix(string *matrix, int rows);


/**
Print the matrix as in the sample_output.txt. 
**/
void print_matrix(string *matrix, int rows);


/**
Delete the dynamically allocated array of strings.
**/
void delete_matrix(string *&matrix);


/**
Finds the starting position of Niobe.
**/
void find_start(string *matrix, int rows, int &row, int &col);


/**
Recursive function that finds the solution if there is one
**/
bool find_exit(string *matrix, int row, int col);


/**
Returns true if row and col are the final exit location,
and false otherwise.
**/
bool at_end(string *matrix, int row, int col);


/**
Returns true if the position indexed by row and col when incremented in direction is a valid move, and false otherwise.
**/
bool valid_move(string *matrix, int row, int col, string direction);

#endif

