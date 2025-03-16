package main

import (
	"fmt"
	"math"
)

func main() {
	// Creating a Scanner object to read input from the console
	var Q, H, S, D, N int64
	fmt.Scan(&Q, &H, &S, &D, &N)

	// Calculating the minimum price for a single item based on the given prices
	onePrice := int64(math.Min(math.Min(float64(Q*4), float64(H*2)), float64(S)))

	// Checking if the price of one item is less than or equal to half the price of buying in pairs
	if onePrice <= D/2 {
		// If true, calculate the total cost for N items at the price of one item
		fmt.Println(N * onePrice)
	} else {
		// If false, calculate the total cost using the pair price and the remaining single item price if N is odd
		fmt.Println((N/2)*D + (N%2)*onePrice)
	}
}

