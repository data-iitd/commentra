package main  // Define the main package

import (  // Import necessary packages
	"fmt"  // Import the fmt package for formatted I/O
)

func main() {  // Define the main function, the entry point of the program
	var a, b, c int  // Declare three integer variables
	fmt.Scanf("%d %d %d", &a, &b, &c)  // Read three integers from the user and store them in variables a, b, and c
	
	if a < b && b < c {  // Check if a is less than b and b is less than c
		fmt.Println("Yes")  // Print "Yes" if true
	} else {
		fmt.Println("No")  // Print "No" if the condition is not met
	}
}

// Return 0 is implicit in Go, as the program exits with a status code of 0 by default
