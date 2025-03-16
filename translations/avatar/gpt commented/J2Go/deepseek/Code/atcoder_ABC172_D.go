package main

import (
	"fmt"
)

func main() {
	// Read an integer input from the user
	var n int
	fmt.Scan(&n)
	
	// Initialize a variable to hold the final result
	var ans int64 = 0
	
	// Loop through each integer from 1 to n (inclusive)
	for i := 1; i < n + 1; i++ {
		// Calculate the contribution of the current integer i to the result
		// This involves multiplying i by the number of times i fits into n
		// and summing up the series of numbers from 1 to (n / i)
		ans += int64(i) * int64(n / i) * (int64(n / i) + 1) / 2
	}
	
	// Output the final result
	fmt.Println(ans)
}
