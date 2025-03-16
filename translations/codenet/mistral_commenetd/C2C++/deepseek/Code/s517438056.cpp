#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

// Declare variables
int N, D, i, j, k = 0, n = 0;
double l;
int** matrix;

int main() {
	// Read the number of rows and columns from the user
	cout << "Enter the number of rows and columns: ";
	cin >> N >> D;

	// Allocate memory for the 2D matrix
	matrix = (int**)malloc(sizeof(int*)* N);
	for (i = 0; i < N; i++){
		matrix[i] = (int*)malloc(sizeof(int) * D);
	}

	// Read the elements of the matrix from the user
	cout << "Enter the elements of the matrix:\n";
	for (i = 0; i < N; i++) {
		cout << "Row " << i + 1 << ": ";
		for (j = 0; j < D; j++) {
			cin >> matrix[i][j];
		}
	}

	// Calculate the number of identical rows
	k = 0;
	for (i = 0; i < N - 1; i++) {
		for (j = i + 1; j < N; j++) {
			int m = 0; // Initialize the variable m to 0
			for (n = 0; n < D; n++) {
				// Calculate the difference between the corresponding elements of two rows and square it
				m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]);
			}
			// Calculate the square root of the sum of squared differences
			l = sqrt(m);
			// If the square root is an integer, increment the counter k
			if (ceil(l) == floor(l)) k++;
		}
	}

	// Print the result
	cout << k << endl;

	// Free the allocated memory
	for (i = 0; i < N; i++) {
		free(matrix[i]);
	}
	free(matrix);

	return 0;
}
