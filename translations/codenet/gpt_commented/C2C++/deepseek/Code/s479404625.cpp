#include <iostream>
#include <string>

int main()
{
    // Declare string variables to hold three strings
    std::string A, B, C;

    // Read three strings from user input
    std::cin >> A >> B >> C;

    // Calculate the lengths of the first two strings
    int la = A.length(), lb = B.length();

    // Check if the last character of A is the same as the first character of B
    // and if the last character of B is the same as the first character of C
    if (A[la - 1] == B[0] && B[lb - 1] == C[0])
    {
        // If both conditions are true, print "YES"
        std::cout << "YES" << std::endl;
    }
    else
    {
        // If either condition is false, print "NO"
        std::cout << "NO" << std::endl;
    }

    return 0; // Indicate that the program ended successfully
}
