
#include <iostream>
using namespace std;
// The main function is the entry point of the program
int main(void) {
    long sum = 0; // Initialize sum to 0
    int m, n, i, min, max; // Declare and initialize variables
    
    // Read the number of integers to be input from the user
    cin >> n;
    
    // Iterate through each integer input
    for(i=0; i<n; i++){
        cin >> m; // Read an integer input and assign it to m
        sum += m; // Add the current integer input to the sum
        
        // Update min and max values if the current input is smaller or larger
        if(min > m){
            min = m; // Set min to the current input if it's smaller
        }
        if(max < m){
            max = m; // Set max to the current input if it's larger
        }
    }
    
    // Print the minimum value, maximum value, and sum of the input integers
    cout << min << " " << max << " " << sum << endl;
}

