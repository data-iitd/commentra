#include<iostream>

using namespace std;

int main()
{
    // Declare two integer variables to hold the input values
    int a, b;

    // Read two integer values from user input
    cin >> a >> b;

    // If the first input value is 1, set it to 14
    if (a == 1)
        a = 14;

    // If the second input value is 1, set it to 14
    if (b == 1)
        b = 14;

    // Compare the two values and print the result
    if (a < b)
        // If 'a' is less than 'b', print "Bob"
        cout << "Bob" << endl;
    else if (a > b)
        // If 'a' is greater than 'b', print "Alice"
        cout << "Alice" << endl;
    else
        // If 'a' is equal to 'b', print "Draw"
        cout << "Draw" << endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}

