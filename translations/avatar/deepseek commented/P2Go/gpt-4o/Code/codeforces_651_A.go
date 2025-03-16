package main

import (
	"fmt"
)

func main() {
	// Step 1: Take two integers as input and assign them to x and y.
	var x, y int
	fmt.Scan(&x, &y)

	// Step 2: Calculate the maximum value between x + y - 3 and 0, with an additional condition based on (y - x) % 3.
	result := x + y - 3
	if (y-x)%3 > 0 {
		result++
	}
	if result < 0 {
		result = 0
	}
	fmt.Println(result)

	// Step 3: Define functions for taking different types of inputs.
	numInp := func() int {
		var n int
		fmt.Scan(&n)
		return n
	}

	arrInp := func() []int {
		var n int
		fmt.Scan(&n)
		arr := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&arr[i])
		}
		return arr
	}

	spInp := func() []int {
		var arr []int
		for {
			var n int
			if _, err := fmt.Scan(&n); err != nil {
				break
			}
			arr = append(arr, n)
		}
		return arr
	}

	strInp := func() string {
		var s string
		fmt.Scan(&s)
		return s
	}
}

// <END-OF-CODE>
