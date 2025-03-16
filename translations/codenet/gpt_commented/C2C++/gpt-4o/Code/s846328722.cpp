#include <iostream>
#include <vector>

// Function prototype for linear search
bool linearSearch(const std::vector<int>&, int, int);

int main() {
    int n, q, count = 0;

    // Read the number of elements in the array
    std::cin >> n;
    std::vector<int> s(n);

    // Read n elements into the array s
    for(int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    // Read the number of queries
    std::cin >> q;

    // Process each query to check if the element exists in the array
    for(int i = 0; i < q; i++) {
        int t; // Query element
        std::cin >> t;
        // Use linear search to check if the element t is in the array s
        if(linearSearch(s, n, t)) count++; // Increment count if found
    }

    // Output the total count of found elements
    std::cout << count << std::endl;

    return 0;
}

// Function to perform linear search
bool linearSearch(const std::vector<int>& a, int n, int key) {
    // Sentinel value: create a copy of the array with the key at the end
    std::vector<int> temp = a;
    temp.push_back(key); // Add the key as a sentinel value

    int i = 0;

    // Search for the key in the array
    while(temp[i] != key) {
        i++; // Increment index until the key is found
    }

    // Return true if the key was found within the original array bounds
    return i != n;
}

// <END-OF-CODE>
