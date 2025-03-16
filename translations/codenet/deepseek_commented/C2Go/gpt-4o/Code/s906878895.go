package main

import (
	"fmt"
)

func main() {
	var a, b int // Declare variables to store input values
	for {
		_, err := fmt.Scanf("%d %d", &a, &b) // Read two integers from standard input
		if err != nil { // Check for end of file or input error
			break
		}
		x := a + b // Calculate the sum of the two integers
		w := 0     // Initialize the digit count to 0
		for x > 0 { // Loop to count the number of digits in the sum
			w++    // Increment the digit count
			x /= 10 // Divide the sum by 10 to remove the last digit
		}
		fmt.Println(w) // Print the number of digits in the sum
	}
}
