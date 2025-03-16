package main

import (
	"fmt"
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
	n := 0
	if N%2 == 0 {
		n = N / 2
	} else {
		n = (N + 1) / 2
	}
	ans := sum(1) + sum(N-1)
	for A := 1; A <= n; A++ {
		if sum(A) + sum(N-A) < ans {
			ans = sum(A) + sum(N-A)
		}
	}
	fmt.Println(ans)
}

