// Importing necessary headers
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to reverse the subarray of vector 'a' from index 'b' to 'e' (both inclusive)
void reva(vector<int>& a, int b, int e) {
    // Reverse the subarray using the std::reverse function
    reverse(a.begin() + b, a.begin() + e + 1);
}

// Main function
int main() {
    // Read the number of elements in the array 'a'
    int n;
    cin >> n;
    
    // Allocate memory for the vector 'a' of size 'n'
    vector<int> a(n);

    // Read 'n' integers from the standard input and store them in the vector 'a'
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Read the number of queries 'q'
    int q;
    cin >> q;

    // Process each query by reversing the subarray of 'a'
    for (int i = 0; i < q; i++) {
        // Read the starting and ending indices of the subarray to be reversed
        int b, e;
        cin >> b >> e;

        // Reverse the subarray 'a[b:e]'
        reva(a, b, e);
    }

    // Write the reversed array 'a' to the standard output
    for (int i = 0; i < n; i++) {
        // Write each element of the array 'a' to the standard output with a space in between (except for the first element)
        if (i > 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;

    return 0;
}

// <END-OF-CODE>
