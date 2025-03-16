package main

import (
	"fmt"
)

const (
	N = 1000000
	Q = 50000
)

var (
	n   int
	S   [N]int
	T   [Q]int
)

func binarySearch(key int) int {
	left := 0
	right := n
	for left < right {
		mid := (left + right) / 2
		if S[mid] == key {
			return 1
		} else if key < S[mid] {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return 0
}

func main() {
	var i, j, q, c int

	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		fmt.Scan(&S[i])
	}

	fmt.Scan(&q)
	for i = 0; i < q; i++ {
		fmt.Scan(&T[i])
		if binarySearch(T[i]) == 1 {
			c++
		}
	}

	fmt.Println(c)
}

