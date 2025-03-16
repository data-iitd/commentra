
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A custom InputReader class for reading input efficiently
typedef struct {
    char *str;
    int len;
    int pos;
} InputReader;

// Initialize the InputReader
InputReader *init(char *str) {
    InputReader *reader = (InputReader *) malloc(sizeof(InputReader));
    reader->str = str;
    reader->len = strlen(str);
    reader->pos = 0;
    return reader;
}

// Read a string token
char *next(InputReader *reader) {
    char *token = (char *) malloc(sizeof(char) * 100);
    int i = 0;
    while (reader->pos < reader->len && reader->str[reader->pos]!='') {
        token[i++] = reader->str[reader->pos++];
    }
    token[i] = '\0';
    return token;
}

// Read an integer
int nextInt(InputReader *reader) {
    return atoi(next(reader));
}

// Read a long integer
long nextLong(InputReader *reader) {
    return atol(next(reader));
}

// Read a double
double nextDouble(InputReader *reader) {
    return atof(next(reader));
}

// Read a line
char *nextLine(InputReader *reader) {
    char *line = (char *) malloc(sizeof(char) * 100);
    int i = 0;
    while (reader->pos < reader->len && reader->str[reader->pos]!= '\n') {
        line[i++] = reader->str[reader->pos++];
    }
    line[i] = '\0';
    return line;
}

// A helper method to get the index of a number in the array 'a'
int rec(long x) {
    int answer = 0;

    // Calculate the index of the number in the array 'a' by counting the number of set bits in the binary representation of the number
    for (int k = 31; k >= 0; k--) {
        if ((x & (1 << k))!= 0) // If the k-th bit is set
            answer++;             // Increment the answer
    }

    return answer;
}

// Main function
int main() {
    // Read the number of test cases
    InputReader *reader = init(readLine());
    int n = nextInt(reader);

    // Initialize an array 'a' to store the frequency of each number
    int a[33];
    memset(a, 0, sizeof(a));

    // Read each test case and update the frequency of the number in the array 'a'
    for (int i = 0; i < n; i++) {
        int num = nextInt(reader); // Read a number
        int index = rec(num);      // Get the index of the number in the array 'a'
        a[index]++;                // Increment the frequency of the number in the array 'a'
    }

    // Calculate the answer and print it
    double answer = 0;
    for (int i = 0; i < 33; i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1); // Calculate the sum of squares of numbers up to the current number
        answer += summ;                                 // Add the sum to the answer
    }
    printf("%ld\n", (long) answer); // Print the answer as a long integer

    return 0;
}

