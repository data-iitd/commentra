package main

import (
	"fmt"
	"strconv"
)

func main() {
	var kStr, nStr, wStr string
	fmt.Scan(&kStr, &nStr, &wStr)

	k, _ := strconv.Atoi(kStr)
	n, _ := strconv.Atoi(nStr)
	w, _ := strconv.Atoi(wStr)

	// Check if k is at least 1 and w is at most 1000
	if k >= 1 && w <= 1000 {
		// Initialize total cost to zero
		total := 0

		// Calculate the total cost of buying w bananas
		for i := 1; i <= w; i++ {
			total += i * k // Cost of each banana increases with its quantity (1*k, 2*k, ..., w*k)
		}

		// Check if the total cost exceeds the initial amount of money n
		if total > n {
			// Print the amount of money needed to buy the bananas
			fmt.Println(total - n)
		} else {
			// Print 0 if the initial amount is sufficient to buy the bananas
			fmt.Println(0)
		}
	}
}

// <END-OF-CODE>
