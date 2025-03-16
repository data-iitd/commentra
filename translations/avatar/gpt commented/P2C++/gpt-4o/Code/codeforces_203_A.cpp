#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read input values and split them into a vector
    vector<int> xxs(6);
    for (int i = 0; i < 6; ++i) {
        cin >> xxs[i];
    }

    // Convert the input values to integers
    int x = xxs[0], t = xxs[1], a = xxs[2], b = xxs[3], da = xxs[4], db = xxs[5];

    // Check if the target value x is zero
    if (x == 0) {
        cout << "YES" << endl;  // If x is zero, print "YES" and return
        return 0;
    }

    // Calculate the maximum time available for a and b, constrained by t
    int a_time = min(a / da, t - 1);
    int b_time = min(b / db, t - 1);

    // Iterate through all possible values of i and j within the calculated time limits
    for (int i = 0; i <= a_time; ++i) {
        for (int j = 0; j <= b_time; ++j) {
            // Check if either a or b can be reduced to x by subtracting multiples of da or db
            if (a - da * i == x || b - db * j == x) {
                cout << "YES" << endl;  // If found, print "YES" and return
                return 0;
            }
            // Check if the sum of the remaining values of a and b equals x
            if ((a - da * i) + (b - db * j) == x) {
                cout << "YES" << endl;  // If found, print "YES" and return
                return 0;
            }
        }
    }

    // If no valid combination is found, print "NO"
    cout << "NO" << endl;

    return 0;
}

// <END-OF-CODE>
