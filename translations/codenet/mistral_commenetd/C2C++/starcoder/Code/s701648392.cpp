
#include<iostream>
// Include the standard input/output library header file

using namespace std;
// Use the standard namespace

int main()
{
    int a, b, c;
    // Declare three integer variables: a, b, and c

    cin >> a >> b >> c;
    // Use the cin object to read three integers from the standard input
    // and assign them to the variables a, b, and c respectively

    if(a<b && b<c)
    {
        cout << "Yes" << endl;
        // If the condition a < b && b < c is true, print the string "Yes"
        // followed by a newline character to the standard output
    }
    else
    {
        cout << "No" << endl;
        // If the condition a < b && b < c is false, print the string "No"
        // followed by a newline character to the standard output
    }

    return 0;
    // End the main function with a return statement of 0, indicating that
    // the program has run successfully
}

