package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	ans := 0
	count := 0
	for i := 0; i < N-1; i++ {
		if A[i] == A[i+1] {
			count++
			if count%2 != 0 {
				ans++
			}
		} else {
			count = 0
		}
	}

	fmt.Println(ans)
}

