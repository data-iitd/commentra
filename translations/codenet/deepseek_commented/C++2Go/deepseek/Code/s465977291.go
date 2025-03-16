package main

import (
	"fmt"
	"math"
)

func main() {
	var n, d float64
	fmt.Scan(&n, &d)

	a := d*2 + 1
	result := math.Ceil(n / a)
	fmt.Println(result)
}

