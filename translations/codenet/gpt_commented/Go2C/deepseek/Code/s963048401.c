#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

// Function to read a line of input
char* readLine() {
    char *line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }
    return line;
}

// Function to convert a string to an integer
int stringToInt(const char* s) {
    return atoi(s);
}

// Function to read an integer from input
int readInt() {
    char *line = readLine();
    int result = stringToInt(line);
    free(line);
    return result;
}

// Function to read a float from input
double readFloat() {
    char *line = readLine();
    double result = atof(line);
    free(line);
    return result;
}

// Function to read n integers from input and store them in an array
void readInts(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = readInt();
    }
}

// Function to perform binary search in a sorted array
int binarySearch(int* arr, int len, int target) {
    int left = 0, right = len - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    // Set the modulus value to 1000000007
    const int mod = MOD;

    // Read the number of elements
    int n = readInt();

    // Initialize an array to hold the integers
    int as[n];

    // Read n integers from input
    readInts(as, n);

    // Initialize an array to hold the unique sorted integers
    int xs[n];
    int size = 0;

    // Iterate through the input integers
    for (int j = 0; j < n; j++) {
        // Use binary search to find the position to insert the current integer
        int idx = binarySearch(xs, size, as[j]);

        // If the index is equal to the size, append the integer
        if (idx == size) {
            xs[size++] = as[j];
        } else {
            // Otherwise, replace the existing integer at the found index
            xs[idx] = as[j];
        }
    }

    // Print the number of unique integers found
    printf("%d\n", size);

    return 0;
}
