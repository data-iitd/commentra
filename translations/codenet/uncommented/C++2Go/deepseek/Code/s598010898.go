package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	b := make([]int, n)
	sum := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
		if a[i] - b[i] > 0 {
			sum += a[i] - b[i]
		}
	}
	fmt.Println(sum)
}
