
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    // Declare variables
    int n, i; // n: number of elements, i: loop index
    vector<int> h; // Vector to store heights
    int max = -1; // Variable to track the maximum height
    int flag = 0; // Flag to indicate if the condition is met

    // Read the number of elements
    cin >> n;

    // Loop to read heights and determine the maximum height
    for(i = 0; i < n; i++) {
        int temp; // Temporary variable to store input
        cin >> temp; // Read height into the vector
        h.push_back(temp); // Add height to the vector
        
        // Update maximum height if current height is greater
        if(max < temp) max = temp;

        // Check if the difference between max height and current height is 2 or more
        if(max - temp >= 2) flag = 1; // Set flag if condition is met
    }

    // Output result based on the flag value
    if(flag == 1) 
        cout << "No" << endl; // If flag is set, print "No"
    else 
        cout << "Yes" << endl; // If flag is not set, print "Yes"

    return 0; // Exit the program
}
