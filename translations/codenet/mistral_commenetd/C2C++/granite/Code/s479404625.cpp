

#include <iostream>
#include <string>

// Declare three string variables A, B, and C
std::string A, B, C;

int main()
{
	// Initialize the string variables A, B, and C using cin function
	std::cin >> A >> B >> C;

	// Calculate the length of strings A and B using size function and store the lengths in la and lb respectively
	int la = A.size(), lb = B.size();

	// Logical block to check if the last character of string A is same as the first character of string B
	// and the last character of string B is same as the first character of string C
	if (A[la - 1] == B[0] && B[lb - 1] == C[0])
	{
		// If the condition is true, print YES on the console
		std::cout << "YES\n";
	}
	// Logical block to check if the condition in if block is false
	else
	{
		// If the condition is false, print NO on the console
		std::cout << "NO\n";
	}

	// Return 0 to indicate successful execution of the program
	return 0;
}

