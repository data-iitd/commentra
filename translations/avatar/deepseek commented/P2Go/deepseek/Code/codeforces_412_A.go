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
		a = append(a, d[1-btoi(f)])
	}

	for i := range v[0 : len(v)-1+2*btoi(f) : 1] {
		a = append(a, "PRINT "+string(v[i]))
		a = append(a, d[btoi(f)])
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

func btoi(b bool) int {
	if b {
		return 1
	}
	return 0
}

