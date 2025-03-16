#include <iostream>
using namespace std;

int main()
{
    // Declare two integer variables A and B
    int A, B;

    // Read input values for A and B from the user
    cin >> A >> B;

    // Check if A is between 6 (inclusive) and 13 (exclusive)
    if (A < 13 && A >= 6) {
        // If true, output half of B
        cout << B / 2 << endl;
    }

    // Check if A is less than 6
    if (A < 6) {
        // If true, output 0
        cout << 0 << endl;
    }

    // Check if A is greater than or equal to 13
    if (A >= 13) {
        // If true, output the value of B
        cout << B << endl;        
    }

    return 0; // Return 0 to indicate successful completion of the program
}
