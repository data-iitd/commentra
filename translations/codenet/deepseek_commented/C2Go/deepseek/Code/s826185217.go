package main

import (
	"fmt" // Step 1: Import the fmt package to use Println and Scan functions.
)

func main() { // Step 2: Define the main function where the execution of the program begins.
	var a, b, c, d int // Step 3: Declare four integer variables a, b, c, and d to store the input values.

	fmt.Scan(&a, &b, &c, &d) // Step 4: Use Scan function to read four integers from the user and store them in variables a, b, c, and d.

	if a + b > c + d { // Step 5: Compare the sum of a and b with the sum of c and d.
		fmt.Println("Left") // Step 6: If the sum of a and b is greater than the sum of c and d, print "Left".
	} else if a + b < c + d { // Step 7: If the sum of a and b is less than the sum of c and d, print "Right".
		fmt.Println("Right")
	} else { // Step 8: If the sums are equal, print "Balanced".
		fmt.Println("Balanced")
	}
}
