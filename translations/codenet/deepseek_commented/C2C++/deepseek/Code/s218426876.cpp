#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i, sum = 0;
	bool flag = false;
	string x; // Declare a string to store the input string
	cin >> x; // Read the first string from the input
	do {
		sum = 0; // Reset the sum for each string
		for (i = 0; i < x.length(); i++) { // Loop through each character in the string
			sum += x[i] - '0'; // Convert the character to its corresponding digit and add it to the sum
		}
		cout << sum << endl; // Print the sum of the digits
		cin >> x; // Read the next string from the input
	} while (x[0] != '0'); // Continue the loop until a string starting with '0' is encountered

	return 0;
}
