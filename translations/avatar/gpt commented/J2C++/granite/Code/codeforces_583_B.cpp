
#include <iostream> // Importing the standard input/output stream
#include <vector> // Importing the vector container

using namespace std;

int main() {
    // Creating a vector to store the input values
    vector<int> a;
    
    // Loop to process multiple test cases until there is no more input
    while (cin >> a.size()) {
        // Initialize a vector to track which elements have been processed
        vector<int> b(a.size(), 0); // Initialize the status vector 'b' to 0 (not processed)
        
        // Initialize variables for processing
        int tem = 1; // Variable to alternate between forward and backward processing
        int q = 0; // Counter for the number of processed elements
        int s = -1; // Start with -1 to account for the first increment
        
        // Loop until all elements have been processed
        while (q!= a.size()) {
            s++; // Increment the step counter
            
            // Check the direction of processing based on 'tem'
            if (tem == 1) {
                // Process elements from the start of the vector
                for (int i = 0; i < a.size(); i++) {
                    // If the current element can be processed
                    if (a[i] <= q && b[i] == 0) {
                        b[i] = 1; // Mark the element as processed
                        q++; // Increment the processed counter
                    }
                }
                tem = 0; // Switch to backward processing for the next iteration
            } else {
                // Process elements from the end of the vector
                for (int i = a.size() - 1; i >= 0; i--) {
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
