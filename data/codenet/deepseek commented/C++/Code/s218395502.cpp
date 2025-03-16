#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	// Step 3: Declare variables to store the input values
	int a, b, c;

	// Step 4: Read input values from the user
	cin >> a >> b >> c;

	// Step 5: Calculate the number formed by the digits a, b, and c
	int number = 100*a + 10*b + c;

	// Step 6: Check if the number is divisible by 4
	if (number % 4 == 0) {
		// Output the result if the number is divisible by 4
		cout << "YES" << endl;
	}
	else {
		// Output the result if the number is not divisible by 4
		cout << "NO" << endl;
	}
}
