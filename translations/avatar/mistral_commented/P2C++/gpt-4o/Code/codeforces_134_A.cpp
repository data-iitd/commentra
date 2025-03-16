#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Reading the number of elements 'n' in the list 'w'
    int n;
    cin >> n;

    // Initializing a vector 'w' to store the elements
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i]; // Reading each element into the vector
    }

    // Initializing a vector 'd' to store the indices of the elements that satisfy the condition
    vector<int> d;

    // Calculating the total sum of the elements in 'w'
    int total_sum = 0;
    for (int i = 0; i < n; ++i) {
        total_sum += w[i];
    }

    // Iterating through each element 'i' in the list 'w'
    for (int i = 0; i < n; ++i) {
        // Checking if the average of the remaining sum of elements after removing the current element 'w[i]'
        // is equal to the current element 'w[i]'
        if ((total_sum - w[i]) / (n - 1) == w[i]) {
            // If the condition is true, append the index 'i+1' to the vector 'd'
            d.push_back(i + 1);
        }
    }

    // Printing the length of the vector 'd'
    cout << d.size() << endl;

    // Printing the elements of the vector 'd' separated by a space
    for (size_t i = 0; i < d.size(); ++i) {
        cout << d[i];
        if (i < d.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}

// <END-OF-CODE>
