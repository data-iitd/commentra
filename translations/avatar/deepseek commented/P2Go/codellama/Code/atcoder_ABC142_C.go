
package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)

	A := make([][2]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i][1])
		A[i][0] = i + 1
	}

	sort.Slice(A, func(i, j int) bool {
		return A[i][1] < A[j][1]
	})

	for i := 0; i < N-1; i++ {
		fmt.Print(A[i][0], " ")
	}
	fmt.Println(A[N-1][0])
}

