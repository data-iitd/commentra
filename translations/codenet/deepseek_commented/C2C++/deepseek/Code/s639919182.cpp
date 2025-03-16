#include <iostream> // Step 1: Include necessary headers

int main(void) // Step 1: Define the main function
{
	int v[10]; // Step 2: Declare an array of 10 integers
	int sum = 0; // Step 2: Declare and initialize a variable to store the sum
	int i; // Step 2: Declare a loop variable
	
	for(i = 0; i < 10; i++) // Step 3: Initialize a loop to read 10 integers from the user
		std::cin >> v[i]; // Step 3: Read an integer and store it in the array
	
	for(i = 0; i < 10; i++) // Step 4: Initialize a loop to calculate the sum of the integers
		sum += v[i]; // Step 4: Add the current element to the sum
	
	std::cout << sum << std::endl; // Step 5: Print the sum of the integers
	
	return 0; // Step 6: Return 0 to indicate successful execution
}
