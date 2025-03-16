#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    int N, L, R, QL, QR;
    cin >> N >> L >> R >> QL >> QR; // Number of elements
    
    // Read the number of elements (N) and the values for L, R, QL, QR
    int W[N]; // Array to store weights
    int sum[N + 1]; // Prefix sum array
    
    // Read weights and compute the prefix sum
    for (int n = 0; n < N; n++) {
        cin >> W[n]; // Read weight for each element
        sum[n + 1] = sum[n] + W[n]; // Update prefix sum
    }
    
    // Initialize a variable to track the minimum cost
    long min = LONG_MAX; // Start with the maximum possible value
    
    // Iterate over possible counts of elements assigned to the left side
    for (int firstR = 0; firstR <= N; firstR++) {
        int lCount = firstR; // Count of elements on the left
        int rCount = N - lCount; // Count of elements on the right
        
        // Calculate the candidate cost based on current left and right counts
        long cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R;
        
        // Calculate excess counts for left and right
        int llCount = max(0, lCount - rCount - 1); // Excess left count
        int rrCount = max(0, rCount - lCount - 1); // Excess right count
        
        // Add additional costs for excess elements
        cand += llCount * QL; // Add cost for excess left elements
        cand += rrCount * QR; // Add cost for excess right elements
        
        // Update the minimum cost found
        min = min(cand, min); // Keep track of the minimum cost
    }
    
    // Output the minimum cost
    cout << min << endl; // Print the result
    
    return 0;
}

