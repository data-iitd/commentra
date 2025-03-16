
package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		fmt.Println(sub(a, b))
	}
}

func sub(a, b int) int {
	min := int(math.Min(float64(a), float64(b)))
	max := int(math.Max(float64(a), float64(b)))
	result := 0
	for min > 0 {
		result += max / min
		max = max % min
		currMin := int(math.Min(float64(min), float64(max)))
		currMax := int(math.Max(float64(min), float64(max)))
		min = currMin
		max = currMax
	}
	return result
}

