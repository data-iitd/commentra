#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    // Read the number of elements in the list `w`
    int n;
    cin >> n;

    // Read `n` integers from the standard input and store them in the vector `w`
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    // Calculate the sum of all elements in the vector `w`
    int x = accumulate(w.begin(), w.end(), 0);

    // Initialize an empty vector `d` to store the indices of elements that satisfy the condition
    vector<int> d;

    // Iterate over each element in the vector `w`
    for (int i = 0; i < n; ++i) {
        // Check if the current element `w[i]` is equal to the average of the total sum `x` and the number of elements `n` minus one
        if ((x - w[i]) / (n - 1) == w[i]) {
            // Append the 1-based index of the element to the vector `d`
            d.push_back(i + 1);
        }
    }

    // Print the length of the vector `d`
    cout << d.size() << endl;

    // Print the indices in `d` separated by spaces
    for (size_t i = 0; i < d.size(); ++i) {
        cout << d[i];
        if (i < d.size() - 1) {
            cout << ' ';
        }
    }
    cout << endl;

    return 0;
}

// <END-OF-CODE>
