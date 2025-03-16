package main

import (
	"fmt"
)

func main() {
	// Declare an integer slice 'c' of size 3 to store the input values
	c := make([]int, 3)

	// Start an infinite loop to read input values until EOF is reached
	for {
		// Read three integers from standard input
		_, err := fmt.Scan(&c[0], &c[1], &c[2])
		if err != nil {
			break // Exit the loop if an error occurs (EOF)
		}

		// Declare and initialize a byte slice 'card' of size 10 with all elements set to zero
		card := make([]byte, 10)
		count := 0
		sum := c[0] + c[1] // Initialize sum with the sum of the first two input values

		// Loop through the slice 'c' to mark the corresponding index in 'card' slice
		for _, value := range c {
			card[value-1] = 1 // Set the index in 'card' slice to 1 if the corresponding value in 'c' is read
		}

		// Loop through the slice 'card' to check if there are at least 4 distinct numbers in the input
		for i := 0; i < 10; i++ {
			// If the index in 'card' slice is not set to 1 and the sum of input values, index and 1 is less than or equal to 20
			if card[i] == 0 && sum+i+1 <= 20 {
				count++ // Increment the count if the condition is true
			}
		}

		// Check if the count is greater than or equal to 4 and print "YES" if true, otherwise print "NO"
		if count >= 4 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

// <END-OF-CODE>
