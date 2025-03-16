#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Define the number of elements 'n' and the difference 'd' in the input list
    int n, d;
    cin >> n >> d;

    // Initialize a vector 'x' to store the input elements
    vector<int> x(n);

    // Initialize variables 'm' and 'q' to 0
    int m = 0;
    int q = 0;

    // Read the 'n' elements from the input
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Iterate through the vector 'x' to find the elements that are not in increasing order
    for (int i = 0; i < n - 1; i++) {
        // Check if the current element is greater than or equal to the next element
        if (x[i] >= x[i + 1]) {
            // Calculate the number of elements that need to be added to the next element
            q = (x[i] - x[i + 1]) / d + 1;
            // Add the calculated number of elements to the current and next elements
            m += q;
            x[i + 1] += q * d;
        }
    }

    // Print the final result 'm'
    cout << m << endl;

    return 0;
}

// <END-OF-CODE>
