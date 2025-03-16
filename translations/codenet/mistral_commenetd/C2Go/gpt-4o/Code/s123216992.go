package main

import (
	"fmt"
)

// Function to swap two integers passed by reference
func swap(a, b *int) {
	tmp := *a // Assign the value of 'a' to 'tmp'
	*a = *b   // Assign the value of 'b' to 'a'
	*b = tmp  // Assign the value of 'tmp' back to 'b'
}

func main() {
	var a, b int

	for {
		// Read two integers from the user
		_, err := fmt.Scanf("%d %d", &a, &b)
		if err != nil {
			break // Break on input error
		}

		if a == 0 && b == 0 {
			break // If both 'a' and 'b' are zero, break out of the loop
		}

		if b < a {
			swap(&a, &b) // If 'b' is less than 'a', swap their values
		}

		fmt.Printf("%d %d\n", a, b) // Print the swapped values of 'a' and 'b'
	}
}

// <END-OF-CODE>
