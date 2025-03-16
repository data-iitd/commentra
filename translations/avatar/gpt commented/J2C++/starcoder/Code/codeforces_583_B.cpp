#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of test cases
    int t;
    cin >> t;
    
    // Loop to process each test case
    while (t--) {
        // Read the number of elements
        int n;
        cin >> n;
        
        // Initialize two vectors to store the input values and a status flag
        vector<int> a(n); // Vector to store the input values
        vector<int> b(n); // Vector to track which elements have been processed
        
        // Initialize a counter for the number of steps taken
        int s = -1; // Start with -1 to account for the first increment
        
        // Read the input values into vector 'a' and initialize vector 'b' to 0
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // Read each integer into vector 'a'
            b[i] = 0; // Initialize the status vector 'b' to 0 (not processed)
        }
        
        // Initialize variables for processing
        int tem = 1; // Variable to alternate between forward and backward processing
        int q = 0; // Counter for the number of processed elements
        
        // Loop until all elements have been processed
        while (q!= n) {
            s++; // Increment the step counter
            
            // Check the direction of processing based on 'tem'
            if (tem == 1) {
                // Process elements from the start of the vector
                for (int i = 0; i < n; i++) {
                    // If the current element can be processed
                    if (a[i] <= q && b[i] == 0) {
                        b[i] = 1; // Mark the element as processed
                        q++; // Increment the processed counter
                    }
                }
                tem = 0; // Switch to backward processing for the next iteration
            } else {
                // Process elements from the end of the vector
                for (int i = n - 1; i >= 0; i--) {
                    // If the current element can be processed
                    if (a[i] <= q && b[i] == 0) {
                        b[i] = 1; // Mark the element as processed
                        q++; // Increment the processed counter
                    }
                }
                tem = 1; // Switch to forward processing for the next iteration
            }
        }
        
        // Output the total number of steps taken to process all elements
        cout << s << endl;
    }
    
    return 0;
}

