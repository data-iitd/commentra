package main

import (
	"fmt"
	"math"
)

func main() {
	var h int64
	fmt.Scan(&h)

	var ans, cnt, mx, sum, mn int64 = 0, 1, 0, 0, 1e8

	for h != 1 {
		if h%2 != 0 {
			h-- // Decrement h if it is odd
		}
		h /= 2 // Divide h by 2
		cnt *= 2 // Double the count
		ans += cnt // Increment the sum by the current count
	}

	fmt.Println(ans + 1)
}

