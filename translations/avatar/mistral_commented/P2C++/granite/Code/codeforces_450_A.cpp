
#####
# Code
#####

# Include the necessary header file
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Define the number of elements 'n' and the modulus'm' in the list 'l'
    int n, m;
    cin >> n >> m;

    // Initialize a vector 'l' to store the elements of the list
    vector<int> l(n);

    // Read the elements of the list 'l' from the input
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    // Initialize a vector 'l2' to store the quotient of each element in 'l' divided by'm'
    vector<int> l2(n);

    // Iterate through each element 'i' in the vector 'l'
    for (int i = 0; i < n; i++) {
        // Check if the element 'i' is divisible by'm'. If yes, store the quotient (integer division) in 'l2'. If not, store the quotient plus one.
        if (l[i] % m == 0) {
            l2[i] = l[i] / m;
        } else {
            l2[i] = int(l[i] / m + 1);
        }
    }

    // Find the maximum quotient in 'l2'
    int mx = *max_element(l2.begin(), l2.end());

    // Iterate through each index 'i' from 0 to 'n-1' in the vector 'l2'
    for (int i = 0; i < n; i++) {
        // Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient'mx'. If yes, store the index 'i' in the variable 'ind'.
        if (l2[i] == mx) {
            ind = i;
        }
    }

    // Print the index 'ind' plus one (since the indices in C++ start from 0)
    cout << ind + 1 << endl;

    return 0;
}
