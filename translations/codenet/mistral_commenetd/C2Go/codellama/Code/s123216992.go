
package main

import "fmt"

func swap(a *int , b *int) {
	// Function to swap two integers passed by reference
	tmp := *a
	// Declare a temporary variable to store the value of 'a'

	*a = *b
	// Assign the value of 'b' to 'a'

	*b = tmp
	// Assign the value of the temporary variable 'tmp' back to 'b'
}

func main() {
	// Declare two integer variables 'a' and 'b'
	var a , b int

	for {
		// Infinite loop to read two integers from the user

		fmt.Scan(&a , &b)
		// Read two integers from the user and store them in 'a' and 'b' respectively

		if a == 0 && b == 0 {
			break
		}
		// If both 'a' and 'b' are zero, break out of the loop

		if b < a {
			swap(&a , &b)
		}
		// If 'b' is less than 'a', swap their values

		fmt.Println(a , b)
		// Print the swapped values of 'a' and 'b'
	}
	// Return 0 to indicate successful execution of the program

	return
}

