package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)
	result := max(a*c, b*d, a*d, b*c)
	fmt.Println(result)
}

func max(values ...int) int {
	maxValue := math.MinInt64
	for _, value := range values {
		if value > maxValue {
			maxValue = value
		}
	}
	return maxValue
}

// <END-OF-CODE>
