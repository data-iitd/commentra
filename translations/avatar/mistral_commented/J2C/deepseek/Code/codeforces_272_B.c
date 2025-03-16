#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A custom InputReader struct for reading input efficiently
typedef struct {
    char *buffer;
    size_t buffer_size;
    ssize_t input_pos;
} FastReader;

// Initialize the FastReader
void init_fast_reader(FastReader *fr, size_t buffer_size) {
    fr->buffer = (char *)malloc(buffer_size);
    fr->buffer_size = buffer_size;
    fr->input_pos = 0;
}

// Read a line from stdin
char* read_line(FastReader *fr) {
    ssize_t pos = 0;
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (pos < fr->buffer_size - 1) {
            fr->buffer[pos++] = ch;
        }
    }
    fr->buffer[pos] = '\0';
    return fr->buffer;
}

// Read a string token
char* next_token(FastReader *fr) {
    char *token_start = fr->buffer + fr->input_pos;
    while (fr->buffer[fr->input_pos] != ' ' && fr->buffer[fr->input_pos] != '\0') {
        fr->input_pos++;
    }
    fr->buffer[fr->input_pos] = '\0';
    fr->input_pos++;
    return token_start;
}

// Read an integer
int next_int(FastReader *fr) {
    return atoi(next_token(fr));
}

// Read a long integer
long long next_long(FastReader *fr) {
    return atoll(next_token(fr));
}

// Read a double
double next_double(FastReader *fr) {
    return atof(next_token(fr));
}

// A helper function to get the index of a number in the array 'a'
int rec(long long x) {
    int answer = 0;

    // Calculate the index of the number in the array 'a' by counting the number of set bits in the binary representation of the number
    for (int k = 31; k >= 0; k--) {
        if ((x & (1 << k)) != 0) // If the k-th bit is set
            answer++;             // Increment the answer
    }

    return answer;
}

int main() {
    FastReader fr;
    init_fast_reader(&fr, 1024);

    // Read the number of test cases
    int n = next_int(&fr);

    // Initialize an array 'a' to store the frequency of each number
    int a[33];
    memset(a, 0, sizeof(a));

    // Read each test case and update the frequency of the number in the array 'a'
    for (int i = 0; i < n; i++) {
        int num = next_int(&fr); // Read a number
        int index = rec(num);    // Get the index of the number in the array 'a'
        a[index]++;              // Increment the frequency of the number in the array 'a'
    }

    // Calculate the answer and print it
    double answer = 0;
    for (int i = 0; i < 33; i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1); // Calculate the sum of squares of numbers up to the current number
        answer += summ;                                 // Add the sum to the answer
    }
    printf("%lld\n", (long long)answer); // Print the answer as a long integer

    free(fr.buffer); // Free the allocated buffer
    return 0;
}
