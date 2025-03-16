#include<stdio.h>         // Include stdio for input and output operations
#include<string.h>        // Include string for string manipulation functions
#include<stdlib.h>        // Include stdlib for general functions like malloc
#include<math.h>          // Include math for mathematical functions
#include<algorithm>       // Include algorithm for general algorithms like sort
typedef long long ll;      // Define ll as an alias for long long
const int inf = 0x3f3f3f3f; // Define inf as a large value (0x3f3f3f3f)
const int mod = (1 ? 1e9 + 7 : 998244353); // Define mod as either 1e9 + 7 or 998244353

int main()
{
	freopen("input.txt", "r", stdin); // Redirect input to input.txt
	freopen("output.txt", "w", stdout); // Redirect output to output.txt
	ios::sync_with_stdio(false); cin.tie(0); // Optimize input/output operations
	ll a, b, c, d, e, f, g, T; // Declare variables to store input values
	char z[1000000]; // Declare a string variable to store input string
	scanf("%s", z); // Read input string from standard input
	a = strlen(z); // Calculate the size of the string and store it in a
	for (int i = 0; i < a - 1; i++) // Iterate through the string
	{
		if (z[i] == z[i + 1]) // Check if any two consecutive characters are the same
		{
			printf("Bad\n"); // Print "Bad" if a pair is found and exit
			return 0;
		}
	}
	printf("Good\n"); // Print "Good" if no pair is found
	return 0;
}
