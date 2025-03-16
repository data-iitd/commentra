package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	ans := arr[0] + 1
	for i := 1; i < n; i++ {
		ans += abs(arr[i] - arr[i-1]) + 2
	}
	fmt.Println(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

