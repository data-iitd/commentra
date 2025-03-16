package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read an integer n from the user
	var ans int64 = 0 // Initialize the variable ans to 0

	// Loop from 1 to n (inclusive)
	for i := 1; i < n + 1; i++ {
		// Calculate a value based on the current value of i and the variable n
		term := int64(n) / int64(i)
		sum := term * (term + 1) / 2
		ans += int64(i) * sum
	}

	// Print the value of ans
	fmt.Println(ans)
}
