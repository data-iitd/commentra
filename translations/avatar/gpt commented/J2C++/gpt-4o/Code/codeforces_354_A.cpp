#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    // Create a variable to read input from the console
    int N; // Number of elements
    int L; // Cost for left elements
    int R; // Cost for right elements
    int QL; // Additional cost for left excess
    int QR; // Additional cost for right excess
    
    // Read the number of elements (N) and the values for L, R, QL, QR
    cin >> N >> L >> R >> QL >> QR;
    
    // Initialize a vector to hold the weights and a prefix sum vector
    vector<int> W(N); // Vector to store weights
    vector<long long> sum(N + 1, 0); // Prefix sum vector
    
    // Read weights and compute the prefix sum
    for (int n = 0; n < N; n++) {
        cin >> W[n]; // Read weight for each element
        sum[n + 1] = sum[n] + W[n]; // Update prefix sum
    }
    
    // Initialize a variable to track the minimum cost
    long long minCost = numeric_limits<long long>::max(); // Start with the maximum possible value
    
    // Iterate over possible counts of elements assigned to the left side
    for (int firstR = 0; firstR <= N; firstR++) {
        int lCount = firstR; // Count of elements on the left
        int rCount = N - lCount; // Count of elements on the right
        
        // Calculate the candidate cost based on current left and right counts
        long long cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R;
        
        // Calculate excess counts for left and right
        int llCount = max(0, lCount - rCount - 1); // Excess left count
        int rrCount = max(0, rCount - lCount - 1); // Excess right count
        
        // Add additional costs for excess elements
        cand += llCount * QL; // Add cost for excess left elements
        cand += rrCount * QR; // Add cost for excess right elements
        
        // Update the minimum cost found
        minCost = min(cand, minCost); // Keep track of the minimum cost
    }
    
    // Output the minimum cost
    cout << minCost << endl; // Print the result

    return 0;
}

// <END-OF-CODE>
