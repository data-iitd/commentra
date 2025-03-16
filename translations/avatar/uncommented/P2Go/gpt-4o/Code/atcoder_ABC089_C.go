package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)

	S := make([]string, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}

	march := []string{"M", "A", "R", "C", "H"}
	marchCount := make([]int, 5)

	for _, s := range S {
		for i, m := range march {
			if string(s[0]) == m {
				marchCount[i]++
			}
		}
	}

	ans := 0
	for i := 0; i < 5; i++ {
		for j := i + 1; j < 5; j++ {
			for k := j + 1; k < 5; k++ {
				ans += marchCount[i] * marchCount[j] * marchCount[k]
			}
		}
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
