#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic array
#include <cmath>    // Including the cmath library for mathematical functions
#include <string>   // Including the string library for string manipulation

using namespace std; // Using the standard namespace

int main() {
    int n; // Variable to store the number of test cases
    cin >> n; // Reading the number of test cases from standard input

    vector<char> ch; // Vector to store characters dynamically
    int s1 = 0, s2 = 0; // Initializing two variables to keep track of the sum of x and y coordinates respectively
    int flag = 0; // Flag to indicate if the difference exceeds the limit

    // Reading input for each test case
    for (int i = 0; i < n; i++) {
        int x, y; // Variables to store the x and y values for the current test case
        cin >> x >> y; // Reading the values of x and y

        int temp1 = s1 + x; // Calculating the sum of s1 and x
        int temp2 = s2 + y; // Calculating the sum of s2 and y

        // Checking if the difference between the sums is within the limit of 500
        if (abs(temp1 - temp2) <= 500) {
            s1 += x; // Updating the value of s1
            ch.push_back('A'); // Adding 'A' to the character vector ch
            continue; // Skipping the rest of the loop and moving to the next iteration
        }

        // Checking if the difference between the absolute values of the sums is within the limit of 500
        if (abs(temp1 - s2) <= 500) {
            s2 += y; // Updating the value of s2
            ch.push_back('G'); // Adding 'G' to the character vector ch
            continue; // Skipping the rest of the loop and moving to the next iteration
        }

        flag = 1; // Setting the flag to 1 if the difference between the sums is greater than 500
        break; // Exiting the loop if the difference is greater than 500
    }

    // Checking if the flag is set to 1, indicating that the difference between the sums is greater than 500 for the current test case
    if (flag == 1)
        cout << -1 << endl; // Printing -1 if the difference is greater than 500
    else {
        string ans(ch.begin(), ch.end()); // Converting the character vector ch to a string ans
        cout << ans << endl; // Printing the string ans as the answer for the current test case
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
