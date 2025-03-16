
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate combinations C(N, K)
double combi(int N, int K) {
    double a = 1;
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
    int N, P;
    cin >> N >> P;

    vector<int> lis(N);
    for (int i = 0; i < N; i++) {
        cin >> lis[i];
    }

    vector<int> ls;
    for (int a : lis) {
        // Append the remainder when divided by 2 (0 for even, 1 for odd)
        ls.push_back(a % 2);
    }

    int one = count(ls.begin(), ls.end(), 1);
    int zero = count(ls.begin(), ls.end(), 0);

    double pattern_a = 0;
    double pattern_b = 0;

    // Calculate the total number of patterns for the even numbers
    for (int j = 0; j <= zero; j++) {
        pattern_b += combi(zero, j);
    }

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
    cout << int(pattern_a * pattern_b) << endl;

    return 0;
}

