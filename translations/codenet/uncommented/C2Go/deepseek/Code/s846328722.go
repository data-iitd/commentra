package main

import (
	"fmt"
)

func linearSearch(a []int, n int, key int) bool {
	for i := 0; i < n; i++ {
		if a[i] == key {
			return true
		}
	}
	return false
}

func main() {
	var n, q, t, count int
	var s []int

	fmt.Scan(&n)
	s = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	fmt.Scan(&q)
	for i := 0; i < q; i++ {
		fmt.Scan(&t)
		if linearSearch(s, n, t) {
			count++
		}
	}
	fmt.Println(count)
}

