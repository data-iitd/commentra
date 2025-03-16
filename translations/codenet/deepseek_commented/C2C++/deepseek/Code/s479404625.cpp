#include <iostream>
#include <string>

int main()
{
	// Declare string variables to store three strings
	std::string A, B, C;

	// Read three strings from the user, separated by spaces
	std::cin >> A >> B >> C;

	// Calculate the lengths of strings A and B
	int la = A.length(), lb = B.length();

	// Check if the last character of A matches the first character of B
	// and if the last character of B matches the first character of C
	if (A[la - 1] == B[0] && B[lb - 1] == C[0])
	{
		// If both conditions are true, print "YES"
		std::cout << "YES" << std::endl;
	}
	else
	{
		// Otherwise, print "NO"
		std::cout << "NO" << std::endl;
	}

	// Return 0 to indicate successful execution
	return 0;
}
