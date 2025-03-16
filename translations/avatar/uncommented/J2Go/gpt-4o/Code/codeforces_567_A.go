package main

import (
	"fmt"
)

func main() {
	var a int
	fmt.Scan(&a)
	ar := make([]int, a)
	for i := 0; i < a; i++ {
		fmt.Scan(&ar[i])
	}

	for i := 0; i < a; i++ {
		var max, min int
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

func maxInt(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func minInt(x, y int) int {
	if x < y {
		return x
	}
	return y
}
