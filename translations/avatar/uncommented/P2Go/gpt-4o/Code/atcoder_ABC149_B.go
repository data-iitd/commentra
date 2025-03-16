package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	leftOver := a - c
	takahashi := int(math.Max(float64(0), float64(leftOver)))

	if takahashi > 0 {
		fmt.Printf("%d %d\n", takahashi, b)
	} else {
		fmt.Printf("%d %d\n", takahashi, int(math.Max(float64(0), float64(b-abs(leftOver)))))
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// <END-OF-CODE>
