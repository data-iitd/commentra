#include <iostream>
#include <vector>

int main() {
    // Declare variables
    int n, m, s, t;

    // Read the number of elements in the array
    std::cin >> n;
    
    // Declare a vector of size n
    std::vector<int> a(n);

    // Read n elements into the vector
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Initialize total sum variable
    t = 0;

    // Outer loop to iterate through each element of the array
    for(int i = 0; i < n; i++) {
        // Initialize sum for the current element
        s = 0;

        // Inner loop to calculate the product of the current element with all subsequent elements
        for(int j = 1; j < n; j++) {
            // Skip elements that are not after the current element
            if(j <= i) {
                continue;
            }

            // Calculate the product of the current element a[i] and a[j]
            m = a[i] * a[j];

            // Add the product to the sum for the current element
            s += m;
        }

        // Add the sum of products for the current element to the total
        t += s;
    }

    // Print the total sum of products
    std::cout << t << std::endl;

    // Return success status
    return 0;
}

// <END-OF-CODE>
