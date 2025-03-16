package main

import (
	"fmt"
	"math"
)

func main() {
	var Q, H, S, D, N int64

	// Reading input values
	fmt.Scan(&Q, &H, &S, &D, &N)

	// Calculating the minimum price for one unit
	onePrice := int64(math.Min(float64(math.Min(float64(Q*4), float64(H*2))), float64(S)))

	// Conditional logic to determine the total cost
	if float64(onePrice) <= float64(D)/2 {
		fmt.Println(N * onePrice)
	} else {
		fmt.Println((N / 2) * D + (N % 2) * onePrice)
	}
}

// <END-OF-CODE>
