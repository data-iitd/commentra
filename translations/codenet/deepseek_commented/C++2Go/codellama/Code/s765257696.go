package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)

	p := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i])
	}

	ans := 0
	for i := 0; i < n-2; i++ {
		if p[i] > p[i+1] && p[i+1] > p[i+2] {
			ans++
		}
		if p[i] < p[i+1] && p[i+1] < p[i+2] {
			ans++
		}
	}

	fmt.Println(ans)
}

