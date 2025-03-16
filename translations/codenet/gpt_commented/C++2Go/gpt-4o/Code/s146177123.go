package main

import (
	"fmt"
)

var seg = [10][7]bool{
	{false, true, true, true, true, true, true},  // 0
	{false, false, false, false, true, true, false}, // 1
	{true, false, true, true, false, true, true}, // 2
	{true, false, false, true, true, true, true}, // 3
	{true, true, false, false, true, true, false}, // 4
	{true, true, false, true, true, false, true}, // 5
	{true, true, true, true, true, false, true}, // 6
	{false, true, false, false, true, true, true}, // 7
	{true, true, true, true, true, true, true}, // 8
	{true, true, false, true, true, true, true}, // 9
}

func main() {
	var n, t int
	st := make([]bool, 7) // Array to store the state of segments

	// Read input until a negative number is encountered
	for {
		if _, err := fmt.Scan(&n); err != nil || n < 0 {
			break
		}
		for i := 0; i < 7; i++ {
			st[i] = false // Initialize segment states to false
		}

		// Process each digit input
		for i := 0; i < n; i++ {
			fmt.Scan(&t) // Read the digit
			ans := make([]byte, 7) // Initialize answer array to store segment states

			// Determine the segment states based on the input digit
			for j := 0; j < 7; j++ {
				if st[j] != seg[t][j] {
					ans[j] = '1'
				} else {
					ans[j] = '0'
				}
				st[j] = seg[t][j] // Update the current segment state
			}
			fmt.Println(string(ans)) // Output the segment states for the current digit
		}
	}
}

// <END-OF-CODE>
