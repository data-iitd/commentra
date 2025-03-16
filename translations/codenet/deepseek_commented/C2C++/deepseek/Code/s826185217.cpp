#include <iostream> // Step 1: Include the iostream library to use cin and cout functions.

int main(void){ // Step 2: Define the main function where the execution of the program begins.
	int a, b, c, d; // Step 3: Declare four integer variables a, b, c, and d to store the input values.

	std::cin >> a >> b >> c >> d; // Step 4: Use cin function to read four integers from the user and store them in variables a, b, c, and d.

	if (a + b > c + d) // Step 5: Compare the sum of a and b with the sum of c and d.
		std::cout << "Left" << std::endl; // Step 6: If the sum of a and b is greater than the sum of c and d, print "Left".
	else if (a + b < c + d) // Step 7: If the sum of a and b is less than the sum of c and d, print "Right".
		std::cout << "Right" << std::endl;
	else // Step 8: If the sums are equal, print "Balanced".
		std::cout << "Balanced" << std::endl;

	return 0; // Step 9: Return 0 to indicate successful execution of the program.
}
