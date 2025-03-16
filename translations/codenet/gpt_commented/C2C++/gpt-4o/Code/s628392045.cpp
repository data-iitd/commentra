#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Declare variables
    int n; // n: number of elements
    std::vector<int> h; // Vector to store heights
    int max = -1; // Variable to track the maximum height
    bool flag = false; // Flag to indicate if the condition is met

    // Read the number of elements
    std::cin >> n;
    h.resize(n); // Resize the vector to hold n elements

    // Loop to read heights and determine the maximum height
    for(int i = 0; i < n; i++) {
        // Read height into the vector
        std::cin >> h[i];
        
        // Update maximum height if current height is greater
        if(max < h[i]) max = h[i];

        // Check if the difference between max height and current height is 2 or more
        if(max - h[i] >= 2) flag = true; // Set flag if condition is met
    }

    // Output result based on the flag value
    if(flag) 
        std::cout << "No" << std::endl; // If flag is set, print "No"
    else 
        std::cout << "Yes" << std::endl; // If flag is not set, print "Yes"

    return 0; // Exit the program
}

// <END-OF-CODE>
