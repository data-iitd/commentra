package main

import (
	"fmt"
	"os"
)

func main() {
	var a, b, x, w int
	// Declare four integer variables: a, b, x, and w

	for {
		_, err := fmt.Scanf("%d %d", &a, &b)
		if err != nil {
			if err == os.EOF {
				break
			}
			fmt.Println(err)
		}
		x = a + b
		// Add this comment to explain the assignment of the sum of a and b to x

		w = 0
		// Initialize w to zero

		for x > 0 {
			w++
			// Increment w each time through the loop
			x /= 10
			// Divide x by 10 to get the next digit
		}
		fmt.Println(w)
		// Print the value of w, which represents the number of digits in the sum of a and b
	}
	// This for loop continues to read input until the end of the file is reached
}
// The main function returns 0 to indicate successful execution

