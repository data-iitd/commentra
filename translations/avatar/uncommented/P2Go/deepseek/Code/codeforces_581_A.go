package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	minVal := int(math.Min(float64(a), float64(b)))
	maxVal := int(math.Max(float64(a), float64(b)))
	fmt.Println(minVal, (maxVal-minVal)/2)
}

