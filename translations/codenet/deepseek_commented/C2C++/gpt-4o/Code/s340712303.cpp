#include <iostream> // Include the iostream library for input/output
#include <vector>   // Include the vector library for dynamic arrays
using namespace std; // Use the standard namespace

#define N 2000 // Define a constant N for the size of the array

int num1; // Declare a global variable num1
vector<int> math(N + 1, 0); // Declare a global vector math initialized to 0

int main() { // Main function is the entry point of the program
    int a, num2, ans, sum = 0; // Declare local variables a, num2, ans, and sum
    math[0] = 1; // Initialize the first element of math to 1

    cin >> num1; // Read the number of elements in the first set of inputs
    for (int i = 0; i < num1; i++) { // Loop through num1 times
        cin >> a; // Read each element
        sum += a; // Update the sum
        for (int j = sum - a; j >= 0; j--) { // Loop to mark possible sums
            if (math[j] == 1) math[j + a] = 1; // If the sum j is possible, mark sum j+a as possible
        }
    }

    cin >> num2; // Read the number of elements in the second set of inputs
    for (int i = 0; i < num2; i++) { // Loop through num2 times
        cin >> ans; // Read each element
        cout << (math[ans] == 1 ? "yes" : "no") << endl; // Check if the sum is possible and print the result
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
