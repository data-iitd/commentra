#include<iostream> // Step 1: Include the standard input/output library.

using namespace std; // Step 2: Use the standard namespace.

int main() // Step 3: Define the main function.
{
    int a, b, s; // Step 4: Declare three integer variables: a, b, and s.

    cin >> a >> b; // Step 5: Read two integers from the user input and store them in variables a and b.

    s = (a*b) - (a + b) + 1; // Step 6: Calculate the value of s using the formula (a*b) - (a + b) + 1.

    cout << s << endl; // Step 7: Print the value of s.
}

