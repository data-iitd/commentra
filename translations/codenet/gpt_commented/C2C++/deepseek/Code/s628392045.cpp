#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Declare variables
    int n, i; // n: number of elements, i: loop index
    vector<int> h(100001); // Vector to store heights
    int max = -1; // Variable to track the maximum height
    bool flag = false; // Flag to indicate if the condition is met

    // Read the number of elements
    cin >> n;

    // Loop to read heights and determine the maximum height
    for(i = 0; i < n; i++) {
        // Read height into the vector
        cin >> h[i];
        
        // Update maximum height if current height is greater
        if(max < h[i]) max = h[i];

        // Check if the difference between max height and current height is 2 or more
        if(max - h[i] >= 2) flag = true; // Set flag if condition is met
    }

    // Output result based on the flag value
    if(flag) 
        cout << "No" << endl; // If flag is set, print "No"
    else 
        cout << "Yes" << endl; // If flag is not set, print "Yes"

    return 0; // Exit the program
}
