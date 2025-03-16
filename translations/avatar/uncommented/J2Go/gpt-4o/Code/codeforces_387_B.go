package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	req := make([]int, n)
	pre := make([]int, m)

	for i := 0; i < n; i++ {
		fmt.Scan(&req[i])
	}
	for i := 0; i < m; i++ {
		fmt.Scan(&pre[i])
	}

	i, j := n-1, m-1
	ans := 0

	for i >= 0 && j >= 0 {
		if req[i] > pre[j] {
			ans++
		} else {
			j--
		}
		i--
	}

	fmt.Print(ans + i + 1)
}

// <END-OF-CODE>
