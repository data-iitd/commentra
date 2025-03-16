#include <iostream>

using namespace std;

// The main function is the entry point of the program
int main(void)
{
        // Declare two integer variables 'n' and 'k'
        int n, k;

        // Read two integers from the standard input using scanf
        cin >> n >> k;

        // Check if 'n' is divisible by 'k'
        if(n%k==0)
        {
                // If it is, print '0' to the standard output
                cout << "0" << endl;
        }
        else
        {
                // If it's not, print '1' to the standard output
                cout << "1" << endl;
        }

        // Return 0 to indicate successful execution of the program
        return 0;
}

