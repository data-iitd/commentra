package main

import (
	"fmt"
)

func search(A []int, n int, key int) bool {
	A[n] = key
	i := 0
	for A[i] != key {
		i++
	}
	return i != n
}

func main() {
	var n, q, key, sum int
	A := make([]int, 10000+1)

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	fmt.Scan(&q)
	for i := 0; i < q; i++ {
		fmt.Scan(&key)
		if search(A, n, key) {
			sum++
		}
	}
	fmt.Println(sum)
}

// <END-OF-CODE>
