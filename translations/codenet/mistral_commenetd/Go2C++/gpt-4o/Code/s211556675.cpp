#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// I/O
class Scanner {
public:
    Scanner() {
        // No specific initialization needed for cin
    }

    string nextStr() {
        string s;
        cin >> s; // Read the next token from the input
        return s; // Return the token as a string
    }

    int nextInt() {
        return stoi(nextStr()); // Convert the next string to an integer
    }

    double nextFloat() {
        return stod(nextStr()); // Convert the next string to a floating-point number
    }

    vector<int> nextIntSlice(int n) {
        vector<int> res(n); // Create a vector of integers with the given length
        for (int i = 0; i < n; i++) {
            res[i] = nextInt(); // Read and assign the next integer to the current index in the vector
        }
        return res; // Return the vector of integers
    }

    vector<double> nextFloatSlice(int n) {
        vector<double> res(n); // Create a vector of floating-point numbers with the given length
        for (int i = 0; i < n; i++) {
            res[i] = nextFloat(); // Read and assign the next floating-point number to the current index in the vector
        }
        return res; // Return the vector of floating-point numbers
    }
};

// Arithmetic
int max(int a, int b, int c) {
    return std::max({a, b, c}); // Return the maximum value among a, b, and c
}

int pow(int x, int y) {
    int res = 1; // Initialize the result to 1
    for (int i = 0; i < y; i++) { // Iterate y times
        res *= x; // Multiply the result by x
    }
    return res; // Return the result
}

// Main function
int main() {
    Scanner sc; // Initialize a new Scanner

    // Read input values
    int A = sc.nextInt(), B = sc.nextInt(), C = sc.nextInt(), K = sc.nextInt();

    // Find the maximum value among A, B, and C
    int ma = max(A, B, C);

    // Calculate the rest of the numbers that need to be multiplied by 2 to reach or exceed K
    int rest = 0;
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }

    // Calculate the final answer
    int answer = pow(ma, K) + rest;

    // Write the answer to the output
    cout << answer << endl; // Output the answer

    return 0; // Return success
}

// <END-OF-CODE>
