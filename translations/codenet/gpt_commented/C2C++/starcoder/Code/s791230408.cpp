#include <iostream>

using namespace std;

int main()
{
    // Declare variables for input values and control variables
    int a, b, c, i, j, k;
    int max;

    // Read the number of test cases
    cin >> j;

    // Loop through each test case
    for(i = 0; i < j; i++) {
        // Read three integers a, b, and c
        cin >> a;
        cin >> b;
        cin >> c;

        // Initialize max to the value of a
        max = a;
        k = 0; // k will track which number is the largest

        // Determine the maximum value among a, b, and c
        if(max <= b) {
            max = b; // Update max to b if b is greater
            k = 1; // Set k to indicate b is the largest
        }
        if(max <= c) {
            max = c; // Update max to c if c is greater
            k = 2; // Set k to indicate c is the largest
        }

        // Square the maximum value and the other two values
        max = max * max;
        a = a * a;
        b = b * b;
        c = c * c;

        // Check if the squared values satisfy the Pythagorean theorem
        if(k == 0 && max == b + c) {
            cout << "YES" << endl; // a is the largest, check if a^2 = b^2 + c^2
        }
        else if(k == 1 && max == a + c) {
            cout << "YES" << endl; // b is the largest, check if b^2 = a^2 + c^2
        }
        else if(k == 2 && max == a + b) {
            cout << "YES" << endl; // c is the largest, check if c^2 = a^2 + b^2
        }
        else {
            cout << "NO" << endl; // The values do not satisfy the condition
        }
    }

    return 0; // End of the program
}

