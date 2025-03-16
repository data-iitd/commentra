#include <iostream> // Include the iostream library for input and output
#include <vector>   // Include the vector library for using vectors
using namespace std; // Use the standard namespace

int main() {
    int n; // Declare an integer variable 'n'
    cin >> n; // Read the number of elements (n) from the user
    vector<int> a(n); // Initialize a vector 'a' of size n to store the elements
    int r = 0; // Initialize a variable 'r' to store the result of XOR operation

    // Read the elements of the vector 'a' from the user and perform XOR operation on each element
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read each element into the vector
        r ^= a[i]; // Perform XOR operation with the current element
    }

    // Print the result of XOR operation for each element in the vector 'a'
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " "; // Print a space before each element except the first one
        cout << (r ^ a[i]); // Print the result of XOR operation for each element
    }
    cout << endl; // Print a newline at the end
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
