#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Read a long integer N from user input
    long long N;
    cin >> N;

    // Initialize a variable to hold the minimum value
    long long min = 0;

    // Loop to read five long integers and find the minimum
    for (int i = 0; i < 5; i++) {
        long long value;
        cin >> value;
        // For the first iteration, directly assign the value to min
        if (i == 0) {
            min = value;
        } else {
            // For subsequent iterations, update min if a smaller value is found
            min = std::min(min, value);
        }
    }

    // Calculate the result by dividing N by min, rounding up, and adding 4
    long long result = static_cast<long long>(ceil(static_cast<double>(N) / min)) + 4;
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
