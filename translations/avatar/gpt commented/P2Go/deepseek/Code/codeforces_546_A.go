package main

import (
	"fmt"
	"strconv"
)

func main() {
	var k, n, w string
	fmt.Scan(&k, &n, &w)

	// Convert string inputs to integers
	kInt, _ := strconv.Atoi(k)
	wInt, _ := strconv.Atoi(w)

	// Check if k is at least 1 and w is at most 1000
	if kInt >= 1 && wInt <= 1000 {
		// Initialize total cost to zero
		total := 0

		// Calculate the total cost of buying w bananas
		for i := 1; i <= wInt; i++ {
			total += i * kInt // Cost of each banana increases with its quantity (1*k, 2*k, ..., w*k)
		}

		// Check if the total cost exceeds the initial amount of money n
		if total > kInt {
			// Print the amount of money needed to buy the bananas
			fmt.Println(total - kInt)
		} else {
			// Print 0 if the initial amount is sufficient to buy the bananas
			fmt.Println(0)
		}
	}
}
