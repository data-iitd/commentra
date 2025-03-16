#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Read the value of N
    long long N;
    cin >> N;

    // Initialize min to 0 and find the minimum of the first five inputs
    long long min = 0;
    for (int i = 0; i < 5; i++) {
        long long input;
        if (i == 0) {
            cin >> min;
        } else {
            cin >> input;
            min = std::min(min, input);
        }
    }

    // Calculate the result and print it
    cout << static_cast<long long>(ceil(static_cast<double>(N) / min)) + 4 << endl;

    return 0;
}

// <END-OF-CODE>
