#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create an input stream for input and an output stream for output
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read the number of elements
    int n;
    cin >> n;
    
    // Initialize a vector to store the input integers
    vector<int> list(n);
    
    // Read n integers from input and add them to the list
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    
    // Sort the list of integers in ascending order
    sort(list.begin(), list.end());
    
    // Initialize a counter to track the maximum consecutive integer
    int c = 1;
    
    // Iterate through the sorted list to find the maximum consecutive integer
    for (int i = 0; i < n; i++) {
        // If the current integer is greater than or equal to the counter, increment the counter
        if (list[i] >= c) {
            c++;
        }
    }
    
    // Print the result which is the maximum consecutive integer found
    cout << c << endl;
    
    return 0;
}

// <END-OF-CODE>
