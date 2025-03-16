
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

// Define a function to calculate the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    return b == 0? a : gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Use accumulate() from numeric and gcd() from this program to calculate the GCD of all integers in the vector A
    int gcd = accumulate(A.begin(), A.end(), A[0], gcd);

    cout << gcd << endl;

    return 0;
}

