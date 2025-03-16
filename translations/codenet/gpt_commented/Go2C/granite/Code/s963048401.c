
#include <stdio.h>
#include <stdlib.h>

// Initialize a new scanner to read input from standard input
#define SCANNER(type) type Scanner() { \
    type n; \
    scanf("%" #type, &n); \
    return n; \
}

// Scanner function reads a line of input and returns it as a string
char* Scanner() {
    int bufSize = 1024;
    char* buf = (char*)malloc(sizeof(char) * bufSize);
    fgets(buf, bufSize, stdin);
    char* ret = (char*)malloc(sizeof(char) * (strlen(buf) - 1));
    for (int i = 0; i < strlen(buf) - 1; i++) {
        ret[i] = buf[i];
    }
    free(buf);
    return ret;
}

// intScanner function reads an integer from input and returns it
int intScanner() {
    int n;
    scanf("%d", &n);
    return n;
}

// floatScanner function reads a float64 from input and returns it
double floatScanner() {
    double n;
    scanf("%lf", &n);
    return n;
}

// stringToInt converts a string to an integer
int stringToInt(char* s) {
    int n;
    sscanf(s, "%d", &n);
    return n;
}

// Declare a variable for the modulus value
#define MOD 1000000007

int main() {
    // Create a buffer for the scanner with a size limit defined by mod
    char buf[MOD];
    fgets(buf, MOD, stdin);
    
    // Set the scanner to split input by whitespace
    char* token = strtok(buf, " ");
    
    // Read the number of elements
    int n = intScanner();
    
    // Initialize a slice to hold the integers
    int* as = (int*)malloc(sizeof(int) * n);
    
    // Read n integers from input
    for (int i = 0; i < n; i++) {
        as[i] = intScanner();
    }
    
    // Initialize a slice to hold the unique sorted integers
    int* xs = (int*)malloc(sizeof(int) * n);
    xs[0] = as[0];
    int xsIdx = 1;
    
    // Iterate through the input integers starting from the second element
    for (int j = 1; j < n; j++) {
        // Use binary search to find the position to insert the current integer
        int idx = 0;
        int left = 0;
        int right = xsIdx;
        while (left < right) {
            int mid = (left + right) / 2;
            if (xs[mid] < as[j]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        idx = left;
        
        // If the index is equal to the length of xs, append the integer
        if (idx == xsIdx) {
            xs = (int*)realloc(xs, sizeof(int) * (xsIdx + 1));
            xs[xsIdx] = as[j];
            xsIdx++;
        } else {
            // Otherwise, replace the existing integer at the found index
            xs[idx] = as[j];
        }
    }
    
    // Print the number of unique integers found
    printf("%d\n", xsIdx);
    
    // Free the allocated memory
    free(as);
    free(xs);
    
    return 0;
}

