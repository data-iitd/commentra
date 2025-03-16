#include <iostream>

using namespace std;

int main() {
    // Read the first integer `T` from the input
    int T;
    cin >> T;

    // Read the second integer `S` from the input
    int S;
    cin >> S;

    // Read the third integer `q` from the input
    int q;
    cin >> q;

    // Initialize the variable `previous` with the value of `S`
    long long previous = S;

    // Initialize the variable `answer` with the value of 0
    int answer = 0;

    // Start a while loop that continues as long as `previous` is less than `T`
    while (previous < T) {
        // Increment the value of `answer` by 1
        answer++;

        // Multiply the value of `previous` by `q`
        previous *= q;
    }

    // Print the value of `answer` to the standard output stream
    cout << answer << endl;

    return 0;
}

// <END-OF-CODE>
