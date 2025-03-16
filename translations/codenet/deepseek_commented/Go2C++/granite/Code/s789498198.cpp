
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    // Read two integers A and B from standard input
    int A, B;
    cin >> A >> B;

    // Check if the sum of A and B is even
    if ((A + B) % 2 == 0) {
        // If even, print the average of A and B
        cout << (A + B) / 2 << endl;
    } else {
        // If not even, print "IMPOSSIBLE"
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

