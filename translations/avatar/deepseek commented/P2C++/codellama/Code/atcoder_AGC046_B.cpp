
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
    int A, B, C, D;
    int m = 998244353;
    cin >> A >> B >> C >> D;

    // Initialize a 2D vector d with dimensions (C+1) x (D+1), filled with zeros
    vector<vector<int>> d(C+1, vector<int>(D+1, 0));

    // Set the starting point for our calculations
    d[A][B] = 1;

    // Iterate over the range from A to C for the rows and from B to D for the columns
    for (int i = A; i <= C; i++) {
        for (int j = B; j <= D; j++) {
            // Update the value of d[i][j] based on its neighboring cells and some arithmetic operations
            d[i][j] += (d[i][j-1] * i + d[i-1][j] * j - d[i-1][j-1] * (i-1) * (j-1)) % m;
        }
    }

    // Print the value at the bottom-right corner of the array
    cout << d[C][D] << endl;

    return 0;
}

