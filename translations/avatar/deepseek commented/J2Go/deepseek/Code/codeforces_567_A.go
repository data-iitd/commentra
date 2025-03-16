package main

import (
	"fmt"
)

func main() {
	var a int
	fmt.Scan(&a)
	ar := make([]int, a)
	var min, max int

	for i := 0; i < a; i++ {
		fmt.Scan(&ar[i])
	}

	for i := 0; i < a; i++ {
		max = maxInt(ar[i]-ar[0], ar[a-1]-ar[i])
		if i == 0 {
			min = ar[i+1] - ar[i]
		} else if i == a-1 {
			min = ar[i] - ar[i-1]
		} else {
			min = minInt(ar[i]-ar[i-1], ar[i+1]-ar[i])
		}
		fmt.Println(min, max)
	}
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

