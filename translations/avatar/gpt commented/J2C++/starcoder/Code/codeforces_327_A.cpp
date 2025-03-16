#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    cin >> ws;
    cin.sync();
    // Check if there is input available
    if (cin.peek()!= cin.eof()) {
        // Read the size of the array
        int n;
        cin >> n;
        // Initialize the array to hold n integers
        vector<int> arr(n);
        
        // Populate the array with user input
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        // Initialize max to the smallest possible integer value
        int max = INT_MIN;
        
        // Iterate through all possible subarrays
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Initialize a temporary variable to track the index for brr
                int x = 0;
                // Create a copy of the original array
                vector<int> brr(n);
                for (int k : arr)
                    brr[x++] = k;
                
                // Flip the values in the subarray from index i to j
                for (int k = i; k <= j; k++) {
                    if (brr[k] == 0)
                        brr[k] = 1; // Change 0 to 1
                    else
                        brr[k] = 0; // Change 1 to 0
                }
                
                // Count the number of 1's in the modified array
                int count = checkNo(brr);
                
                // Update max if the current count is greater
                if (count > max)
                    max = count;
            }
        }
        
        // Handle the case when there is only one element in the array
        if (n == 1) {
            if (arr[0] == 1)
                cout << 0 << endl; // Output 0 if the single element is 1
            else
                cout << 1 << endl; // Output 1 if the single element is 0
        } else {
            // Output the maximum count of 1's found
            cout << max << endl;
        }
    }
    return 0;
}

// Method to count the number of 1's in the given array
int checkNo(vector<int> brr) {
    int val = 0;
    // Count each occurrence of 1 in the array
    for (int i : brr)
        if (i == 1)
            ++val;
    return val; // Return the total count of 1's
}

