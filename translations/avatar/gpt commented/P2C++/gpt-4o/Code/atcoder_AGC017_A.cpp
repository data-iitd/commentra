#include <iostream>
#include <vector>

using namespace std;

// Function to calculate combinations C(N, K)
long long combi(int N, int K) {
    long long a = 1;
    // Calculate the numerator of the combination formula
    for (int i = 0; i < K; i++) {
        a *= N - i;
    }
    // Calculate the denominator of the combination formula
    for (int j = 0; j < K; j++) {
        a /= j + 1;
    }
    return a;
}

int main() {
    // Read two integers N and P from input
    int N, P;
    cin >> N >> P;

    // Initialize the answer variable
    long long ans = 0;

    // Read a list of integers from input
    vector<int> lis(N);
    for (int i = 0; i < N; i++) {
        cin >> lis[i];
    }

    // Create a vector to hold the parity (0 or 1) of each number
    vector<int> ls(N);
    for (int i = 0; i < N; i++) {
        // Append the remainder when divided by 2 (0 for even, 1 for odd)
        ls[i] = lis[i] % 2;
    }

    // Count the number of 1s (odd numbers) and 0s (even numbers) in the list
    int one = count(ls.begin(), ls.end(), 1);
    int zero = count(ls.begin(), ls.end(), 0);

    // Initialize variables to count patterns
    long long pattern_a = 0;
    long long pattern_b = 0;

    // Calculate the total number of patterns for the even numbers
    for (int j = 0; j <= zero; j++) {
        pattern_b += combi(zero, j);
    }

    // Initialize a variable to track the number of odd numbers used
    int time = 0;

    // Loop through all possible counts of odd numbers used
    while (time <= one) {
        // Check if the current count of odd numbers is congruent to P modulo 2
        if (time % 2 == P) {
            // If it is, add the number of combinations to pattern_a
            pattern_a += combi(one, time);
        }
        time++;
    }

    // Print the final result, which is the product of pattern_a and pattern_b
    cout << pattern_a * pattern_b << endl;

    return 0;
}

// <END-OF-CODE>
