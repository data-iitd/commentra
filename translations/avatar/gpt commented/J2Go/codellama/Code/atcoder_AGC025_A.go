
package main

import (
	"fmt"
	"math"
)

func sum(a int) int {
	ans := 0
	for a >= 10 {
		ans += a % 10
		a /= 10
	}
	ans += a
	return ans
}

func main() {
	var N int
	fmt.Scan(&N)
	n := N / 2
	if N%2 == 1 {
		n = (N + 1) / 2
	}
	ans := sum(1) + sum(N-1)
	for A := 1; A <= n; A++ {
		if sum(A)+sum(N-A) < ans {
			ans = sum(A) + sum(N-A)
		}
	}
	fmt.Println(ans)
}

