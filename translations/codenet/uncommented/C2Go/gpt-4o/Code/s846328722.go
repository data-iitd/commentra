package main

import (
	"fmt"
)

func linearSearch(a []int, n int, key int) bool {
	a = append(a, key) // Append the key to the slice

	i := 0
	for a[i] != key {
		i++
	}
	return i != n
}

func main() {
	var n, q, t int
	count := 0

	fmt.Scan(&n)
	s := make([]int, n)

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

// <END-OF-CODE>
