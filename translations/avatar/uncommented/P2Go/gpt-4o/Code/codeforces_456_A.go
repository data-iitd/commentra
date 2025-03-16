package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	m := make([][]int, n)
	for i := 0; i < n; i++ {
		m[i] = make([]int, 2)
		fmt.Scan(&m[i][0], &m[i][1])
	}

	// Sort the slice in descending order based on the first element
	sort.Slice(m, func(i, j int) bool {
		return m[i][0] > m[j][0]
	})

	a := m[0]
	happy := false
	for _, i := range m[1:] {
		if i[1] > a[1] {
			fmt.Println("Happy Alex")
			happy = true
			break
		}
		a = i
	}

	if !happy {
		fmt.Println("Poor Alex")
	}
}

// <END-OF-CODE>
