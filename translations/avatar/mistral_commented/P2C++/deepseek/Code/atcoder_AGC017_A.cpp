#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the factorial of a number
long long fact(int n) {
    long long f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

// Function to calculate the number of combinations of choosing K items from a set of N items
long long combi(int N, int K) {
    long long a = 1;
    for (int i = 0; i < K; i++) {
        a *= (N - i);
        a /= (i + 1);
    }
    return a;
}

int main() {
    int N, P;
    cin >> N >> P;

    vector<int> lis;
    vector<int> ls;
    int a;

    // Read the input values from the user and store them in a list
    for (int i = 0; i < N; i++) {
        cin >> a;
        lis.push_back(a);
    }

    // Initialize an empty list to store the remainder of each input value when divided by 2
    for (int i = 0; i < N; i++) {
        ls.push_back(lis[i] % 2);
    }

    // Calculate the number of 1's and 0's in the list
    int one = 0, zero = 0;
    for (int i = 0; i < N; i++) {
        if (ls[i] == 1) one++;
        else zero++;
    }

    // Initialize two variables to store the pattern values
    long long pattern_a = 0, pattern_b = 0;

    // Calculate the value of pattern_b by summing up the combinations of choosing 0's from the list
    for (int j = 0; j <= zero; j++) {
        pattern_b += combi(zero, j);
    }

    // Calculate the value of pattern_a by summing up the combinations of choosing numbers from the list based on the value of P
    int time = 0;
    while (time <= one) {
        if (time % P == 0) {
            pattern_a += combi(one, time);
        }
        time++;
    }

    // Print the final answer as an integer
    cout << (int)(pattern_a * pattern_b) << endl;

    return 0;
}

