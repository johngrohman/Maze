#include "maze.h"

int main()
{
	int rows = 1;
	int r;
	int c;
	int i = 0;
	cin >> rows;
	while (rows != 0) {
		string * arr = build_matrix(rows);
		fill_matrix(arr, rows);
		find_start(arr, rows, r, c);
		cout << "Map " << i << " -- " << ((find_exit(arr, r, c)) ? "Solution found:\n" : "No solution found:\n");
		print_matrix(arr, rows);
		cout << endl;
		delete_matrix(arr);
		i++;
		cin >> rows;
	}
	
	
	return 0;
}

