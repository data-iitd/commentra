#include <iostream>
#include <vector>

#define I 10000 // Define a constant I with the value 10000

// Function to perform Counting Sort
void CountingSort(std::vector<int>& a, std::vector<int>& b, int k);

int main() {
    int n;
    
    // Read the number of elements
    std::cin >> n;
    
    // Dynamically allocate memory for arrays a and b
    std::vector<int> a(n + 1);
    std::vector<int> b(n + 1);
    
    // Read elements into array a starting from index 1 to n
    for (int i = 0; i < n; i++) {
        std::cin >> a[i + 1];
    }
    
    // Call CountingSort function to sort the array
    CountingSort(a, b, n);
    
    // Print the sorted elements starting from index 1 to n
    std::cout << b[1];
    for (int i = 2; i < n + 1; i++) {
        std::cout << " " << b[i];
    }
    std::cout << std::endl;
    
    return 0;
}

// Function to perform Counting Sort
void CountingSort(std::vector<int>& a, std::vector<int>& b, int k) {
    int c[I + 1] = {0}; // Initialize array c to store the count of each element
    
    // Count the occurrences of each element in array a
    for (int j = 0; j < k; j++) {
        c[a[j + 1]]++;
    }
    
    // Compute the cumulative count to determine the positions of elements in the sorted array
    for (int i = 1; i <= I; i++) {
        c[i] += c[i - 1];
    }
    
    // Place elements into array b in sorted order
    for (int j = k; j > 0; j--) {
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
}

// <END-OF-CODE>
