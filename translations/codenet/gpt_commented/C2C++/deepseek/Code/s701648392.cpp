#include<iostream>
using namespace std;

int main()
{
    // Declare three integer variables to hold the input values
    int a, b, c;

    // Read three integers from the user
    cin >> a >> b >> c;

    // Check if the first number is less than the second and the second is less than the third
    if(a < b && b < c)
    {
        // If the condition is true, print "Yes"
        cout << "Yes" << endl;
    }
    else
    {
        // If the condition is false, print "No"
        cout << "No" << endl;
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}
