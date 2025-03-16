#include <iostream>
using namespace std;

// Function to find a number X raised to the power n such that A * X^n equals B
int task4(int A, int B, int n) {
    // Iterate through all possible values of X from -1000 to 1000
    for (int X = -1000; X <= 1000; X++) {
        // Check if the condition A * X^n equals B is satisfied
        if (A * pow(X, n) == B) {
            // If the condition is satisfied, return the value of X
            return X;
        }
    }
    // If no solution is found, return a message indicating that
    return -1; // Indicating no solution found
}

int main() {
    int A, B, n;
    // Get input values of A, B, and n from the user
    cin >> A >> B >> n;

    // Call the function and print the result
    int result = task4(A, B, n);
    if (result == -1) {
        cout << "No solution" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}

// <END-OF-CODE>
