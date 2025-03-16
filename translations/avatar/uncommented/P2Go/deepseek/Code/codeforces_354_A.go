package main

import (
	"fmt"
)

func main() {
	var n, L, R, QL, QR int
	fmt.Scan(&n, &L, &R, &QL, &QR)

	var W []int
	for i := 0; i < n; i++ {
		var w int
		fmt.Scan(&w)
		W = append(W, w)
	}

	sum_el := make([]int, n+1)
	for i := 1; i <= n; i++ {
		sum_el[i] = W[i-1] + sum_el[i-1]
	}

	answer := QR * (n - 1) + sum_el[n] * R

	for i := 1; i <= n; i++ {
		energy := L * sum_el[i] + R * (sum_el[n] - sum_el[i])
		if i > (n - i) {
			energy = energy + (i - (n - i) - 1) * QL
		} else if (n - i) > i {
			energy = energy + ((n - i) - i - 1) * QR
		}
		if energy < answer {
			answer = energy
		}
	}

	fmt.Println(answer)
}

