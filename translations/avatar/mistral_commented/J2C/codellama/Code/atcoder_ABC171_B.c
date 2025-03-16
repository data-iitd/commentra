#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Main method to start the program
int main ( int argc , char *argv[] ) {
    // Initialize input and output streams
    FILE *inputStream = stdin;
    FILE *outputStream = stdout;

    // Create InputReader and PrintWriter objects
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);

    // Create Solution object and call its solve method
    Solution sol = new Solution();
    sol.solve(in, out);

    // Close the output stream
    out.close();
}

// Private nested class for solving the problem
class Solution {
    // Method to solve the problem
    private void solve ( InputReader in , PrintWriter out ) {
        // Read input: number of elements n and the number of summands k
        int n = in.ni();
        int k = in.ni();

        // Read input array a of size n
        int* a = (int*)malloc(n * sizeof(int));
        for ( int i = 0 ; i < n ; ++ i ) {
            a[i] = in.ni(); // Read next element of array a
        }

        // Sort the array a in parallel using Arrays.parallelSort()
        qsort(a, n, sizeof(int), compare);

        // Calculate the answer: sum of first k elements of sorted array a
        int ans = 0;
        for ( int i = 0 ; i < k ; ++ i ) {
            ans += a[i];
        }

        // Write the answer to the output stream
        out.println(ans);
    }
}

// Nested static class for reading input
class InputReader {
    // Initialize reader and tokenizer
    FILE *reader;
    char *tokenizer;

    // Constructor to initialize InputReader with input stream
    private InputReader(FILE *stream) {
        reader = stream;
        tokenizer = NULL;
    }

    // Method to read a string token
    private char *n() {
        while (tokenizer == NULL || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    // Method to read an integer
    private int ni() {
        return atoi(n());
    }
}

// Function to compare two integers
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to print an integer
void println(int x) {
    printf("%d\n", x);
}

// Function to close the output stream
void close() {
    fclose(outputStream);
}

// Function to free the memory
void free() {
    free(a);
}

// Function to end the program
void end() {
    printf("