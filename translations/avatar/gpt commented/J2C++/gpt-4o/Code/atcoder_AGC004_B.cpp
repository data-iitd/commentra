#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    // Create a variable to read input
    int N;
    long long x;
    
    // Read the number of elements (N) and a long value (x) from input
    std::cin >> N >> x;
    
    // Initialize a vector to store the prime numbers
    std::vector<long long> srimeList(N);
    
    // Read N long values into the srimeList
    for (int i = 0; i < N; i++) {
        std::cin >> srimeList[i];
    }
    
    // Initialize a 2D vector to store costs
    std::vector<std::vector<long long>> costList(N, std::vector<long long>(N));
    
    // Populate the costList with minimum values based on the srimeList
    for (int i = 0; i < N; i++) {
        // Set the first column of costList to the corresponding values from srimeList
        costList[i][0] = srimeList[i];
        // Calculate the minimum costs for each subsequent column
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = std::min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]);
        }
    }
    
    // Initialize a vector to store the final results
    std::vector<long long> result(N);
    
    // Calculate the result for each index based on the costs and the value of x
    for (int i = 0; i < N; i++) {
        long long sum = 0;
        for (int j = 0; j < N; j++) {
            sum += costList[j][i];
        }
        result[i] = i * x + sum;
    }
    
    // Print the minimum value from the result vector
    std::cout << *std::min_element(result.begin(), result.end()) << std::endl;

    return 0;
}

// <END-OF-CODE>
