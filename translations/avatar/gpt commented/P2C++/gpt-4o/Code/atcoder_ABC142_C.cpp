#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;  // Read the number of elements

    vector<pair<int, int>> A(N);  // Create a vector of pairs to store (index, value)

    // Read the elements and store them in the vector
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        A[i] = make_pair(i + 1, x);  // Store index (i + 1) and value (x)
    }

    // Sort the vector based on the second item (the value) in each pair
    sort(A.begin(), A.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;  // Compare based on the value
    });

    // Extract the first item (the original index) from each sorted pair into a new vector
    vector<int> A__;
    for (const auto& a : A) {
        A__.push_back(a.first);  // Push the index into the new vector
    }

    // Print the indices of the sorted values, separated by spaces
    for (size_t i = 0; i < A__.size() - 1; ++i) {  // Loop through all but the last index
        cout << A__[i] << " ";  // Print each index followed by a space
    }

    // Print the last index without a trailing space
    cout << A__.back();

    return 0;
}

// <END-OF-CODE>
