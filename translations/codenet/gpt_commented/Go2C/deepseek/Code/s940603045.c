#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define INF INT_MAX

// Direction vectors for 8 possible movements (up, down, left, right, and diagonals)
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

// Define an infinite value for comparison
const int inf = INF;

// Initialize a new scanner for input
typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t buffer_position;
} Scanner;

Scanner newScanner() {
    Scanner scanner;
    scanner.buffer_size = 10000;
    scanner.buffer = (char *)malloc(scanner.buffer_size * sizeof(char));
    scanner.buffer_position = 0;
    return scanner;
}

// Read the next token from the input
char* next(Scanner *scanner) {
    while (scanner->buffer_position < scanner->buffer_size && scanner->buffer[scanner->buffer_position] == ' ') {
        scanner->buffer_position++;
    }
    if (scanner->buffer_position >= scanner->buffer_size) {
        return NULL;
    }
    size_t start = scanner->buffer_position;
    while (scanner->buffer_position < scanner->buffer_size && scanner->buffer[scanner->buffer_position] != ' ') {
        scanner->buffer_position++;
    }
    char *token = (char *)malloc((scanner->buffer_position - start + 1) * sizeof(char));
    strncpy(token, scanner->buffer + start, scanner->buffer_position - start);
    token[scanner->buffer_position - start] = '\0';
    return token;
}

// Read the entire line from the input
char* line(Scanner *scanner) {
    size_t position = scanner->buffer_position;
    while (position < scanner->buffer_size && scanner->buffer[position] != '\n') {
        position++;
    }
    char *line = (char *)malloc((position - scanner->buffer_position + 1) * sizeof(char));
    strncpy(line, scanner->buffer + scanner->buffer_position, position - scanner->buffer_position);
    line[position - scanner->buffer_position] = '\0';
    scanner->buffer_position = position + 1;
    return line;
}

// Read the next string from the input
char* string(Scanner *scanner) {
    return next(scanner);
}

// Read the next integer from the input
int integer(Scanner *scanner) {
    char *token = next(scanner);
    int value = atoi(token);
    free(token);
    return value;
}

// Read multiple integers from the input
int* ints(Scanner *scanner, int n) {
    int *values = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        values[i] = integer(scanner);
    }
    return values;
}

// Read the next int64 from the input
long long int64(Scanner *scanner) {
    char *token = next(scanner);
    long long value = atoll(token);
    free(token);
    return value;
}

// Read the next uint64 from the input
unsigned long long uint64(Scanner *scanner) {
    char *token = next(scanner);
    unsigned long long value = strtoull(token, NULL, 10);
    free(token);
    return value;
}

// Read the next float64 from the input
double float64(Scanner *scanner) {
    char *token = next(scanner);
    double value = atof(token);
    free(token);
    return value;
}

// Pre-read to ensure there is data in the buffer
void pre(Scanner *scanner) {
    if (scanner->buffer_position >= scanner->buffer_size) {
        char *new_buffer = (char *)malloc(scanner->buffer_size * sizeof(char));
        size_t bytes_read = fread(new_buffer, sizeof(char), scanner->buffer_size, stdin);
        if (bytes_read == 0) {
            return;
        }
        scanner->buffer = new_buffer;
        scanner->buffer_position = 0;
    }
}

// Read a line from the input and fill the buffer
void read_line(Scanner *scanner) {
    scanner->buffer_position = 0;
    scanner->buffer_size = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        scanner->buffer[scanner->buffer_size++] = c;
    }
    scanner->buffer[scanner->buffer_size] = '\0';
}

// Utility functions for various operations

// Check if a value is within a range
bool in(int c, int a, int z) {
    return c >= a && c < z;
}

// Check if a value is outside a range
bool out(int c, int a, int z) {
    return !in(c, a, z);
}

// Convert boolean to integer (1 for true, 0 for false)
int btoi(bool b) {
    return b ? 1 : 0;
}

// Convert integer to boolean (non-zero to true, zero to false)
bool itob(int a) {
    return a != 0;
}

// Return the maximum value from a list of integers
int max(int a, ...) {
    va_list args;
    va_start(args, a);
    int max_value = a;
    int current;
    while ((current = va_arg(args, int)) != -1) {
        if (current > max_value) {
            max_value = current;
        }
    }
    va_end(args);
    return max_value;
}

// Return the minimum value from a list of integers
int min(int a, ...) {
    va_list args;
    va_start(args, a);
    int min_value = a;
    int current;
    while ((current = va_arg(args, int)) != -1) {
        if (current < min_value) {
            min_value = current;
        }
    }
    va_end(args);
    return min_value;
}

// Calculate the sum of a slice of integers
int sum(int *a, int n) {
    int r = 0;
    for (int i = 0; i < n; i++) {
        r += a[i];
    }
    return r;
}

// Calculate the product of a slice of integers
int pro(int *a, int n) {
    int r = a[0];
    for (int i = 1; i < n; i++) {
        r *= a[i];
    }
    return r;
}

// Fill a slice with a specified value
void fill(int *a, int n, int value) {
    for (int i = 0; i < n; i++) {
        a[i] = value;
    }
}

// Return the minimum and maximum of two integers
void minmax(int a, int b, int *min_out, int *max_out) {
    if (a > b) {
        *min_out = a;
        *max_out = b;
    } else {
        *min_out = b;
        *max_out = a;
    }
}

// Return the absolute value of an integer
int abs(int a) {
    return a < 0 ? -a : a;
}

// Calculate the ceiling of a division of two integers
int ceil(int a, int b) {
    return (a % b != 0) ? 1 : 0;
}

// Print a slice of strings with space separation
void print_strings(char **out, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s", out[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

// Print a slice of integers with space separation
void print_ints(int *out, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", out[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    Scanner scanner = newScanner();

    // Read input as a string
    char *N = string(&scanner);
    int n = 0; // Initialize sum of digits

    // Calculate the sum of digits in the input number
    for (int i = 0; i < strlen(N); i++) {
        n += N[i] - '0'; // Convert char to int and accumulate
    }

    // Convert the string input to an integer
    int m = atoi(N);
    // Check if the number is divisible by the sum of its digits
    if (m % n == 0) {
        printf("Yes\n"); // Print "Yes" if divisible
    } else {
        printf("No\n"); // Print "No" if not divisible
    }

    free(N);
    return 0;
}

