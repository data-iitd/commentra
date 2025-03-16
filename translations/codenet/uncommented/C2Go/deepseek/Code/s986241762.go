package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	sum := 0
	for i := 1; i < n; i++ {
		if a[i-1] > a[i] {
			sum += a[i-1] - a[i]
			a[i] = a[i-1]
		}
	}
	fmt.Println(sum)
}
