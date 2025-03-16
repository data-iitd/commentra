package main  // Define the main package

import (
	"fmt"  // Import the fmt package for formatted I/O
)

func main() {  // Define the main function
	var a, b, c int64  // Declare variables to store the input values
	fmt.Scanf("%d %d %d", &a, &b, &c)  // Read three int64 integers from the user

	d := c - a - b  // Calculate the difference between c and the sum of a and b
	if d > 0 && (4*a*b) < (d*d) {  // Check if the difference is positive and satisfies the specific condition
		fmt.Println("Yes")  // Print "Yes" if the condition is met
	} else {
		fmt.Println("No")  // Print "No" otherwise
	}
}

// <END-OF-CODE>
