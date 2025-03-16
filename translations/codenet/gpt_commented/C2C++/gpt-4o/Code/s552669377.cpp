#include <iostream>
using namespace std;

int main() {
    // Declare variables
    int i, n, tmp; // i for loop iteration, n for number of inputs, tmp for temporary input storage
    long long int min = 1000000, max = -1000000, sum = 0; // Initialize min, max, and sum

    // Read the number of integers to be processed
    cin >> n;
    
    // Loop to read n integers
    for(i = 0; i < n; i++) {
        // Read the next integer
        cin >> tmp;
        
        // Update min if the current number is smaller
        if(min > tmp) min = tmp;
        
        // Update max if the current number is larger
        if(max < tmp) max = tmp;
        
        // Add the current number to the sum
        sum += tmp;
    }

    // Print the minimum, maximum, and sum of the numbers
    cout << min << " " << max << " " << sum << endl;

    return 0; // Indicate that the program ended successfully
}

// <END-OF-CODE>
