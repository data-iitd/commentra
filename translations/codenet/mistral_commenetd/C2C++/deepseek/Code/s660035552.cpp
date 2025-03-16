#include <iostream> // Standard Input/Output Stream Library
#include <vector> // Vector Library
#include <algorithm> // Algorithm Library

// Initialize low and high arrays for quicksort
int low[200000];
int high[200000];

// Array 'a' to store elements after sorting
int a[200000];

// Array 'b' to store elements for quicksort partitioning
int b[200000];

// Function to partition the array using quicksort algorithm
int part(int a[], int b[], int l, int r) {
    int i, j, x, t; // Initialize variables

    i = l - 1; // Initialize index 'i' for smaller elements
    j = r; // Initialize index 'j' for greater elements

    x = b[r]; // Set pivot as last element

    while (true) { // While loop for partitioning
        while (b[++i] < x); // Move 'i' to next smaller element
        while (i < --j && x < b[j]); // Move 'j' to previous greater element

        if (i >= j) break; // If 'i' and 'j' meet, partitioning is done

        t = a[i]; a[i] = a[j]; a[j] = t; // Swap elements in 'a' array
        t = b[i]; b[i] = b[j]; b[j] = t; // Swap elements in 'b' array
    }

    t = a[i]; a[i] = a[r]; a[r] = t; // Swap pivot with last element in 'a' array
    t = b[i]; b[i] = b[r]; b[r] = t; // Swap pivot with last element in 'b' array
    return i; // Return index of pivot
}

// Function to perform quicksort on the array 'a'
void quicksort(int a[], int b[], int n) {
    int l, r, v; // Initialize variables
    int sp; // Stack pointer

    low[0] = 0; // Initialize 'low' stack with base index 0
    high[0] = n - 1; // Initialize 'high' stack with top index 'n-1'
    sp = 1; // Initialize stack pointer

    while (sp > 0) { // While stack is not empty
        sp--; // Decrement stack pointer
        l = low[sp]; // Get base index 'l' from stack
        r = high[sp]; // Get top index 'r' from stack

        if (l >= r) { // If base and top indices are same, no need to partition
            continue; // Skip this iteration
        }

        v = part(a, b, l, r); // Partition the array

        if (v - l < r - v) { // If partitioning moved pivot to left, swap 'low' and 'high' indices
            low[sp] = v + 1;
            high[sp++] = r;
            low[sp] = l;
            high[sp++] = v - 1;
        }
        else { // If partitioning moved pivot to right, swap 'low' and 'high' indices in reverse order
            low[sp] = l;
            high[sp++] = v - 1;
            low[sp] = v + 1;
            high[sp++] = r;
        }
    }
}

// Main function to read input and call quicksort
int main() {
    int n, m; // Initialize variables
    int i; // Initialize loop variable
    std::vector<std::pair<int, int>> elements(100006); // Initialize vector of pairs to store elements and queries
    int cnt = 0; // Initialize counter for unique elements

    std::cin >> n >> m; // Read number of elements 'n' and queries 'm'

    for (i = 0; i < m; i++) std::cin >> elements[i].first >> elements[i].second; // Read elements and their corresponding queries

    quicksort(a, b, m); // Call quicksort function to sort elements

    int t = 0; // Initialize counter to 0
    for (i = 0; i < m; i++) { // Iterate through sorted elements
        if (t <= elements[i].first) { // If current element is greater than previous element, increment counter
            t = elements[i].second; // Set current query as new temporary storage
            cnt++; // Increment counter
        }
    }

    std::cout << cnt << std::endl; // Print the number of unique queries

    return 0; // Return 0 to indicate successful execution
}

