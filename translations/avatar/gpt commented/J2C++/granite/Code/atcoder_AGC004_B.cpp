
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Create a Scanner object to read input from the console
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cin.exceptions(std::ios::badbit);
    
    // Read the number of elements (N) and a long value (x) from input
    int N;
    long x;
    std::cin >> N >> x;
    
    // Initialize a vector to store the prime numbers
    std::vector<long> srimeList(N);
    
    // Read N long values into the srimeList
    for (int i = 0; i < N; i++) {
        std::cin >> srimeList[i];
    }
    
    // Initialize a 2D vector to store costs
    std::vector<std::vector<long>> costList(N, std::vector<long>(N));
    
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
    std::vector<long> result(N);
    
    // Calculate the result for each index based on the costs and the value of x
    for (int i = 0; i < N; i++) {
        result[i] = i * x + std::accumulate(costList[i].begin(), costList[i].end(), 0L);
    }
    
    // Print the minimum value from the result vector
    std::cout << *std::min_element(result.begin(), result.end()) << std::endl;
    
    return 0;
}
