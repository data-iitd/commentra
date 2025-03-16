package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	mn, mx := N+1, -1
	for i := 0; i < N; i++ {
		if (i+1 != A[i]) {
			if mn > i {
				mn = i
			}
			if mx < i {
				mx = i
			}
		}
	}
	if mx == -1 {
		fmt.Println("0 0")
	} else {
		A[mn], A[mx] = A[mx], A[mn]
		if sort.IntsAreSorted(A) {
			fmt.Println(mn+1, mx+1)
		} else {
			fmt.Println("0 0")
		}
	}
}
