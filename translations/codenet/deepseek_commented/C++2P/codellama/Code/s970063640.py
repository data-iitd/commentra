#include <iostream>  # Include the input-output stream library for input and output operations
#include <algorithm> # Include the algorithm library for sorting functions
using namespace std; # Use the standard namespace to avoid prefixing standard library names with 'std::'

int main():
    int n; # Declare an integer variable to store the number of elements
    cin >> n; # Read the value of n from the standard input
    int a; # Declare an integer variable to store the value of a
    cin >> a; # Read the value of a from the standard input
    int sum = 0; # Initialize a variable to store the sum of the last 'a' elements
    int s[n]; # Declare an array to store the elements
    for(int i = 0; i < n; i++): # Loop to read 'n' elements into the array 's'
        cin >> s[i]; # Read the elements from the standard input
    sort(s, s + n); # Sort the array 's' in ascending order
    for(int i = n - 1; i > n - a - 1; i--): # Loop to calculate the sum of the last 'a' elements
        sum += s[i]; # Add the value of the current element to the sum
    cout << sum << endl; # Print the calculated sum to the standard output
    return 0; # Return 0 to indicate successful execution

