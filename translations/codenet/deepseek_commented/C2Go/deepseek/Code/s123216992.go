package main

import (
	"fmt"
)

// Define a function named 'swap' that takes two integer pointers as arguments.
func swap(a, b *int) {
	tmp := *a  // Inside the 'swap' function, declare a temporary variable 'tmp'.
	*a = *b    // Assign the value pointed to by 'b' to the memory location pointed to by 'a'.
	*b = tmp   // Assign the value stored in 'tmp' to the memory location pointed to by 'b'.
}

func main() {  // In the 'main' function, declare two integer variables 'a' and 'b'.
	for {  // Create an infinite loop using 'for { }'.
		var a, b int
		fmt.Scan(&a, &b)  // Use 'fmt.Scan' to read two integers from the user and store them in 'a' and 'b'.
		if a == 0 && b == 0 {  // Check if both 'a' and 'b' are zero. If true, break the loop.
			break
		}
		if b < a {  // Check if 'b' is less than 'a'. If true, call the 'swap' function to swap the values of 'a' and 'b'.
			swap(&a, &b)
		}
		fmt.Printf("%d %d\n", a, b)  // Print the values of 'a' and 'b'.
	}
}

