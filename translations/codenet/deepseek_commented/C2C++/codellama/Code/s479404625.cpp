#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Declare strings to store three strings
	string A, B, C;

	// Read three strings from the user, separated by spaces
	cin >> A >> B >> C;

	// Calculate the lengths of strings A and B
	int la = A.length(), lb = B.length();

	// Check if the last character of A matches the first character of B
	// and if the last character of B matches the first character of C
	if (A[la - 1] == B[0] && B[lb - 1] == C[0])
	{
		// If both conditions are true, print "YES"
		cout << "YES\n";
	}
	else
	{
		// Otherwise, print "NO"
		cout << "NO\n";
	}

	// Return 0 to indicate successful execution
	return 0;
}

