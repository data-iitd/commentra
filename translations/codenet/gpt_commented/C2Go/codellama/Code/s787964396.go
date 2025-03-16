package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n+1)
	b := make([]int, n+1)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i+1])
	}
	CountingSort(a, b, n)
	fmt.Print(b[1])
	for i := 2; i < n+1; i++ {
		fmt.Print(" ", b[i])
	}
	fmt.Println()
}

func CountingSort(a []int, b []int, k int) {
	c := make([]int, k+1)
	for i := 0; i <= k; i++ {
		c[i] = 0
	}
	for j := 0; j < k; j++ {
		c[a[j+1]]++
	}
	for i := 1; i < k+1; i++ {
		c[i] += c[i-1]
	}
	for j := k; 0 < j; j-- {
		b[c[a[j]]] = a[j]
		c[a[j]]--
	}
}

