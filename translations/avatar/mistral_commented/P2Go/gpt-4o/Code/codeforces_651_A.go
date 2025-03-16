package main

import (
	"fmt"
)

func main() {
	var x, y int
	fmt.Scan(&x, &y)

	// Calculate and print the maximum value between x + y - 3 + ( ( y - x ) % 3 > 0 ) and 0
	result := x + y - 3
	if (y-x)%3 > 0 {
		result++
	}
	if result < 0 {
		result = 0
	}
	fmt.Println(result)
}

// Helper functions for simplifying input process
func numInp() int {
	var n int
	fmt.Scan(&n)
	return n
}

func arrInp() []int {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	return arr
}

func spInp() []int {
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

func strInp() string {
	var s string
	fmt.Scan(&s)
	return s
}

// <END-OF-CODE>
