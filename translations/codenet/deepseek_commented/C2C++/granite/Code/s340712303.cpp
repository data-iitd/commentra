
#include<iostream> // Include the standard input/output library
#define N 2000 // Define a constant N for the size of the array
using namespace std; // Use the standard namespace

int main(){ // Main function is the entry point of the program
    int a, num2, ans, sum = 0, math[N+1]; // Declare local variables a, num2, ans, sum, and math (shadowing the global variable)
    int i, j; // Declare loop variables

    math[0] = 1; // Initialize the first element of math to 1
    
    cin >> num1; // Read the number of elements in the first set of inputs
    for(i = 0; i < num1; i++){ // Loop through num1 times
        cin >> a; // Read each element
        sum += a; // Update the sum
        for(j = sum - a; j >= 0; j--){ // Loop to mark possible sums
           if(math[j] == 1) math[j + a] = 1; // If the sum j is possible, mark sum j+a as possible
        }
    }

    cin >> num2; // Read the number of elements in the second set of inputs
    for(i = 0; i < num2; i++){ // Loop through num2 times
        cin >> ans; // Read each element
        math[ans] == 1? cout << "yes\n" : cout << "no\n"; // Check if the sum is possible and print the result
    }

    return 0; // Return 0 to indicate successful execution
}

