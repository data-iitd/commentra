#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Create a variable to hold the number of elements in the array
    int n;
    cin >> n;

    // Initialize a vector to hold the input integers
    vector<int> arr(n);

    // Populate the vector with integers from user input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize the answer with the first element of the array plus one
    int ans = arr[0] + 1;

    // Calculate the total distance based on the differences between consecutive elements
    for (int i = 1; i < n; i++) {
        // Add the absolute difference between the current and previous element, plus 2
        ans += abs(arr[i] - arr[i - 1]) + 2;
    }

    // Output the final calculated answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
