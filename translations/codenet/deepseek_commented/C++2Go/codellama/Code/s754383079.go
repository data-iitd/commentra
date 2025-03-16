package main

import (
	"fmt"
	"strings"
)

func main() {
	// Step 3: Read input strings
	var a, b string
	fmt.Scan(&a, &b)
	n := len(a)
	m := len(b)

	// Step 4: Calculate the minimum number of differences
	ans := n + m
	for i := 0; i+m <= n; i++ {
		sum := 0
		for j := 0; j < m; j++ {
			if a[i+j] != b[j] {
				sum++
			}
		}
		if sum < ans {
			ans = sum
		}
	}

	// Step 5: Output the result
	fmt.Println(ans)
}

