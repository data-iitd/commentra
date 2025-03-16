package main

import "fmt"

func binarySearch(key int, S []int, n int) int {
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
	var n, q, c int
	fmt.Scan(&n)
	S := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&S[i])
	}
	fmt.Scan(&q)
	T := make([]int, q)
	for i := 0; i < q; i++ {
		fmt.Scan(&T[i])
		if binarySearch(T[i], S, n) == 1 {
			c++
		}
	}
	fmt.Println(c)
}

