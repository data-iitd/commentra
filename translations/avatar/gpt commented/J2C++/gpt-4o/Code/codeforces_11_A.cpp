#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays

using namespace std;

int main() {
    // Reading the number of elements (n) and the divisor (d) from user input
    int n, d;
    cin >> n >> d;
    
    // Initializing a vector to hold the numbers
    vector<int> nums(n);
    
    // Reading n integers from user input and storing them in the nums vector
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // Initializing result variable to count the total adjustments made
    int result = 0;
    int a = 0; // Variable to hold the difference between consecutive elements
    
    // Looping through the nums vector starting from the second element
    for (int i = 1; i < n; i++) {
        // Calculating the difference between the previous and current element
        a = (nums[i - 1] - nums[i]);
        
        // If the difference is non-negative, adjustments are needed
        if (a >= 0) {
            // Calculating how many times we can adjust the current element
            result += a / d + 1; 
            
            // Adjusting the current element to maintain the required condition
            nums[i] += (a / d + 1) * d; 
        }
    }
    
    // Printing the total number of adjustments made
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
