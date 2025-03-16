package main

import (
	"fmt"
	"math"
)

func main() {
	var Q, H, S, D, N float64
	fmt.Scan(&Q, &H, &S, &D, &N)

	// Calculating the minimum price for one unit
	onePrice := math.Min(math.Min(Q*4, H*2), S)

	// Conditional logic to determine the total cost
	if onePrice <= D/2 {
		fmt.Println(N * onePrice)
	} else {
		fmt.Println((N/2)*D + math.Mod(N, 2)*onePrice)
	}
}

