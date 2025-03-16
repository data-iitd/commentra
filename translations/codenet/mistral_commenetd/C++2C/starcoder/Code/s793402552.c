
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	// Read two integers `a` and `b` from the standard input
	int a, b; scanf("%d %d", &a, &b);

	// Convert the integer `b` to a string `bstr` using the `to_string()` function
	char bstr[100]; sprintf(bstr, "%d", b);

	// Calculate the number `num` as the product of `a` and `10` raised to the power of the length of the string `bstr`, plus the integer `b`
	int num = a * pow(10, strlen(bstr)) + b;

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
		printf("No\n");
	}
	// If we find a square root of `num` inside the loop, print "Yes" to the standard output
	else
	{
		printf("Yes\n");
	}
}

