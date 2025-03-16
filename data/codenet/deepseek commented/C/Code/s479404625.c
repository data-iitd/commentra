#include <stdio.h>
#include <string.h>

int main()
{
	// Declare character arrays to store three strings
	char A[20], B[20], C[20];

	// Read three strings from the user, separated by spaces
	scanf("%s %s %s", A, B, C);

	// Calculate the lengths of strings A and B
	int la = strlen(A), lb = strlen(B);

	// Check if the last character of A matches the first character of B
	// and if the last character of B matches the first character of C
	if (A[la - 1] == B[0] && B[lb - 1] == C[0])
	{
		// If both conditions are true, print "YES"
		printf("YES\n");
	}
	else
	{
		// Otherwise, print "NO"
		printf("NO\n");
	}

	// Return 0 to indicate successful execution
	return 0;
}