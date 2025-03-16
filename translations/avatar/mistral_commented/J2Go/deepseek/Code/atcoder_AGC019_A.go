package main

import (
	"fmt"
	"math"
)

func main() {
	var Q, H, S, D, N float64
	fmt.Scan(&Q, &H, &S, &D, &N)

	onePrice := math.Min(math.Min(Q*4, H*2), S)

	if onePrice <= D/2 {
		fmt.Println(N * onePrice)
	} else {
		fmt.Println((N/2)*D + math.Mod(N, 2)*onePrice)
	}
}
