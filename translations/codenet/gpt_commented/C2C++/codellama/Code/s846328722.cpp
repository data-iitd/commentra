#include<iostream>

// Function prototype for linear search
bool linersearch(int [], int, int);

int main() {
    int i, n, s[100000], q, t, count = 0;

    // Read the number of elements in the array
    std::cin >> n;

    // Read n elements into the array s
    for(i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    // Read the number of queries
    std::cin >> q;

    // Process each query to check if the element exists in the array
    for(i = 0; i < q; i++) {
        std::cin >> t; // Read the query element
        // Use linear search to check if the element t is in the array s
        if(linersearch(s, n, t)) count++; // Increment count if found
    }

    // Output the total count of found elements
    std::cout << count << std::endl;
  
    return 0;
}

// Function to perform linear search
bool linersearch(int a[], int n, int key) {
    int i = 0;

    // Sentinel value: place the key at the end of the array
    a[n] = key;
  
    // Search for the key in the array
    while(a[i] != key) {
        i++; // Increment index until the key is found
    }
    
    // Return true if the key was found within the original array bounds
    return i != n;
}

