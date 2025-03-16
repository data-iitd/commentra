
package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var q, h, s, d int
	var n int
	fmt.Scan(&q, &h, &s, &d, &n)

	best1L := min(q*4, h*2, s)
	best2L := min(d, best1L*2)

	if n%2 == 0 {
		fmt.Println(best2L * (n / 2))
	} else {
		fmt.Println(best2L*(n/2) + best1L)
	}
}

func min(a, b, c int) int {
	return int(math.Min(float64(a), float64(b), float64(c)))
}

