#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // Declare three integer variables to hold the input values
    int a, b, c;

    // Read three integers from the user input
    cin >> a >> b >> c;

    // Check if the number formed by a, b, and c is divisible by 4
    // The number is formed as 100*a + 10*b + c
    if ((100 * a + 10 * b + c) % 4 == 0) {
        // If the number is divisible by 4, output "YES"
        cout << "YES" << endl;
    }
    else {
        // If the number is not divisible by 4, output "NO"
        cout << "NO" << endl;
    }
}
