#include <iostream> // Including the iostream library for input and output
#include <algorithm> // Including the algorithm library for std::min and std::max

using namespace std; // Using the standard namespace

int sub(int a, int b) { // Defining the sub function for subtracting two numbers
    int min = std::min(a, b); // Finding the smaller number
    int max = std::max(a, b); // Finding the larger number
    int result = 0; // Initializing the result variable

    while (min > 0) { // Iterating as long as the smaller number is greater than zero
        result += max / min; // Adding the quotient of the larger number divided by the smaller number to the result
        max = max % min; // Updating the larger number by taking the remainder of the larger number with the smaller number
        int curr_min = std::min(min, max); // Finding the current smaller number
        int curr_max = std::max(min, max); // Finding the current larger number
        min = curr_min; // Updating the smaller number
        max = curr_max; // Updating the larger number
    }

    return result; // Returning the final result
}

int main() { // Defining the main function
    int n; // Variable to store the number of test cases
    cin >> n; // Reading the number of test cases from the user

    for (int i = 0; i < n; i++) { // Iterating through each test case
        int a, b; // Variables to store the two numbers
        cin >> a >> b; // Reading the two numbers from the user
        cout << sub(a, b) << endl; // Printing the result of subtracting 'b' from 'a'
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
