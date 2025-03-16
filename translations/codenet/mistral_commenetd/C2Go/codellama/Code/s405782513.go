
package main

import (
	"fmt"
)

func main() {
	// Declare an integer array 'c' of size 3 to store the input values
	c := make([]int, 3)

	// Start an infinite loop to read input values until EOF is reached
	for {
		// Declare and initialize a character array 'card' of size 10 with all elements set to zero
		card := make([]int, 10)
		var i int
		var count int
		var sum int

		// Read the input values into the array 'c'
		_, err := fmt.Scanf("%d %d %d", &c[0], &c[1], &c[2])
		if err != nil {
			break
		}

		// Initialize sum with the sum of the first two input values
		sum = c[0] + c[1]

		// Loop through the array 'c' to mark the corresponding index in 'card' array
		for i = 0; i < 3; i++ {
			card[c[i]-1] = 1
		}

		// Loop through the array 'card' to check if there are at least 4 distinct numbers in the input
		for i = 0; i < 10; i++ {
			// If the index in 'card' array is not set to 1 and the sum of input values, index and 1 is less than or equal to 20
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

