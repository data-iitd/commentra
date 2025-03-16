
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; // Declare a variable 'n' to store the number of elements
    cin >> n; // Read the number of elements from the user
    vector<int> a(n); // Initialize a vector 'a' of size 'n' to store the elements
    int r = 0; // Initialize a variable 'r' to store the result of XOR operation

    // Read the elements of the vector 'a' from the user and perform XOR operation on each element
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r ^= a[i];
    }

    // Print the result of XOR operation for each element in the vector 'a'
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " "; // Print a space before each element except the first one
        cout << r ^ a[i]; // Print the result of XOR operation for each element
    }

    return 0;
}

