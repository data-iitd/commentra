#include <iostream>

using namespace std;

int main() {
    // Read input values for k (cost per banana), n (initial amount of money), and w (number of bananas)
    int k, n, w;
    cin >> k >> n >> w;
    
    // Check if k is at least 1 and w is at most 1000
    if (k >= 1 && w <= 1000) {
        // Initialize total cost to zero
        int total = 0;
        
        // Calculate the total cost of buying w bananas
        for (int i = 1; i <= w; i++) {
            total += i * k;  // Cost of each banana increases with its quantity (1*k, 2*k,..., w*k)
        
        // Check if the total cost exceeds the initial amount of money n
        if (total > n) {
            // Print the amount of money needed to buy the bananas
            cout << total - n << endl;
        } else {
            // Print 0 if the initial amount is sufficient to buy the bananas
            cout << 0 << endl;
        }
    }
    
    return 0;
}

