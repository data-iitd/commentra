#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to read a line text from stdin and return its string
char* NextLine() {
    char* line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }
    return line;
}

// Function to read a line text, that consists of ONLY INTEGERS DELIMITED BY SPACES, from stdin
// And then returns integers slice
int* NextIntsLine() {
    char* line = NextLine();
    char* token = strtok(line, " ");
    int count = 0;
    int* ints = malloc(100 * sizeof(int)); // Allocate memory for integers
    while (token != NULL) {
        ints[count++] = atoi(token);
        token = strtok(NULL, " ");
    }
    free(line); // Free the allocated line memory
    return ints;
}

// Function to read a line text, that consists of ONLY CHARACTERS ARRANGED CONTINUOUSLY, from stdin
// And then returns runes slice
char* NextRunesLine() {
    return NextLine();
}

// Function to find the maximum integer among input integers
// This function needs at least 1 argument (no argument causes panic)
int Max(int num_args, ...) {
    va_list args;
    va_start(args, num_args);
    int max = va_arg(args, int);
    for (int i = 1; i < num_args; i++) {
        int current = va_arg(args, int);
        if (current > max) {
            max = current;
        }
    }
    va_end(args);
    return max;
}

// Function to find the minimum integer among input integers
// This function needs at least 1 argument (no argument causes panic)
int Min(int num_args, ...) {
    va_list args;
    va_start(args, num_args);
    int min = va_arg(args, int);
    for (int i = 1; i < num_args; i++) {
        int current = va_arg(args, int);
        if (current < min) {
            min = current;
        }
    }
    va_end(args);
    return min;
}

// Function to calculate integer power
int PowInt(int base, int exp) {
    if (base < 0 || exp < 0) {
        fprintf(stderr, "[argument error]: PowInt does not accept negative integers\n");
        exit(EXIT_FAILURE);
    }
    return (int)pow(base, exp);
}

// Function to calculate absolute value of an integer
int AbsInt(int a) {
    return (int)fabs(a);
}

// Function to delete an element from a slice
int* DeleteElement(int* s, int len, int index) {
    if (index < 0 || index >= len) {
        fprintf(stderr, "[index error]\n");
        exit(EXIT_FAILURE);
    }
    int* n = malloc((len - 1) * sizeof(int));
    for (int i = 0, j = 0; i < len; i++) {
        if (i != index) {
            n[j++] = s[i];
        }
    }
    return n;
}

// Function to concatenate two slices
char* Concat(char* s, char* t) {
    size_t len_s = strlen(s);
    size_t len_t = strlen(t);
    char* n = malloc(len_s + len_t + 1);
    strcpy(n, s);
    strcat(n, t);
    free(s); // Free the allocated s memory
    free(t); // Free the allocated t memory
    return n;
}

// Variable declaration and initialization
int x;

// Main function
int main() {
    int* tmp = NextIntsLine();
    x = tmp[0];
    int sum = 0;
    int i = 1;
    while (1) {
        sum += i;
        if (sum >= x) {
            break;
        }
        i++;
    }
    printf("%d\n", i);
    free(tmp); // Free the allocated tmp memory
    return 0;
}
