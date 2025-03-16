package main

import (
	"fmt" // Import the format package for formatted I/O
)

func main() {
	var a, b, c, d int // Declare four integer variables

	fmt.Scan(&a, &b, &c, &d) // Read four integers from the standard input and store them in the variables a, b, c, and d

	if a + b > c + d { // Check if the sum of a and b is greater than the sum of c and d
		fmt.Println("Left") // If true, print "Left" to the standard output
	} else if a + b < c + d { // Check if the sum of a and b is less than the sum of c and d
		fmt.Println("Right") // If true, print "Right" to the standard output
	} else { // If neither of the above conditions is true
		fmt.Println("Balanced") // Print "Balanced" to the standard output
	}
}

