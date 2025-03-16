// Include necessary headers
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Function to read an integer from standard input
int nextInt() {
    int i;
    cin >> i;
    return i;
}

// Function to read n integers from standard input
vector<int> nextInts(int n) {
    vector<int> slice(n);
    for (int i = 0; i < n; i++) {
        slice[i] = nextInt();
    }
    return slice;
}

int main() {
    // Initialize the number of elements
    int n = nextInt();
    vector<int> a = nextInts(n);

    // Initialize answer variable
    int ans = 0;

    // Iterate through the array 'a'
    for (int i = 0; i < n; i++) {
        // Initialize left and right indices
        int l = i, r = i + 1;

        // Use a while loop to find the next index 'r' such that the difference between 'a[r]' and 'a[l]' is negative
        while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
            r++;
        }

        // Increment the answer variable
        ans++;

        // Update the index 'i' to 'r' for the next iteration
        i = r;
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
