#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Private nested class for the solution logic
class Solution {
    // Method to solve the problem using the given input and output objects
    private void solve ( InputReader in , PrintWriter out ) {
        int n = in.nextInt(); // Read the number of logs
        int k = in.nextInt(); // Read the number of days

        // Initialize the minimum and maximum possible days
        int min = 1, max = (int) 1e9 + 1000;

        // Binary search to find the minimum day such that the number of days needed to cut the logs is greater than or equal to k
        while (min < max) {
            int mid = (min + max) / 2; // Calculate the middle day
            if (nei(mid, logsLength, k)) // If the number of days needed to cut the logs is greater than or equal to k
                max = mid; // Narrow down the search space to the left
            else
                min = mid + 1; // Narrow down the search space to the right
        }

        // Print the minimum day as the output
        out.println(min);
    }

    // Method to check if the number of days needed to cut the logs of given length is greater than or equal to k
    private boolean nei ( int mid , int [ ] logsLength , int k ) {
        int daysNeeded = 0; // Initialize the days needed to zero

        // Iterate through all the logs and calculate the days needed to cut them
        for (int log : logsLength) {
            daysNeeded += (log + mid - 1) / mid; // Calculate the days needed to cut the current log
            k -= daysNeeded; // Subtract the days needed from the remaining days
            if (k < 0) // If the remaining days are not sufficient to cut all the logs
                return false; // Return false to indicate that the middle day is not the answer
        }

        // If all the logs have been cut, return true to indicate that the middle day is the answer
        return true;
    }
}

// Private nested static class for reading input
class InputReader {
    private FILE *reader; // Initialize FILE pointer object
    private char *tokenizer; // Initialize char pointer to null

    // Constructor to initialize the InputReader object with the given input stream
    private InputReader ( FILE *stream ) {
        reader = stream; // Initialize FILE pointer with the given input stream
        tokenizer = NULL; // Initialize char pointer to null
    }

    // Method to read a string token
    private char *next () {
        while (tokenizer == NULL || *tokenizer == '\0') {
            char *line = NULL; // Initialize char pointer to null
            size_t len = 0; // Initialize length of the line to zero
            ssize_t read = getline(&line, &len, reader); // Read a line from the input
            if (read == -1) throw new RuntimeException(); // If the end of the input is reached, throw an exception
            tokenizer = strtok(line, " \n"); // Initialize char pointer with the first token
        }
        char *token = tokenizer; // Initialize char pointer with the current token
        tokenizer = strtok(NULL, " \n"); // Update char pointer with the next token
        return token; // Return the current token
    }

    // Method to read an integer
    private int nextInt () {
        return atoi(next()); // Parse the current token as an integer
    }

    // Method to read an array of integers
    private int [ ] readArray ( int n ) {
        int [ ] a = malloc(n * sizeof(int)); // Initialize an array of size n
        for (int i = 0; i < n; ++i) // Iterate through all the elements of the array
            a [ i ] = nextInt(); // Read an integer as the next element
        return a; // Return the array
    }
}

// Main method to start the program
int main ( int argc , char *argv [ ] ) {
    FILE *inputStream = stdin; // Initialize FILE pointer to standard input
    FILE *outputStream = stdout; // Initialize FILE pointer to standard output
    InputReader in = new InputReader(inputStream); // Create an InputReader object
    PrintWriter out = new PrintWriter(outputStream); // Create a PrintWriter object
    Solution sol = new Solution(); // Create a Solution object
    sol.solve(in, out); // Call the solve method of Solution object
    out.close(); // Close the PrintWriter object
    return 0;
}

