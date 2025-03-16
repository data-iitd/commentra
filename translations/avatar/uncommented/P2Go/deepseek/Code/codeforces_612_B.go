package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	
	var a []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		a = append(a, x)
	}
	
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[a[i]-1] = i
	}
	
	res := 0
	for i := 1; i < n; i++ {
		res += abs(b[i] - b[i-1])
	}
	
	fmt.Println(res)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

