
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; // Declare variable 'n' to store the number of elements
    int temp = 0; // Declare variable 'temp' to temporarily store a value
    int q = 0; // Declare variable 'q' to store a value for comparison
    int w = 0; // Declare variable 'w' to store the maximum value of 'a'
    int e = 0; // Declare variable 'e' to store a value for comparison
    bool f = false; // Declare boolean variable 'f' to determine the output
    vector<int> a; // Declare vector 'a' to store first set of values
    vector<int> b; // Declare vector 'b' to store second set of values

    // Read the number of elements
    cin >> n;

    // Loop through each element
    for (int i = 0; i < n; i++) {
        int x; // Declare variable 'x' to store the value for array 'a'
        int y; // Declare variable 'y' to store the value for array 'b'

        // Read the value for array 'a'
        cin >> x;
        a.push_back(x);

        // Read the value for array 'b'
        cin >> y;
        b.push_back(y);

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
    if (f == true) {
        cout << "Happy Alex" << endl; // Print "Happy Alex" if 'f' is true
    } else {
        cout << "Poor Alex" << endl; // Print "Poor Alex" if 'f' is false
    }

    return 0;
}

