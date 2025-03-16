// Importing necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a static inner class FastReader for reading input
class FastReader {
    private:
        FILE *br;
        char *str;
        char *token;

    public:
        // Constructor for FastReader
        FastReader() {
            br = fopen("input.txt", "r");
        }

        // Method for reading next token
        char *next() {
            while (str == NULL || token == NULL) {
                str = fgets(str, 1000, br);
                token = strtok(str, " ");
            }
            return token;
        }

        // Methods for reading specific types of input
        int nextInt() {
            return atoi(next());
        }

        long nextLong() {
            return atol(next());
        }

        double nextDouble() {
            return atof(next());
        }

        char *nextLine() {
            char *str = (char *)malloc(sizeof(char) * 1000);
            fgets(str, 1000, br);
            return str;
        }
};

// Main method
int main() {
    // Creating an instance of FastReader
    FastReader sc = FastReader();

    // Reading input for number of test cases
    int n = sc.nextInt();

    // Reading input for number of operations
    int m = sc.nextInt();

    // Calling reverse function for m and adding it to n
    int t = reverse(m);
    printf("%d\n", t + n);
    return 0;
}

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

