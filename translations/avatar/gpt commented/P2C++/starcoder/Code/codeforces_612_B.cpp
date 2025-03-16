#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read the number of elements
    int n;
    cin >> n;

    // Read the elements into a list and convert them to integers
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Initialize a list 'b' with zeros to store the positions of elements
    vector<int> b(n, 0);

    // Populate the list 'b' with the indices of elements from list 'a'
    for (int i = 0; i < n; i++) {
        b[a[i] - 1] = i;  // Store the index of each element in 'b' based on its value in 'a'
    }

    // Initialize the result variable to accumulate the total distance
    int res = 0;

    // Calculate the total distance between consecutive elements in 'b'
    for (int i = 1; i < n; i++) {
        res += abs(b[i] - b[i - 1]);  // Add the absolute difference of indices to the result
    }

    // Print the final result
    cout << res << endl;

    return 0;
}

