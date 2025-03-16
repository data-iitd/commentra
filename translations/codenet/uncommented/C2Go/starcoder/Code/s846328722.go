package main

import (
	"fmt"
)

func linersearch(a []int, n int, key int) bool {
	a[n] = key
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
	fmt.Scanf("%d", &n)
	s = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &s[i])
	}
	fmt.Scanf("%d", &q)
	for i := 0; i < q; i++ {
		fmt.Scanf("%d", &t)
		if linersearch(s, n, t) {
			count++
		}
	}
	fmt.Printf("%d\n", count)
}

