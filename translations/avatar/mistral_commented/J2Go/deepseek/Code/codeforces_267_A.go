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
	min := min(a, b)
	max := max(a, b)
	result := 0

	for min > 0 {
		result += max / min
		max = max % min
		curr_min := min(min, max)
		curr_max := max(min, max)
		min = curr_min
		max = curr_max
	}

	return result
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

