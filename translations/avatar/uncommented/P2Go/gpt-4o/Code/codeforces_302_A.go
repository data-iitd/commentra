package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	var input string
	fmt.Scan(&input)
	sa := strings.Count(input, "-")
	sa = min(n-sa, sa)

	var ss []string
	for i := 0; i < m; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		b -= a
		if b%2 != 0 && b <= sa*2 {
			ss = append(ss, "1\n")
		} else {
			ss = append(ss, "0\n")
		}
	}
	fmt.Print(strings.Join(ss, ""))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
