package main

import (
	"fmt"
)

func main() {
	var N, S int

	for {
		if _, err := fmt.Scan(&N); err != nil || N <= 0 {
			break
		}

		M := -1
		m := 1001
		addup := 0

		for i := 0; i < N; i++ {
			fmt.Scan(&S)
			addup += S
			if S > M {
				M = S
			}
			if S < m {
				m = S
			}
		}

		fmt.Println((addup - M - m) / (N - 2))
	}
}

