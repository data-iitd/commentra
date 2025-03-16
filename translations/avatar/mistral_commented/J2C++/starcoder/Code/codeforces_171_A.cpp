#include <bits/stdc++.h>
using namespace std;

// Defining a static inner class FastReader for reading input
class Main {
    static class FastReader {
        public :
        FastReader() {
            // Reading input from stdin
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        }

        // Method for reading next token
        string next() {
            // Declaring a string for storing the input
            string s;

            // Keeping loop until we get a valid input
            while (getline(cin, s)) {
                // Returning the input if it is valid
                if (is_valid(s))
                    return s;
            }

            // Returning an empty string if input is invalid
            return "";
        }

        // Method for checking if the input is valid
        bool is_valid(string s) {
            // Returning false if the input is empty
            if (s.length() == 0)
                return false;

            // Returning true if the input is valid
            return true;
        }

        // Methods for reading specific types of input
        int nextInt() {
            // Declaring a variable to store the input
            int n;

            // Keeping loop until we get a valid input
            while (cin >> n) {
                // Returning the input if it is valid
                if (is_valid(n))
                    return n;
            }

            // Returning 0 if input is invalid
            return 0;
        }

        long long nextLong() {
            // Declaring a variable to store the input
            long long n;

            // Keeping loop until we get a valid input
            while (cin >> n) {
                // Returning the input if it is valid
                if (is_valid(n))
                    return n;
            }

            // Returning 0 if input is invalid
            return 0;
        }

        double nextDouble() {
            // Declaring a variable to store the input
            double n;

            // Keeping loop until we get a valid input
            while (cin >> n) {
                // Returning the input if it is valid
                if (is_valid(n))
                    return n;
            }

            // Returning 0.0 if input is invalid
            return 0.0;
        }

        string nextLine() {
            // Declaring a string for storing the input
            string s;

            // Keeping loop until we get a valid input
            while (getline(cin, s)) {
                // Returning the input if it is valid
                if (is_valid(s))
                    return s;
            }

            // Returning an empty string if input is invalid
            return "";
        }
    }

    // Main method
    public :
    static void main(string[] args) {
        // Creating an instance of FastReader
        FastReader sc = new FastReader();

        // Reading input for number of test cases
        int n = sc.nextInt();

        // Reading input for number of operations
        int m = sc.nextInt();

        // Calling reverse function for m and adding it to n
        int t = reverse(m);
        cout << t + n << endl;
    }

    // Function for reversing a number
    public :
    static int reverse(int n) {
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
}

