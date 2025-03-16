#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Declare strings to hold three strings
    string A, B, C;

    // Read three strings from user input
    cin >> A >> B >> C;

    // Calculate the lengths of the first two strings
    int la = A.length(), lb = B.length();

    // Check if the last character of A is the same as the first character of B
    // and if the last character of B is the same as the first character of C
    if (A[la - 1] == B[0] && B[lb - 1] == C[0])
    {
        // If both conditions are true, print "YES"
        cout << "YES\n";
    }
    else
    {
        // If either condition is false, print "NO"
        cout << "NO\n";
    }

    return 0; // Indicate that the program ended successfully
}

