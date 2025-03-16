
#include <iostream>  // Importing the iostream library for input and output

using namespace std;  // Using the standard namespace

int main() {  // Main function to start the program
    long x, y, a, b, j = 2, i, x1 = 0, y1 = 0, c = 0;  // Declaring variables
    bool ans = true;  // Declaring a boolean variable to keep track of the result

    cin >> x >> y >> a >> b;  // Reading the input values from the user

    c = max(x, y);  // Finding the maximum value between x and y

    if (c > b) {  // Checking if the maximum value is greater than b
        cout << "0";  // If true, printing 0 and setting ans to false
        ans = false;
    }

    while (c % min(x, y)!= 0 && ans) {  // Loop to find the greatest common divisor (GCD)
        if (x > y) {  // If x is greater than y
            c = x * j;  // Multiplying x by j and updating c
            j++;  // Incrementing j
        } else {
            c = y * j;  // Multiplying y by j and updating c
            j++;  // Incrementing j
        }

        if (c > b) {  // Checking if the current value of c is greater than b
            cout << "0";  // If true, printing 0 and setting ans to false
            ans = false;
            break;  // Exiting the loop
        }
    }

    if (ans) {  // If the GCD has been found
        long count = 0;  // Declaring a counter variable
        i = a;  // Starting the loop from a

        for (i = a; i <= b; i++) {  // Loop to find the number of times c divides i
            if (i % c == 0) break;  // If i is divisible by c, breaking the loop
        }

        if (i!= b + 1) {  // Checking if the last number in the range is divisible by c
            cout << ((b - i) / c) + 1;  // Printing the result
        } else {
            cout << "0";  // If the last number is not divisible by c, printing 0
        }
    }

    return 0;  // Returning 0 to indicate successful execution
}

