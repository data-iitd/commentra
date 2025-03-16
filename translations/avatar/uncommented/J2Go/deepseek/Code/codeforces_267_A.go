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
	min := func(x, y int) int {
		if x < y {
			return x
		}
		return y
	}(a, b)
	max := func(x, y int) int {
		if x > y {
			return x
		}
		return y
	}(a, b)
	result := 0
	for min > 0 {
		result += max / min
		max = max % min
		curr_min := func(x, y int) int {
			if x < y {
				return x
			}
			return y
		}(min, max)
		curr_max := func(x, y int) int {
			if x > y {
				return x
			}
			return y
		}(min, max)
		min = curr_min
		max = curr_max
	}
	return result
}

