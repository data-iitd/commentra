// C++ program to count the number of occurrences of a substring
#include <bits/stdc++.h>
using namespace std;

// Driver Code
int main()
{
	// Declare and initialize two variables: n of type int and s of type string
	int n;
	string s;

	// Use the cin package to read input from the standard input
	cin >> n;
	cin >> s;

	// Use the cout and string packages to compute and print the result
	cout << count(s, "ABC") << endl;

	return 0;
}

// End of code

