package main

import (
	"fmt"
	"math"
)

func main() {
	var q int
	fmt.Scan(&q)
	for q > 0 {
		q--
		var n int
		fmt.Scan(&n)
		x := int(math.Log2(float64(n))) + 1
		s := -1 * int(math.Pow(2, float64(x))) + 2 + (int(n) * (int(n) + 1)) / 2 - int(math.Pow(2, float64(x)))
		fmt.Println(s)
	}
}

