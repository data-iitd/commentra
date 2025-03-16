#include <iostream>
#include <vector>

int main() {
    int n; // Step 1: Read the value of n, which represents the number of elements in the array.
    long sum = 0; // Initialize sum to store the total difference.
    std::cin >> n; // Read the number of elements.
    std::vector<int> a(n); // Step 2: Dynamically allocate memory for a vector 'a' of size n.
    
    for (int i = 0; i < n; i++) { // Step 3: Read n elements into the vector 'a'.
        std::cin >> a[i];
    }
    
    for (int i = 1; i < n; i++) { // Step 4: Iterate through the vector and calculate the sum of the differences between consecutive elements, updating the vector 'a' to ensure each element is at least as large as the previous one.
        if (a[i - 1] > a[i]) {
            sum += a[i - 1] - a[i]; // Add the difference to the sum.
            a[i] = a[i - 1]; // Update the current element to be at least as large as the previous one.
        }
    }
    
    std::cout << sum << std::endl; // Step 5: Print the calculated sum.
}

// <END-OF-CODE>
