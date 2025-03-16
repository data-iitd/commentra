package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	roundComplexity := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&roundComplexity[i])
	}

	georgeComplexity := make([]int, m)
	for j := 0; j < m; j++ {
		fmt.Scan(&georgeComplexity[j])
	}

	i, j := 0, 0
	for i < n && j < m {
		if roundComplexity[i] <= georgeComplexity[j] {
			i++
		}
		j++
	}

	fmt.Println(n - i)
}

// <END-OF-CODE>
