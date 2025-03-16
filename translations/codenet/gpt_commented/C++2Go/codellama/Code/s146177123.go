
package main

import (
	"fmt"
)

// Segment representation for digits 0-9
var seg = [][]bool{
	{0, 1, 1, 1, 1, 1, 1}, // 0
	{0, 0, 0, 0, 1, 1, 0}, // 1
	{1, 0, 1, 1, 0, 1, 1}, // 2
	{1, 0, 0, 1, 1, 1, 1}, // 3
	{1, 1, 0, 0, 1, 1, 0}, // 4
	{1, 1, 0, 1, 1, 0, 1}, // 5
	{1, 1, 1, 1, 1, 0, 1}, // 6
	{0, 1, 0, 0, 1, 1, 1}, // 7
	{1, 1, 1, 1, 1, 1, 1}, // 8
	{1, 1, 0, 1, 1, 1, 1}, // 9
}

func main() {
	var n, t int // Declare variables for input and digit
	st := make([]bool, 7) // Array to store the state of segments

	// Read input until a negative number is encountered
	for {
		for i := 0; i < 7; i++ {
			st[i] = false // Initialize segment states to 0
		}

		// Process each digit input
		fmt.Scan(&n)
		if n < 0 {
			break
		}
		for i := 0; i < n; i++ {
			fmt.Scan(&t) // Read the digit
			ans := make([]byte, 8) // Initialize answer array to store segment states

			// Determine the segment states based on the input digit
			for i := 0; i < 7; i++ {
				// Calculate the current segment state and store it in ans
				ans[i] = byte(st[i] ^ seg[t][i])
				st[i] = seg[t][i] // Update the current segment state
			}
			fmt.Println(string(ans)) // Output the segment states for the current digit
		}
	}
}

