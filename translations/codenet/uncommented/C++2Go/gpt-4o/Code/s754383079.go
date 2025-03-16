package main

import (
	"fmt"
	"math"
)

const M = 1010

func main() {
	var a, b [M]byte
	var n, m int
	ans := M + 10

	// Read the first string
	n, _ = fmt.Scanf("%s", &a[1])
	// Read the second string
	m, _ = fmt.Scanf("%s", &b[1])

	for i := 1; i+m-1 <= n; i++ {
		sum := 0
		for j := 1; j <= m; j++ {
			if a[i+j-1] != b[j] {
				sum++
			}
		}
		ans = int(math.Min(float64(ans), float64(sum)))
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
