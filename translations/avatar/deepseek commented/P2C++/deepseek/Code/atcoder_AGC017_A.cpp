#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the binomial coefficient
double combi(int N, int K) {
    double a = 1;
    // Calculate the product part of the binomial coefficient
    for (int i = 0; i < K; ++i) {
        a *= N - i;
    }
    // Calculate the division part of the binomial coefficient
    for (int j = 0; j < K; ++j) {
        a /= j + 1;
    }
    return a;
}

int main() {
    int N, P;
    cin >> N >> P;

    vector<int> lis;
    int temp;
    while (cin >> temp) {
        lis.push_back(temp);
    }

    // Create a new vector where each element is the remainder when divided by 2
    vector<int> ls;
    for (int a : lis) {
        ls.push_back(a % 2);
    }

    // Count the number of 1s and 0s in the vector
    int one = 0, zero = 0;
    for (int l : ls) {
        if (l == 1) ++one;
        else ++zero;
    }

    // Initialize variables to store the number of patterns
    double pattern_a = 0, pattern_b = 0;

    // Calculate the number of patterns with `j` zeros using the combi function
    for (int j = 0; j <= zero; ++j) {
        pattern_b += combi(zero, j);
    }

    // Initialize time to 0 for the while loop
    int time = 0;

    // Calculate the number of patterns with `time` ones, considering the parity with P
    while (time <= one) {
        if (time % 2 == P) {
            pattern_a += combi(one, time);
        }
        ++time;
    }

    // Print the result as an integer by multiplying pattern_a and pattern_b
    cout << static_cast<int>(pattern_a * pattern_b) << endl;

    return 0;
}
