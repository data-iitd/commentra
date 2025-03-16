#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n; // Read the first integer n, which represents the number of elements in the arrays a and b
    vector<int> a(n); // Create a vector a with a length of n
    vector<int> b(n); // Create a vector b with a length of n
    int temp = 0; // Initialize a variable temp to 0
    int q = 0; // Initialize a variable q to 0
    int w = numeric_limits<int>::min(); // Initialize a variable w to the smallest possible integer value
    int e = numeric_limits<int>::min(); // Initialize a variable e to the smallest possible integer value
    bool f = false; // Initialize a boolean variable f to false

    for (int i = 0; i < n; i++) { // Start a for loop that iterates through the elements of arrays a and b
        cin >> a[i]; // Read the next integer value for a[i]
        cin >> b[i]; // Read the next integer value for b[i]

        if (temp < a[i]) { // If the current value of temp is less than a[i]
            if (q > b[i]) { // Check if the condition q > b[i] is satisfied
                f = true; // If it is, set f to true
            }
            q = b[i]; // Update q with the new value of b[i]
            temp = a[i]; // Update temp with the new value of a[i]
        }

        if (temp > a[i]) { // If the current value of temp is greater than a[i]
            if (q < b[i]) { // Check if the condition q < b[i] is satisfied
                f = true; // If it is, set f to true
            }
            q = b[i]; // Update q with the new value of b[i]
            temp = a[i]; // Update temp with the new value of a[i]
        }

        if (a[i] > w) { // If the current value of a[i] is greater than w
            w = a[i]; // Update w with the new value of a[i]
            if (b[i] < e) { // Check if the condition b[i] < e is satisfied
                f = true; // If it is, set f to true
            }
        }

        if (a[i] < w) { // If the current value of a[i] is less than w
            if (b[i] > e) { // Check if the condition b[i] > e is satisfied
                f = true; // If it is, set f to true
            }
        }
    }

    if (f) { // After the loop finishes, check the value of the boolean variable f
        cout << "Happy Alex" << endl; // If it is true, print the message "Happy Alex"
    } else {
        cout << "Poor Alex" << endl; // Otherwise, print the message "Poor Alex"
    }

    return 0;
}

// <END-OF-CODE>
