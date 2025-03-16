#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read four integers from input
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Check conditions to determine the output
    if (c > b) {
        // If c is greater than b, output 0
        cout << 0 << endl;
    } else if (a > d) {
        // If a is greater than d, output 0
        cout << 0 << endl;
    } else if (a < c) {
        // If a is less than c, calculate and output the difference
        cout << min(b, d) - c << endl;
    } else {
        // Create a vector to hold the four integers
        vector<int> l = {a, b, c, d};

        // Sort the vector to find the second largest and third largest values
        sort(l.begin(), l.end());

        // Output the difference between the second largest and third largest values
        cout << l[2] - l[1] << endl;
    }

    return 0;
}

// <END-OF-CODE>
