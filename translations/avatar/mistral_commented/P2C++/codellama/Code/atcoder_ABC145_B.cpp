#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;

    // Read an integer value from the user
    cin >> n;

    // Read a string value from the user
    cin >> s;

    // Check if n is odd
    if (n % 2 != 0)
    {
        cout << "No" << endl;
    }

    // Check if the first half of the string is equal to the second half
    else if (s.substr(0, n / 2) == s.substr(n / 2, n / 2))
    {
        cout << "Yes" << endl;
    }

    // If the first half is not equal to the second half, print 'No'
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
