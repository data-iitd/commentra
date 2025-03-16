package main

import (
	"fmt"
)

func main() {
	var a, b int // Declare two integer variables 'a' and 'b'

	fmt.Scan(&a) // Read an integer value from the standard input and store it in variable 'a'
	fmt.Scan(&b) // Read an integer value from the standard input and store it in variable 'b'

	if (a*b)%2 == 0 { // Check if the product of 'a' and 'b' is even
		fmt.Println("Even") // If it is even, print "Even" to the standard output
	} else {
		fmt.Println("Odd") // If it is odd, print "Odd" to the standard output
	}
}

// <END-OF-CODE>
