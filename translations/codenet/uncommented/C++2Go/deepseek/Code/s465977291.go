package main

import (
	"fmt"
	"math"
)

func main() {
	var n, d int
	fmt.Scan(&n, &d)

	a := float64(d*2+1)
	fmt.Println(int(math.Ceil(float64(n)/a)))
}

