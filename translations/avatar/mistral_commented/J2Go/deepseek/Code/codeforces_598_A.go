package main

import (
	"fmt"
	"math"
)

func main() {
	var q int
	fmt.Scan(&q)

	for i := 0; i < q; i++ {
		var n int
		fmt.Scan(&n)

		s := 0
		x := int(math.Log2(float64(n))) + 1

		s = -1 * int(math.Pow(2, float64(x))) + 2 + (int(n) * (int(n) + 1) / 2) - int(math.Pow(2, float64(x)))

		fmt.Println(s)
	}
}

