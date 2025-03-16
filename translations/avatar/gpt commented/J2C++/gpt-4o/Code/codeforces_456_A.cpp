#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Declare a vector to hold some data (not used in this code)
    vector<int> md;

    // Create a variable for input
    int n;
    
    // Read the number of pairs (n)
    cin >> n;
    
    // Initialize two vectors to hold the pairs of integers
    vector<int> a(n);
    vector<int> b(n);
    
    // Temporary variables for processing
    int temp = 0; // To track the current maximum value in array a
    int q = 0;    // To track the corresponding value in array b
    int w = 0;    // To track the maximum value in array a
    int e = 0;    // To track the corresponding value in array b
    bool f = false; // Flag to determine if the condition for "Happy Alex" is met

    // Loop to read pairs of integers into vectors a and b
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read value for array a
        cin >> b[i]; // Read value for array b
        
        // Check if the current value in a is greater than the previous maximum
        if (temp < a[i]) {
            // If the current b value is less than the previous b value, set flag to true
            if (q > b[i]) {
                f = true;
            }
            // Update q and temp with current values
            q = b[i];
            temp = a[i];
        }
        // Check if the current value in a is less than the previous maximum
        if (temp > a[i]) {
            // If the current b value is greater than the previous b value, set flag to true
            if (q < b[i]) {
                f = true;
            }
            // Update q and temp with current values
            q = b[i];
            temp = a[i];
        }
        // Update the maximum value in a and check conditions for b
        if (a[i] > w) {
            w = a[i]; // Update maximum value in a
            // If the current b value is less than the previous maximum b, set flag to true
            if (b[i] < e) {
                f = true;
            }
            e = b[i]; // Update corresponding value in b
        }
        // Check if the current value in a is less than the maximum value
        if (a[i] < w) {
            // If the current b value is greater than the previous maximum b, set flag to true
            if (b[i] > e) {
                f = true;
            }
        }
    }

    // Output the result based on the flag value
    if (f) {
        cout << "Happy Alex" << endl; // Condition met for "Happy Alex"
    } else {
        cout << "Poor Alex" << endl;   // Condition not met, output "Poor Alex"
    }

    return 0;
}

// <END-OF-CODE>
