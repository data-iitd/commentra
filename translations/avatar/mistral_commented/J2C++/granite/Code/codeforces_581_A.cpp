

#include <iostream> // Importing the standard input/output stream objects

using namespace std ; // Using the standard namespace

int main ( ) { // Starting the main method
    int a, b ; // Declaring two integer variables a and b

    cin >> a >> b ; // Reading the first and second integer inputs and assigning them to variables a and b

    int count = 0 ; // Initializing the count variable to 0

    while ( true ) { // Starting an infinite loop
        if ( a > 0 && b > 0 ) { // Checking if both a and b are greater than 0
            count ++ ; // Incrementing the count variable if both conditions are true
            a -- ; // Decrementing the value of variable a by 1
            b -- ; // Decrementing the value of variable b by 1
        } else { // If either a or b is not greater than 0
            break ; // Exiting the loop
        }
    }

    int ans = a / 2 + b / 2 ; // Calculating the answer by dividing each number by 2 and summing the results

    cout << count << " " << ans << endl ; // Printing the count and answer to the console

    return 0 ; // Returning 0 to indicate successful program execution
}

These comments should provide a clear understanding of what each part of the code does.