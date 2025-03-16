package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	var v string
	fmt.Scan(&v)

	d := []string{"LEFT", "RIGHT"}
	f := k-1 < n-k
	m := min(k-1, n-k)
	a := []string{}

	for i := 0; i < m; i++ {
		if f {
			a = append(a, d[0]) // "LEFT"
		} else {
			a = append(a, d[1]) // "RIGHT"
		}
	}

	for i := len(v) - 1; i >= 0; i-- {
		if f {
			a = append(a, "PRINT "+string(v[i]))
			a = append(a, d[1]) // "RIGHT"
		} else {
			a = append(a, "PRINT "+string(v[i]))
			a = append(a, d[0]) // "LEFT"
		}
	}

	fmt.Println(strings.Join(a[:len(a)-1], "\n"))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
