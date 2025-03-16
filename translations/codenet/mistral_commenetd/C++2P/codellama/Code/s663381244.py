#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Initialize cin and ios streams to disable buffering and synchronization
	cin.tie(0);
	ios::sync_with_stdio(false);

	# Initialize an empty vector 'm' to store the multipliers
	m = []

	# Push back the multipliers into the vector 'm'
	m.append(10)
	m.append(50)
	m.append(100)
	m.append(500)

	first = True # Initialize a boolean variable 'first' to check if it's the first iteration of the loop

	# Main loop to read the input money and calculate the change
	for money in iter(int, 0):
		# If it's not the first iteration, print a newline character to separate the outputs
		if not first:
			print()

		# Set 'first' to false
		first = False

		# Initialize variables 'sum' and 'num'
		sum = 0
		num = [0] * 4

		# Read the numbers and calculate the sum of the products of each number and its corresponding multiplier
		for i in range(4):
			num[i] = int(input()) # Read the number
			sum += num[i] * m[i] # Calculate the product and add it to the sum

		# Calculate the change
		change = sum - money

		# Adjust the numbers to get the exact change
		for i in range(3, -1, -1):
			# If the change is divisible by the current multiplier, subtract the required number of multipliers and update the change
			if change // m[i]:
				num[i] -= change // m[i]
				change %= m[i]

		# Print the numbers that still have a positive value
		for i in range(4):
			if num[i] > 0:
				print(m[i], num[i])

	# Return EXIT_SUCCESS to indicate successful execution
	return EXIT_SUCCESS
}

