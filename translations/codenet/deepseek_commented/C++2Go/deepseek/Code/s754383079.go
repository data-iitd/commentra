package main

import (
	"fmt"
	"strings"
)

const M = 1010

func main() {
	var a, b [M]string
	var n, m, ans int = M + 10, 0, 0

	// Read input strings
	fmt.Scan(&a[1])
	n = len(a[1])
	fmt.Scan(&b[1])
	m = len(b[1])

	// Calculate the minimum number of differences
	for i := 1; i+m-1 <= n; i++ {
		sum := 0
		for j := 1; j <= m; j++ {
			if a[1][i+j-1] != b[1][j-1] {
				sum++
			}
		}
		if sum < ans {
			ans = sum
		}
	}

	// Output the result
	fmt.Println(ans)
}
