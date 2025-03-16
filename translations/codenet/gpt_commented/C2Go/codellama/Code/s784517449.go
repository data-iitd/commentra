package main

import (
	"fmt"
)

func binarySearch(key int, A []int, n int) int {
	left := 0
	right := n
	mid := 0

	for left < right {
		mid = (left + right) / 2
		if key == A[mid] {
			return 1
		}
		if key > A[mid] {
			left = mid + 1
		} else if key < A[mid] {
			right = mid
		}
	}
	return 0
}

func main() {
	var n, q, k, sum int
	fmt.Scan(&n)
	A := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	fmt.Scan(&q)
	for i := 0; i < q; i++ {
		fmt.Scan(&k)
		if binarySearch(k, A, n) == 1 {
			sum++
		}
	}
	fmt.Println(sum)
}

