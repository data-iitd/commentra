package main

import (
	"fmt"
)

func main() {
	// Read two integers from the user: n and k
	var n, k int
	fmt.Scan(&n, &k)
	
	// Increment n by 1
	n++
	
	// Initialize a variable z to store the adjustment needed to make n divisible by k
	var z int
	
	// Check if n is not divisible by k
	if n % k != 0 {
		// Calculate the adjustment needed to make n divisible by k
		z = k - n % k
	}
	
	// Output the final result, which is n plus the adjustment z
	fmt.Println(n + z)
}
