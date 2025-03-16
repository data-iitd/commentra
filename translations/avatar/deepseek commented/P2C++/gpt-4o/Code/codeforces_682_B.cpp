#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read a list of integers
vector<int> readIntList(int n) {
    vector<int> list(n);
    for (int i = 0; i < n; ++i) {
        cin >> list[i];
    }
    return list;
}

int main() {
    // Read the number of elements
    int n;
    cin >> n;

    // Read the list of elements
    vector<int> l = readIntList(n);

    // Initialize variables
    int f = 1;  // Flag variable
    sort(l.begin(), l.end());  // Sort the list
    int c = 0;  // Counter variable

    // Iterate through the list to find the maximum number of unique elements
    for (int i : l) {
        if (i > c) {
            c++;  // Increment the counter if the current element is greater than the counter
        }
    }

    // Print the result
    cout << c + 1 << endl;  // Print the maximum number of unique elements

    return 0;
}

// <END-OF-CODE>
