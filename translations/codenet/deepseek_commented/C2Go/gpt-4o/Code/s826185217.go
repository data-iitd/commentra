package main // Step 1: Declare the main package.

import ( // Step 2: Import the necessary packages.
	"fmt" // Import the fmt package for formatted I/O.
)

func main() { // Step 3: Define the main function where the execution of the program begins.
	var a, b, c, d int // Step 4: Declare four integer variables a, b, c, and d to store the input values.

	fmt.Scanf("%d%d%d%d", &a, &b, &c, &d) // Step 5: Use Scanf function to read four integers from the user and store them in variables a, b, c, and d.

	if a+b > c+d { // Step 6: Compare the sum of a and b with the sum of c and d.
		fmt.Println("Left") // Step 7: If the sum of a and b is greater than the sum of c and d, print "Left".
	} else if a+b < c+d { // Step 8: If the sum of a and b is less than the sum of c and d, print "Right".
		fmt.Println("Right")
	} else { // Step 9: If the sums are equal, print "Balanced".
		fmt.Println("Balanced")
	}
} // Step 10: End of the main function.

