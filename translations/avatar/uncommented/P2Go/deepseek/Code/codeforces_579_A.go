package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	x := 1
	for math.Log2(float64(n)) != float64(int(math.Log2(float64(n)))) {
		x += 1
		n -= int(math.Pow(2, math.Floor(math.Log2(float64(n)))))
	}
	fmt.Println(x)
}

