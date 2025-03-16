package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	var v string
	fmt.Scan(&v)

	d := []string{"LEFT", "RIGHT"}

	f := (k - 1) < (n - k)

	m := min(k-1, n-k)

	a := []string{}

	for i := 0; i < m; i++ {
		if !f {
			a = append(a, d[0]) // "LEFT"
		} else {
			a = append(a, d[1]) // "RIGHT"
		}
	}

	for i := 0; i < len(v); i += 2 * boolToInt(f) {
		a = append(a, fmt.Sprintf("PRINT %c", v[i]))
		if f {
			a = append(a, d[1]) // "RIGHT"
		} else {
			a = append(a, d[0]) // "LEFT"
		}
	}

	for _, line := range a[:len(a)-1] {
		fmt.Println(line)
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

// <END-OF-CODE>
