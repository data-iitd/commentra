package main

import (
	"fmt"
)

func linearSearch(S []int, n int, key int) int {
	i := 0
	for i < n {
		if S[i] == key {
			return 0
		}
		i++
	}
	return 1
}

func main() {
	var n, q int
	count := 0

	fmt.Scan(&n)
	S := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&S[i])
	}

	fmt.Scan(&q)
	T := make([]int, q)
	for j := 0; j < q; j++ {
		fmt.Scan(&T[j])
	}

	for j := 0; j < q; j++ {
		key := T[j]
		if linearSearch(S, n, key) == 1 {
			count++
		}
	}

	fmt.Println(count)
}

// <END-OF-CODE>
