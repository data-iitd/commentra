#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Function to read an integer from input
int intScanner() {
    int n;
    cin >> n;
    return n;
}

int main() {
    // Set the modulus value to 1000000007
    const int mod = 1000000007;

    // Read the number of elements
    int n = intScanner();

    // Initialize a vector to hold the integers
    vector<int> as(n);

    // Read n integers from input
    for (int i = 0; i < n; i++) {
        as[i] = intScanner();
    }

    // Use a set to hold unique integers
    unordered_set<int> uniqueIntegers;

    // Insert integers into the set
    for (int j = 0; j < n; j++) {
        uniqueIntegers.insert(as[j]);
    }

    // Print the number of unique integers found
    cout << uniqueIntegers.size() << endl;

    return 0;
}

// <END-OF-CODE>
