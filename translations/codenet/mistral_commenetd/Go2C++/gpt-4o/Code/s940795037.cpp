// Including necessary headers
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

// Function to read an integer from standard input
int readInt() {
    int x;
    cin >> x;
    return x;
}

int main() {
    // Reading the first integer from the standard input
    int n = readInt();
    // Initializing the answer variable
    double ans = 0.0;

    // Iterating through the given number of integers
    for (int i = 0; i < n; i++) {
        // Reading the next integer from the standard input
        int tmp;
        cin >> tmp;
        // Adding the reciprocal of the current integer to the answer
        ans += 1.0 / tmp;
    }

    // Printing the final answer
    cout << fixed << setprecision(10) << 1.0 / ans << endl;

    return 0;
}

// <END-OF-CODE>
