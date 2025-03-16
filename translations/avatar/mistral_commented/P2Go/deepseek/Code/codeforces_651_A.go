package main

import (
	"fmt"
	"strconv"
)

func main() {
	var x, y int
	fmt.Scan(&x, &y)

	// Helper functions for simplifying input process
	numInp := func() int {
		var input string
		fmt.Scan(&input)
		num, _ := strconv.Atoi(input)
		return num
	}

	arrInp := func() []int {
		var input string
		fmt.Scan(&input)
		parts := strconv.Split(input, " ")
		nums := make([]int, len(parts))
		for i, part := range parts {
			num, _ := strconv.Atoi(part)
			nums[i] = num
		}
		return nums
	}

	spInp := func() []int {
		var input string
		fmt.Scan(&input)
		parts := strconv.Split(input, " ")
		nums := make([]int, len(parts))
		for i, part := range parts {
			num, _ := strconv.Atoi(part)
			nums[i] = num
		}
		return nums
	}

	strInp := func() string {
		var input string
		fmt.Scan(&input)
		return input
	}

	// Calculate and print the maximum value between x + y - 3 + ( ( y - x ) % 3 > 0 ) and 0
	fmt.Println(max(x+y-3+((y-x)%3 > 0), 0))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
