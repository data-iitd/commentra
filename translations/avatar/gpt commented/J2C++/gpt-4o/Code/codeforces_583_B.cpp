#include <iostream> // For input and output
#include <vector>   // For using vectors
using namespace std;

int main() {
    // Loop to process multiple test cases until there is no more input
    while (true) {
        int n;
        cin >> n; // Read the number of elements
        
        if (cin.eof()) break; // Break the loop if there is no more input
        
        vector<int> a(n); // Vector to store the input values
        vector<int> b(n, 0); // Vector to track which elements have been processed
        
        int s = -1; // Start with -1 to account for the first increment
        
        // Read the input values into vector 'a'
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // Read each integer into vector 'a'
        }
        
        // Initialize variables for processing
        int tem = 1; // Variable to alternate between forward and backward processing
        int q = 0; // Counter for the number of processed elements
        
        // Loop until all elements have been processed
        while (q != n) {
            s++; // Increment the step counter
            
            // Check the direction of processing based on 'tem'
            if (tem == 1) {
                // Process elements from the start of the array
                for (int i = 0; i < n; i++) {
                    // If the current element can be processed
                    if (a[i] <= q && b[i] == 0) {
                        b[i] = 1; // Mark the element as processed
                        q++; // Increment the processed counter
                    }
                }
                tem = 0; // Switch to backward processing for the next iteration
            } else {
                // Process elements from the end of the array
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

// <END-OF-CODE>
