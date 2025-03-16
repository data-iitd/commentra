package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	maxVal := math.MinInt64
	if a+b > maxVal {
		maxVal = a + b
	}
	if a-b > maxVal {
		maxVal = a - b
	}
	if a*b > maxVal {
		maxVal = a * b
	}

	fmt.Println(maxVal)
}

