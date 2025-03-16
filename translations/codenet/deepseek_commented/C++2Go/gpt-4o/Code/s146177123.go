package main

import (
	"fmt"
)

func main() {
	// Array to represent the segments of the digits 0-9
	seg := [10][7]bool{
		{false, true, true, true, true, true, true},  // 0
		{false, false, false, false, true, true, false}, // 1
		{true, false, true, true, false, true, true}, // 2
		{true, false, false, true, true, true, true},  // 3
		{true, true, false, false, true, true, false},  // 4
		{true, true, false, true, true, false, true},   // 5
		{true, true, true, true, true, false, true},     // 6
		{false, true, false, false, true, true, true},   // 7
		{true, true, true, true, true, true, true},      // 8
		{true, true, false, true, true, true, true},     // 9
	}

	var n int
	for {
		_, err := fmt.Scan(&n)
		if err != nil || n < 0 { // Read the number of digits and check if it's not zero
			break
		}

		st := [7]bool{} // Initialize the state array to represent the current display state
		for i := 0; i < n; i++ {
			var t int
			fmt.Scan(&t) // Read the next digit
			ans := [7]byte{} // Array to store the current display state
			for j := 0; j < 7; j++ {
				// Calculate the current segment state and store it in the answer array
				if st[j]^seg[t][j] {
					ans[j] = '1'
				} else {
					ans[j] = '0'
				}
				// Update the state array with the current segment state
				st[j] = seg[t][j]
			}
			// Output the current display state
			fmt.Println(string(ans[:]))
		}
	}
}

// <END-OF-CODE>
