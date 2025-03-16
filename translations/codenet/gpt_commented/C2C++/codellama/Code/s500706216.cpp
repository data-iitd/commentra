#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read the number of elements (n) and the number of iterations (k)
    int n, k;
    cin >> n >> k;

    // Input the initial values into the array 'a'
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Calculate the influence range for each element in 'a'
    vector<int> light(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int r, l;
        r = i - a[i]; // Calculate the left boundary
        l = i + a[i]; // Calculate the right boundary
        light[(r < 0 ? 0 : r)]++; // Increment the start of the influence range
        light[(l + 1 > n ? n + 1 : l + 1)]--; // Decrement the end of the influence range
    }

    // Perform k iterations to update the array 'a'
    for (int i = 0; i < k; i++) {
        int sum = 0;

        // Update 'a' based on the current influence ranges
        for (int j = 0; j < n; j++) {
            sum += light[j]; // Accumulate the influence
            a[j] = sum; // Update 'a' with the accumulated influence
        }

        // Update the influence ranges based on the new values in 'a'
        for (int j = 0; j < n; j++) {
            int r = j - a[j]; // Calculate the new left boundary
            int l = j + a[j]; // Calculate the new right boundary
            light[(r < 0 ? 0 : r)]++; // Increment the start of the new influence range
            light[(l + 1 > n ? n + 1 : l + 1)]--; // Decrement the end of the new influence range
        }

        // Check if all elements in 'a' are the same and equal to n
        bool isSame = true;
        for (int j = 0; j < n - 1; j++) {
            if (a[j] != a[j + 1]) {
                isSame = false; // Set flag to false if any elements differ
                break;
            }
        }
        // If all elements are the same and equal to n, exit the loop
        if (isSame && a[0] == n) {
            break;
        }
    }

    // Output the final state of the array 'a'
    for (int j = 0; j < n; j++) {
        cout << a[j] << " "; // Print each element of 'a'
    }
    cout << endl; // Print a newline after the last element
    return 0; // Return success
}

