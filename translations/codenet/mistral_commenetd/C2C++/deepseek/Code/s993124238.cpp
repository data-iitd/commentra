#include <iostream>
#include <cmath>

using namespace std;

// Function declaration for main function
void main(){
	// Declare variables for number of points and their dimensions
	int n, d;

	// Read number of points and their dimensions from the user
	cin >> n >> d;

	// Declare a 2D array 'point' to store the coordinates of each point
	int point[n+1][d+1];

	// Read the coordinates of each point and store them in the 'point' array
	for (int i=1;i<=n ; i++){
		for (int j=1; j<=d; j++){
			cin >> point[i][j];
			// Comment explaining the inner loop
			// Read the j-th coordinate of the i-th point
		}
		// Comment explaining the outer loop
		// Read the i-th row of the 'point' array (i.e., the i-th point's coordinates)
	}

	// Initialize a counter variable 'count' to 0
	int count=0;

	// Iterate through all pairs of points (i, j) where i < j
	for (int i=1; i<=n-1; i++){
		for (int j=i+1; j<=n; j++){
			// Initialize a variable 'sum' to store the sum of the squared differences between the corresponding coordinates of points i and j
			int sum=0;

			// Calculate the sum of the squared differences between the corresponding coordinates of points i and j
			for (int k=1; k<=d; k++){
				sum = sum+ (point[i][k] - point[j][k])*(point[i][k] - point[j][k]);
				// Comment explaining the inner loop
				// Calculate the difference between the k-th coordinate of point i and the k-th coordinate of point j, square it, and add it to the 'sum' variable
			}

			// Calculate the Euclidean distance between points i and j using the 'sum' variable
			double kyori = sqrt(sum);

			// Check if the Euclidean distance is equal to an integer value (i.e., the points are on the same circle)
			if (ceil(kyori) == floor(kyori)){
				// If so, increment the 'count' variable
				count++;
			}
		}
	}

	// Print the final count of pairs of points on the same circle
	cout << count << endl;
}

