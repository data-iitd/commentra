#include <bits/stdc++.h>
using namespace std;

// Define a constant for modulo operations
const int mod = 1000000007;

// Read the integer k from input
int k = atoi(stdin.readline().strip().c_str());

// Initialize a variable to hold the current value of t
int t = 0;

// Loop through numbers from 1 to k
for (int i = 1; i <= k; i++) {
    // Update t by appending a '7' at the end and taking modulo k
    t = (t % k) * 10 + 7;
    
    // Check if the current value of t is divisible by k
    if (t % k == 0) {
        printf("%d\n", i);  // Print the current index if divisible
        break;
    }
}

// If no index was found, print -1
if (i > k) printf("-1\n");

// 