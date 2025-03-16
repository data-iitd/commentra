
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstring> // for memset()

typedef long long ll;
using namespace std;

int main()
{
	// Read two integers `a` and `b` from the standard input
	int a, b; cin >> a >> b;

	// Convert the integer `b` to a string `bstr` using the `to_string()` function
	string bstr = to_string(b);

	// Calculate the number `num` as the product of `a` and `10` raised to the power of the length of the string `bstr`, plus the integer `b`
	int num = a * pow(10, bstr.length()) + b;

	// Initialize a loop counter `i`
	int i;

	// Enter a `for` loop that runs from `1` to `100100`
	for (i = 1; i <= 100100; i++)
	{
		// Inside the loop, check if the square of `i` is equal to the number `num`
		if (i * i == num)
		{
			// If it is, break out of the loop
			break;
		}
	}

	// If the loop completes without finding a square root of `num`, print "No" to the standard output
	if (i > 100100)
	{
		cout << "No" << endl;
	}
	// If we find a square root of `num` inside the loop, print "Yes" to the standard output
	else
	{
		cout << "Yes" << endl;
	}
}