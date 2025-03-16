#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Declare integer variables to store user input and the result
    int a, b;
    int ans;

    // Read two integers from the user
    cin >> a >> b;

    // Initialize the result variable to 0
    ans = 0;

    // Check the value of 'a' and update 'ans' accordingly
    if (a >= 13) {
        // If 'a' is 13 or greater, set 'ans' to 'b'
        ans = b;
    } else if (a >= 6) {
        // If 'a' is between 6 and 12 (inclusive), set 'ans' to half of 'b'
        ans = b / 2;
    }

    // Print the result
    cout << ans << endl;

    return 0;
}

