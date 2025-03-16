package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
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

