

#include <iostream>

using namespace std;

int main() {
    // Initialize a variable `T` with the value of 100000000
    long T = 100000000;

    // Initialize a variable `S` with the value of 2
    long S = 2;

    // Initialize a variable `q` with the value of 3
    long q = 3;

    // Initialize a variable `previous` with the value of `S`
    long previous = S;

    // Initialize a variable `answer` with the value of 0
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

    // End the program
    return 0;
}

