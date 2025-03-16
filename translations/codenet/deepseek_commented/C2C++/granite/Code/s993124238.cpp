
#include <iostream>  // Include standard input-output library for input and output operations
#include <cmath>     // Include mathematical library for mathematical functions like sqrt

int main(){
	int n, d;  // Declare integer variables n and d to store the number of points and dimensions
	std::cin >> n >> d;  // Read the values of n and d from the standard input
	
	int point[n+1][d+1];  // Declare a 2D array to store the points with dimensions (n+1) x (d+1)
	
	// Nested loop to read the coordinates of each point from the standard input
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= d; j++){
			std::cin >> point[i][j];
		}
	}
	
	int count = 0;  // Initialize a counter to zero to count the number of integer distances
	
	// Nested loop to calculate the Euclidean distance between each pair of points
	for (int i = 1; i <= n-1; i++){
		for (int j = i+1; j <= n; j++){
			
			int sum = 0;  // Initialize a variable to store the sum of squared differences
			for (int k = 1; k <= d; k++){
				sum = sum + (point[i][k] - point[j][k]) * (point[i][k] - point[j][k]);
			}
			double kyori = std::sqrt(sum);  // Compute the square root of the sum to get the distance
			
			// Check if the distance is an integer by comparing ceil and floor of the distance
			if (std::ceil(kyori) == std::floor(kyori)){
				count++;  // Increment the counter if the distance is an integer
			}
		}
	}
	
	std::cout << count << std::endl;  // Print the final count of integer distances
	
	return 0;  // Return 0 to indicate successful execution of the program
}
