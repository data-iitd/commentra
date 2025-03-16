
#include <iostream>
#include <cmath>

int main() {
    int n, d;
    
    // Read the number of points (n) and the number of dimensions (d)
    std::cin >> n >> d;
    
    // Declare a 2D array to store the coordinates of the points
    int point[n + 1][d + 1];
    
    // Input the coordinates for each point
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= d; j++) {
            std::cin >> point[i][j];
        }
    }
    
    // Initialize a counter for the number of pairs with integer distance
    int count = 0;
    
    // Iterate through all unique pairs of points
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            
            // Calculate the squared distance between point i and point j
            int sum = 0;
            for (int k = 1; k <= d; k++) {
                sum = sum + (point[i][k] - point[j][k]) * (point[i][k] - point[j][k]);
            }
            
            // Compute the Euclidean distance
            double kyori = sqrt(sum);
            
            // Check if the distance is an integer
            if (ceil(kyori) == floor(kyori)) {
                count++; // Increment the count if the distance is an integer
            }
        }
    }
    
    // Output the total count of pairs with integer distance
    std::cout << count << std::endl;
    
    return 0;
}
