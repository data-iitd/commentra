#include <iostream> // Importing the iostream package for using cout and cin
#include <vector> // Importing the vector package for using vectors

using namespace std; // Using the standard namespace

int main() {
    // Creating a vector to store the input values
    vector<int> a; // Vector to store the input values
    
    // Loop to process multiple test cases until there is no more input
    while (cin >> a) {
        // Read the number of elements
        int n = a.size(); // Number of elements in the vector 'a'
        
        // Initialize two vectors to store the input values and a status flag
        vector<int> b(n, 0); // Vector to store the input values
        vector<int> c(n, 0); // Vector to track which elements have been processed
        
        // Initialize a counter for the number of steps taken
        int s = -1; // Start with -1 to account for the first increment
        
        // Initialize variables for processing
        int tem = 1; // Variable to alternate between forward and backward processing
        int q = 0; // Counter for the number of processed elements
        
        // Loop until all elements have been processed
        while (q != n) {
            s++; // Increment the step counter
            
            // Check the direction of processing based on 'tem'
            if (tem == 1) {
                // Process elements from the start of the vector
                for (int i = 0; i < n; i++) {
                    // If the current element can be processed
                    if (a[i] <= q && c[i] == 0) {
                        c[i] = 1; // Mark the element as processed
                        q++; // Increment the processed counter
                    }
                }
                tem = 0; // Switch to backward processing for the next iteration
            } else {
                // Process elements from the end of the vector
                for (int i = n - 1; i >= 0; i--) {
                    // If the current element can be processed
                    if (a[i] <= q && c[i] == 0) {
                        c[i] = 1; // Mark the element as processed
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

