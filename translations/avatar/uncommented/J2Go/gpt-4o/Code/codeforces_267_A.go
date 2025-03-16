package main

import (
	"fmt"
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
	min := a
	max := b
	if a > b {
		min = b
		max = a
	}
	result := 0
	for min > 0 {
		result += max / min
		max = max % min
		currMin := min
		currMax := max
		if max < min {
			currMin = max
			currMax = min
		}
		min = currMin
		max = currMax
	}
	return result
}

// <END-OF-CODE>
