#include <iostream>
using namespace std;

int main() {
    // Declare variables for loop index, input values, and a product variable
    int i, a, b, s;
    // Array to count occurrences of each number (1 to 4)
    int count[4];

    // Initialize the count array to zero
    for(i = 0; i < 4; i++) 
        count[i] = 0;

    // Read pairs of integers and update their counts
    for(i = 0; i < 3; i++) {
        // Read two integers from input
        cin >> a >> b;
        // Increment the count for each integer read
        count[a - 1]++;
        count[b - 1]++;
    }

    // Initialize the product variable
    s = 1;
    // Calculate the product of counts
    for(i = 0; i < 4; i++) 
        s *= count[i];

    // Check if the product equals 4, indicating each number appears at least once
    if(s == 4) 
        cout << "YES" << endl; // Output YES if all numbers are present
    else 
        cout << "NO" << endl;  // Output NO if any number is missing

    return 0; // End of the program
}
