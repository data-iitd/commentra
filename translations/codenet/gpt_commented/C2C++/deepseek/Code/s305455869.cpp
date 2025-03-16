#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    // Declare variables to hold input values and the result
    int a, b;
    int ans;

    // Read two integers from standard input
    cin >> a >> b;

    // Initialize the answer variable to zero
    ans = 0;

    // Determine the value of ans based on the value of a
    if (a >= 13) {
        // If a is 13 or greater, set ans to b
        ans = b;
    } else if (a >= 6) {
        // If a is between 6 and 12, set ans to half of b
        ans = b / 2;
    }

    // Output the result
    cout << ans << endl;

    // Return 0 to indicate successful execution
    return 0;
}
