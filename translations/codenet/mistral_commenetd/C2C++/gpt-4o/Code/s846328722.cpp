#include <iostream> // Including the iostream library for input/output

// Function declaration for linear search
bool linearSearch(int[], int, int);

int main() {
    int n; // Declaring variable n for array size
    int s[100000]; // Declaring an array s of size 100000
    int q, t; // Declaring variables q and t for number of queries and query elements
    int count = 0; // Initializing count to zero

    // Reading the size of the array from user input
    std::cin >> n;

    // Reading array elements into the array s
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    // Reading the number of queries from user input
    std::cin >> q;

    // Looping through each query
    for (int i = 0; i < q; i++) {
        std::cin >> t; // Reading a query element from user input

        // Calling the linear search function to check if the query element is present in the array
        if (linearSearch(s, n, t)) count++; // If the query element is present, increment the count
    }

    // Printing the final count of query elements present in the array
    std::cout << count << std::endl;

    return 0;
}

// Function definition for linear search
bool linearSearch(int a[], int n, int key) {
    int i = 0; // Initializing index i to zero

    // Adding the key to the end of the array for the case when the key is already present at the beginning
    a[n] = key;

    // Linear search algorithm to find the index of the key in the array
    while (a[i] != key) {
        i++; // Incrementing index i until the key is found
    }

    // Returning true if the key is found, and false otherwise
    return i != n;
}

// <END-OF-CODE>
