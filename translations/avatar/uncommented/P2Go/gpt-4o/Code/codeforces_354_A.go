package main

import (
	"fmt"
)

func main() {
	var n, L, R, QL, QR int
	fmt.Scan(&n, &L, &R, &QL, &QR)

	W := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&W[i])
	}

	sumEl := make([]int, n+1)
	for i := 1; i <= n; i++ {
		sumEl[i] = W[i-1] + sumEl[i-1]
	}

	answer := QR*(n-1) + sumEl[n]*R
	for i := 1; i <= n; i++ {
		energy := L*sumEl[i] + R*(sumEl[n]-sumEl[i])
		if i > (n - i) {
			energy += (i - (n - i) - 1) * QL
		} else if (n - i) > i {
			energy += ((n - i) - i - 1) * QR
		}
		if energy < answer {
			answer = energy
		}
	}
	fmt.Println(answer)
}

// <END-OF-CODE>
