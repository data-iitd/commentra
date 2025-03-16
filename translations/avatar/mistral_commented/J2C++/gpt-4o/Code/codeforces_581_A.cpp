#include <iostream> // Including the iostream library for input and output

using namespace std; // Using the standard namespace

int main() { // Starting the main function
    int a, b; // Declaring two integer variables a and b

    cin >> a; // Reading the first integer input and assigning it to variable a
    cin >> b; // Reading the second integer input and assigning it to variable b

    int count = 0; // Initializing the count variable to 0

    while (true) { // Starting an infinite loop
        if (a > 0 && b > 0) { // Checking if both a and b are greater than 0
            count++; // Incrementing the count variable if both conditions are true
            a--; // Decrementing the value of variable a by 1
            b--; // Decrementing the value of variable b by 1
        } else { // If either a or b is not greater than 0
            break; // Exiting the loop
        }
    }

    int ans = a / 2 + b / 2; // Calculating the answer by dividing each number by 2 and summing the results

    cout << count << " " << ans << endl; // Printing the count and answer to the console

    return 0; // Returning 0 to indicate successful completion of the program
}

// <END-OF-CODE>
