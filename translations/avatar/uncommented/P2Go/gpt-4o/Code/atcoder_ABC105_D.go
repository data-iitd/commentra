package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	cumRemainders := make([]int64, N+1)
	cumRemainders[0] = 0
	for i := 1; i <= N; i++ {
		cumRemainders[i] = (cumRemainders[i-1] + A[i-1]) % int64(M)
	}

	remainderCounts := make(map[int64]int)
	for _, remainder := range cumRemainders {
		remainderCounts[remainder]++
	}

	combinations := int64(0)
	for _, count := range remainderCounts {
		combinations += int64(count) * (int64(count) - 1) / 2
	}

	fmt.Println(combinations)
}

// <END-OF-CODE>
