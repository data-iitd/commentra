#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Create a vector to store the input integers
    vector<int> a;
    
    // Read the number of elements in the array
    int n;
    cin >> n;
    
    // Initialize a flag to indicate if a valid triplet is found
    int f = 0;
    
    // Read n integers from the input and store them in the vector
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }
    
    // Initialize variables for indexing
    int k = 0, j = 0, i = 0;
    
    // Iterate through each element in the vector
    for (k = 0; k < n; k++) {
        // Store the current element to check against pairs
        int t = a[k];
        
        // Check for pairs in the vector that sum up to the current element
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                // Ensure we are not using the same element twice
                if (i != j && t == (a[i] + a[j])) {
                    // Set the flag to indicate a valid triplet is found
                    f = 1;
                    break;
                }
            }
            // Break out of the loop if a valid pair is found
            if (f == 1) break;
        }
        // Break out of the outer loop if a valid triplet is found
        if (f == 1) break;
    }
    
    // Output the result: indices of the triplet or -1 if not found
    if (f == 1)
        cout << (k + 1) << " " << (j + 1) << " " << (i + 1) << endl;
    else
        cout << "-1" << endl;

    return 0;
}

// <END-OF-CODE>
