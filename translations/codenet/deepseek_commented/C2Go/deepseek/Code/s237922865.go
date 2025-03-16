package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the integer n from standard input.

	cnt4, cnt2 := 0, 0 // Initialize counters for multiples of 4 and multiples of 2.

	// Read n integers from standard input and update the counters.
	for i := 0; i < n; i++ {
		var wk int
		fmt.Scan(&wk)
		if wk % 4 == 0 { // Check if the integer is a multiple of 4.
			cnt4++
		} else if wk % 2 == 0 { // Check if the integer is a multiple of 2 but not 4.
			cnt2++
		}
	}

	// Check if the sum of multiples of 4 and multiples of 2 (divided by 2) is greater than or equal to n/2.
	if cnt4 + cnt2 / 2 >= n / 2 {
		fmt.Println("Yes") // Print "Yes" if the condition is met.
	} else {
		fmt.Println("No") // Print "No" otherwise.
	}
}

