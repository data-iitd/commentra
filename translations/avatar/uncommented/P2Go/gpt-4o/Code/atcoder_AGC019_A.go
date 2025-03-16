package main

import (
	"fmt"
	"math"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var q, h, s, d int
	fmt.Scan(&q, &h, &s, &d)
	var n int
	fmt.Scan(&n)

	best1L := min(q*4, min(h*2, s))
	best2L := min(d, best1L*2)

	if n%2 == 0 {
		fmt.Println(best2L * (n / 2))
	} else {
		fmt.Println(best2L*(n/2) + best1L)
	}
}

// <END-OF-CODE>
