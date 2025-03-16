#include <iostream>

using namespace std;

int main()
{
    // Declare two integer variables n and k
    int n, k;

    // Read two integers from user input
    cin >> n >> k;

    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0
        cout << "0" << endl;
    } else {
        // If n is not divisible by k, print 1
        cout << "1" << endl;
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}
