#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read input from stdin
int read_int(void) {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read input from stdin
int read_int_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return n;
}

// Function to print output to stdout
void print_int(int n) {
    printf("%d", n);
}

// Function to print output to stdout
void print_int_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i!= n - 1) {
            printf(" ");
        }
    }
}

int main(void) {
    // Read the number of integers to be processed
    int n = read_int();

    // Initialize a HashMap to store the frequency of each integer
    int *map = (int *) malloc(sizeof(int) * n);
    memset(map, 0, sizeof(int) * n);

    // Loop through the input integers and populate the frequency map
    for (int i = 0; i < n; i++) {
        int val = read_int();
        // Update the count of the integer in the map
        map[val]++;
    }

    // Initialize a variable to track the maximum frequency found
    int max = INT_MIN;

    // Iterate through the entries in the frequency map to find the maximum frequency
    for (int i = 0; i < n; i++) {
        int value = map[i];
        // Update max if the current frequency is greater than the current max
        max = (max > value)? max : value;
    }

    // Print the maximum frequency and the number of unique integers
    print_int(max);
    print_int(" ");
    print_int(n);
    print_int("\n");

    return 0;
}

