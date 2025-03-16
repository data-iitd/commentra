package main

import (
	"fmt"
)

func main() {
	var x, y int
	fmt.Scan(&x, &y)

	result := max(x+y-3+boolToInt((y-x)%3 > 0), 0)
	fmt.Println(result)
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

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
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	return arr
}

func strInp() string {
	var s string
	fmt.Scan(&s)
	return s
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
