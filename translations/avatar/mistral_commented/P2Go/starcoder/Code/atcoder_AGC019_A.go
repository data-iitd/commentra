package main

import (
	"fmt"
	"math"
)

func main() {
	var q, h, s, d, n int
	fmt.Scanf("%d %d %d %d %d", &q, &h, &s, &d, &n)
	best1L := int(math.Min(float64(q*4), float64(h*2), float64(s)))
	best2L := int(math.Min(float64(d), float64(best1L*2)))
	if n%2 == 0 {
		fmt.Println(best2L * (n/2))
	} else {
		fmt.Println(best2L * (n/2) + best1L)
	}
}

