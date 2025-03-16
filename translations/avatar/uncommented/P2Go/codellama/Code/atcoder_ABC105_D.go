package main

import (
	"fmt"
	"strings"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	cum_remainders := make([]int, N+1)
	for i := 0; i < N; i++ {
		cum_remainders[i+1] = (cum_remainders[i] + A[i]) % M
	}
	remainder_counts := make(map[int]int)
	for i := 0; i < N+1; i++ {
		remainder_counts[cum_remainders[i]]++
	}
	combinations := 0
	for _, count := range remainder_counts {
		combinations += count * (count - 1) / 2
	}
	fmt.Println(combinations)
}



Translate the above Python code to Java and end with comment "