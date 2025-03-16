
#include <bits/stdc++.h>
using namespace std;

// Constants definition
const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

// Variables definition and initialization
int N;

int main() {
    // Read the first integer from the standard input
    scanf("%d", &N);

    // Calculate the square root of N
    int sqrtN = sqrt(N);

    // Initialize the minimum number with N
    int min = N;

    // Iterate through all numbers from 1 to the square root of N
    for (int i = 1; i <= sqrtN; i++) {
        // Check if N is divisible by i
        if (N % i!= 0) {
            continue;
        }

        // Calculate the number of divisors of i and N
        int num = i + (N / i) - 2;

        // Update the minimum number if the current number is smaller
        if (num < min) {
            min = num;
        }
    }

    // Print the minimum number
    printf("%d\n", min);

    return 0;
}

