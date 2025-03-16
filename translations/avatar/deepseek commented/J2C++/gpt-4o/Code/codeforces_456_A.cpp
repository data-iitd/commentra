#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> md; // Vector to store some data
    int n; // Number of elements
    cin >> n; // Read the number of elements
    vector<int> a(n); // Vector 'a' to store first set of values
    vector<int> b(n); // Vector 'b' to store second set of values
    int temp = 0; // Variable to temporarily store a value
    int q = 0; // Variable to store a value for comparison
    int w = 0; // Variable to store the maximum value of 'a'
    int e = 0; // Variable to store a value for comparison
    bool f = false; // Boolean variable to determine the output

    // Loop through each element
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read the value for vector 'a'
        cin >> b[i]; // Read the value for vector 'b'
        if (temp < a[i]) { // Check if the current 'a' value is greater than the stored 'temp' value
            if (q > b[i]) { // Check if the stored 'q' value is greater than the current 'b' value
                f = true; // Set 'f' to true if the condition is met
            }
            q = b[i]; // Update 'q' with the current 'b' value
            temp = a[i]; // Update 'temp' with the current 'a' value
        }
        if (temp > a[i]) { // Check if the current 'a' value is less than the stored 'temp' value
            if (q < b[i]) { // Check if the stored 'q' value is less than the current 'b' value
                f = true; // Set 'f' to true if the condition is met
            }
            q = b[i]; // Update 'q' with the current 'b' value
            temp = a[i]; // Update 'temp' with the current 'a' value
        }
        if (a[i] > w) { // Check if the current 'a' value is greater than the stored 'w' value
            w = a[i]; // Update 'w' with the current 'a' value
            if (b[i] < e) { // Check if the current 'b' value is less than the stored 'e' value
                f = true; // Set 'f' to true if the condition is met
            }
            e = b[i]; // Update 'e' with the current 'b' value
        }
        if (a[i] < w) { // Check if the current 'a' value is less than the stored 'w' value
            if (b[i] > e) { // Check if the current 'b' value is greater than the stored 'e' value
                f = true; // Set 'f' to true if the condition is met
            }
        }
    }

    // Determine and print the output based on the value of 'f'
    if (f) {
        cout << "Happy Alex" << endl; // Print "Happy Alex" if 'f' is true
    } else {
        cout << "Poor Alex" << endl; // Print "Poor Alex" if 'f' is false
    }

    return 0;
}

// <END-OF-CODE>
