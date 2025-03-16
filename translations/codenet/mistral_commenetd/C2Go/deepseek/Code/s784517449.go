package main

import (
	"fmt"
)

var A [1000000]int
var n int

func binarySearch(key int) int {
	left := 0
	right := n
	var mid int

	for left < right {
		mid = (left + right) / 2
		if key == A[mid] {
			return 1
		}
		if key > A[mid] {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return 0
}

func main() {
	var i, q, k, sum int

	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	fmt.Scan(&q)
	for i = 0; i < q; i++ {
		fmt.Scan(&k)
		if binarySearch(k) == 1 {
			sum++
		}
	}
	fmt.Println(sum)
}

