package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	x := 1

	for math.Mod(math.Log2(float64(n)), 1) != 0 {
		x++
		n -= int(math.Pow(2, math.Floor(math.Log2(float64(n)))))
	}

	fmt.Println(x)
}
