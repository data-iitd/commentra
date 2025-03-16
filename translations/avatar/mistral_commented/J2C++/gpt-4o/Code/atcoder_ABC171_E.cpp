#include <iostream> // Including iostream for input and output
#include <vector>   // Including vector for dynamic array

using namespace std;

int main() {
    // Initializing the variable to read the number of elements in the array
    int n;
    cin >> n;

    // Creating a vector 'a' to store the input elements
    vector<int> a(n);

    // Initializing the XOR result to 0
    int r = 0;

    // Reading the elements of the array 'a' from the user input and performing XOR operation
    for (int i = 0; i < n; i++) {
        // Reading the next integer from the user input
        cin >> a[i];

        // Performing XOR operation between 'r' and the current element 'a[i]' and updating the value of 'r'
        r ^= a[i];
    }

    // Printing the XOR result
    for (int i = 0; i < n; i++) {
        // If it's not the first element, print a space before the current element
        if (i != 0)
            cout << " ";

        // Printing the XOR result of 'r' and the current element 'a[i]'
        cout << (r ^ a[i]);
    }

    return 0;
}

// <END-OF-CODE>
