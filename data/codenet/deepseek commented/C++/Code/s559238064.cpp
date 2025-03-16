#include<cmath>          // Include cmath for mathematical functions
#include<cstring>        // Include cstring for string manipulation functions
#include<iostream>       // Include iostream for input and output operations
#include<algorithm>      // Include algorithm for general algorithms like sort
using namespace std;     // Use the standard namespace
typedef long long ll;    // Define ll as an alias for long long
const int inf = 0x3f3f3f3f; // Define inf as a large value (0x3f3f3f3f)
const int mod = (1 ? 1e9 + 7 : 998244353); // Define mod as either 1e9 + 7 or 998244353

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); // Optimize input/output operations
	ll a, b, c, d, e, f, g, T; // Declare variables to store input values
	string z; // Declare a string variable to store input string
	cin >> z; // Read input string from standard input
	a = z.size(); // Calculate the size of the string and store it in a
	for (int i = 0; i < a - 1; i++) // Iterate through the string
	{
		if (z[i] == z[i + 1]) // Check if any two consecutive characters are the same
		{
			cout << "Bad" << endl; // Print "Bad" if a pair is found and exit
			return 0;
		}
	}
	cout << "Good" << endl; // Print "Good" if no pair is found
}
