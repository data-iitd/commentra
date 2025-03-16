package main

import (
	"fmt"
)

func main() {
	// Step 1: Read three integers from input.
	var c [3]int

	for {
		// Read input until EOF
		_, err := fmt.Scan(&c[0], &c[1], &c[2])
		if err != nil {
			break
		}

		// Step 2: Initialize an array to keep track of the cards.
		card := make([]byte, 10)
		// Initialize a counter to count the number of valid cards.
		count := 0
		// Calculate the sum of the two known cards.
		sum := c[0] + c[1]

		// Step 3: Loop through the cards and mark them in the array.
		for i := 0; i < 3; i++ {
			card[c[i]-1] = 1
		}

		// Step 4: Check which cards can be added to the sum without exceeding 20.
		for i := 0; i < 10; i++ {
			if card[i] == 0 && sum+i+1 <= 20 {
				count++
			}
		}

		// Step 5: Determine if at least 4 such cards exist.
		if count >= 4 {
			// Step 6: Print "YES" if such cards exist.
			fmt.Println("YES")
		} else {
			// Step 7: Print "NO" otherwise.
			fmt.Println("NO")
		}
	}
}

// <END-OF-CODE>
