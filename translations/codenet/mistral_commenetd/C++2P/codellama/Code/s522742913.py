#include <iostream>
#include <string>
#include <cmath>
#include <bitset>

using namespace std;

int main()
{
	# Initialize an empty string variable named 'source'
	source = ""

	# Read a string input from the standard input stream (cin) and store it in the 'source' variable
	cin >> source

	# Check if the length of the input string is valid (greater than 10 characters or less than 1 character)
	if(source.length() > 10 or source.length() < 1):
		# If the condition is true, return an error code (-1)
		return -1

	# Calculate the maximum value of 'i' based on the length of the input string using bitwise operations
	max_i = int(pow(2, source.length() - 1))

	# Initialize a variable named 'sum' with a value of 0
	sum = 0

	# Iterate through the range of 'i' from 0 to 'max_i' using a for loop
	for i in range(0, max_i):
		# Create a bitset named 'plus' with the binary representation of 'i'
		plus = bitset<100>(i)

		# Initialize a variable named 'number' with a value of 0
		number = 0

		# Initialize a string variable named 'working' with the value of the input string 'source'
		working = source

		# Iterate through the bits of the 'plus' bitset from the least significant bit to the most significant bit
		while(plus.any()):
			# Find the index of the first '1' bit in the 'plus' bitset
			index = 0
			while(!plus[index]):
				index += 1

			# Add the substring of the 'working' string starting from the first '1' bit index to the 'sum' variable
			sum += float(working[0:index + 1])

			# Shift the 'plus' bitset to the right by the index of the first '1' bit
			plus >>= index + 1

			# Update the value of the 'working' string by removing the substring that has been added to the 'sum' variable
			working = working[index + 1:]

		# Add the remaining substring of the 'working' string to the 'sum' variable
		sum += float(working)

	# Set the precision of the output stream (cout) to 0 decimal places
	cout.precision(0)

	# Set the output format of the cout stream to fixed decimal
	cout << fixed

	# Print the value of the 'sum' variable to the standard output stream (cout) with no decimal places and append a newline character ('\n')
	cout << sum << endl

	# Return 0 to indicate successful execution of the program
	return 0
}

