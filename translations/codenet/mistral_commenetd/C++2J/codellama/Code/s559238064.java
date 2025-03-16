#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = (1 ? 1e9 + 7 : 998244353);

// Initialize input/output streams and read input data
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); // Set up fast I/O

	ll a, b, c, d, e, f, g, T;
	String z; // Initialize string variable to store input

	// Read input string from standard input
	cin >> z;
	// Assign size of the string to variable 'a'
	a = z.length();

	// Check if there are any consecutive identical characters in the string
	for (int i = 0; i < a - 1; i++)
	{
		// Check if current character is same as next character
		if (z.charAt(i) == z.charAt(i + 1))
		{
			// If yes, print "Bad" and exit the program
			System.out.println("Bad");
			return 0;
		}
	}
	// If no consecutive identical characters are found, print "Good"
	System.out.println("Good");
}


