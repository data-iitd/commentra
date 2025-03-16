#include<iostream>
using namespace std;

// Declare global variables
int num1, math[2000+1];

int main() {
    int a, num2, ans, sum = 0; // Declare variables for input and calculations
    int i, j;

    // Initialize the first element of the math array to 1
    math[0] = 1;

    // Read the number of elements for the first set
    cin >> num1;
    
    // Loop to read each element and update the possible sums
    for(i = 0; i < num1; i++) {
        cin >> a; // Read the current element
        sum += a; // Update the total sum
        
        // Update the math array to reflect the new possible sums
        for(j = sum - a; j >= 0; j--) {
            if(math[j] == 1) {
                math[j + a] = 1; // Mark the new sum as possible
            }
        }
    }

    // Read the number of queries for possible sums
    cin >> num2;
    
    // Loop to check if each queried sum is possible
    for(i = 0; i < num2; i++) {
        cin >> ans; // Read the queried sum
        // Check if the queried sum is possible and print the result
        math[ans] == 1? cout << "yes\n" : cout << "no\n";
    }

    return 0; // End of the program
}

