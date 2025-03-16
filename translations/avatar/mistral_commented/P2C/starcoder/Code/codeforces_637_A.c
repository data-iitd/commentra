#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>

// Define a structure to store the occurrences of each string
typedef struct {
    char *s;
    int c;
} str;

// Function to read the number of strings to be processed
int read_int() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read the strings and split the last string by space
void read_str(char **s, int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
}

// Function to create a Counter object to store the occurrences of each string
str *create_counter(char **s, int n) {
    str *w = (str *) malloc(n * sizeof(str));
    int i;
    for (i = 0; i < n; i++) {
        w[i].s = s[i];
        w[i].c = 0;
    }
    return w;
}

// Function to initialize variables for storing the index of the longest string and its value
int init_vars(int *c, int *a) {
    *c = -1;
    *a = 0;
}

// Function to iterate through each string in the Counter object
void iterate_counter(str *w, int n, int *c, int *a) {
    int i;
    for (i = 0; i < n; i++) {
        if (w[i].c == INT_MAX) {
            if (strstr(w[i].s, " ")!= NULL) {
                if (strstr(w[i].s, " ") - w[i].s > *c) {
                    *a = i;
                    *c = strstr(w[i].s, " ") - w[i].s;
                }
            }
        }
    }
}

// Function to print the longest string
void print_str(char **s, int n, int a) {
    printf("%s\n", s[a]);
}

// Main function
int main() {
    // Read the number of strings to be processed
    int n = read_int();

    // Read the strings and split the last string by space
    char **s = (char **) malloc(n * sizeof(char *));
    read_str(s, n);

    // Create a Counter object to store the occurrences of each string
    str *w = create_counter(s, n);

    // Initialize variables for storing the index of the longest string and its value
    int c, a;
    init_vars(&c, &a);

    // Iterate through each string in the Counter object
    iterate_counter(w, n, &c, &a);

    // Print the longest string
    print_str(s, n, a);

    // Free the memory allocated to the strings
    int i;
    for (i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);

    // Free the memory allocated to the Counter object
    free(w);

    return 0;
}

