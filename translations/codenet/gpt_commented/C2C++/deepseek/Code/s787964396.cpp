#include<iostream>
#include<vector>
#define I 10000 // Define a constant for the maximum range of input values

// Function prototype for CountingSort
void CountingSort(std::vector<int>&, std::vector<int>&, int);

int main() {
    int n, max = 0;

    // Read the number of elements to be sorted
    std::cin >> n;

    // Allocate memory for the input array 'a' and output array 'b'
    std::vector<int> a(n + 1);
    std::vector<int> b(n + 1);

    // Read 'n' elements into the array 'a'
    for (int i = 0; i < n; i++) {
        std::cin >> a[i + 1]; // Store elements starting from index 1
    }

    // Call the CountingSort function to sort the array 'a' and store the result in 'b'
    CountingSort(a, b, n);

    // Print the sorted elements from array 'b'
    std::cout << b[1]; // Print the first sorted element
    for (int i = 2; i < n + 1; i++) {
        std::cout << " " << b[i]; // Print the remaining sorted elements
    }
    std::cout << std::endl;

    return 0; // Return success
}

// Function to perform Counting Sort
void CountingSort(std::vector<int>& a, std::vector<int>& b, int k) {
    std::vector<int> c(I + 1, 0); // Initialize the counting array 'c' to zero

    // Count occurrences of each element in array 'a'
    for (int j = 0; j < k; j++) {
        c[a[j + 1]]++; // Increment the count for each element
    }

    // Update the counting array 'c' to contain the actual positions of elements
    for (int i = 1; i < I + 1; i++) {
        c[i] += c[i - 1]; // Cumulative sum to determine positions
    }

    // Build the output array 'b' using the counting array 'c'
    for (int j = k; j > 0; j--) {
        b[c[a[j]]] = a[j]; // Place the elements in their sorted position
        c[a[j]]--; // Decrement the count for the current element
    }
}

