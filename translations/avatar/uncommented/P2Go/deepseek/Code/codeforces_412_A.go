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
		a = append(a, d[1-f])
	}
	for i := range v[len(v)-1:0-(1-2*f)] {
		a = append(a, "PRINT "+string(v[i]))
		a = append(a, d[f])
	}
	for i := 0; i < len(a)-1; i++ {
		fmt.Println(a[i])
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

