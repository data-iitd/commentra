package main // Define the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // Define the main function
	var a, b, c, d int // Declare four integer variables

	fmt.Scanf("%d%d%d%d", &a, &b, &c, &d) // Read four integers from standard input

	if a+b > c+d { // Check if the sum of a and b is greater than the sum of c and d
		fmt.Println("Left") // If true, print "Left"
	} else if a+b < c+d { // Check if the sum of a and b is less than the sum of c and d
		fmt.Println("Right") // If true, print "Right"
	} else { // If neither of the above conditions is true
		fmt.Println("Balanced") // Print "Balanced"
	}
}

// <END-OF-CODE>
