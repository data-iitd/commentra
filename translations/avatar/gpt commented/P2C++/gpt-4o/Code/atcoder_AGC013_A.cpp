#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// Function to read an integer from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers from input
vector<int> readList() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    return vec;
}

int main() {
    // Read the number of elements
    int N = readInt();

    // Read the list of integers
    vector<int> A = readList();

    // Remove consecutive duplicates from the list
    auto last = unique(A.begin(), A.end());
    A.erase(last, A.end());

    // Update N to the new length of A after removing duplicates
    N = A.size();

    // Initialize the index and answer counter
    int i = 1;
    int ans = 0;

    // Loop through the list to count the number of peaks and valleys
    while (i < N - 1) {
        // Check if the current element is a peak or a valley
        if ((A[i - 1] < A[i] && A[i] > A[i + 1]) || (A[i - 1] > A[i] && A[i] < A[i + 1])) {
            ans++;  // Increment the answer for each peak/valley found
            i++;    // Skip the next element to avoid double counting
        }
        i++;  // Move to the next element
    }

    // Print the total count of peaks and valleys plus one
    cout << ans + 1 << endl;

    return 0;
}

// <END-OF-CODE>
