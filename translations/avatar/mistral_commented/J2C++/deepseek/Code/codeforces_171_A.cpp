#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Function for reversing a number
int reverse(int n) {
    // Base case for numbers less than 10
    if (n < 10)
        return n * 10;

    // Initializing variables
    int t = n, r = 0;

    // Reversing the number
    while (t > 0) {
        // Adding the digit to the reversed number
        r = (r * 10) + t % 10;

        // Moving to the next digit
        t = t / 10;
    }

    // Returning the reversed number
    return r;
}

int main() {
    // Reading input for number of test cases
    int n, m;
    cin >> n >> m;

    // Calling reverse function for m and adding it to n
    int t = reverse(m);
    cout << t + n << endl;

    return 0;
}
