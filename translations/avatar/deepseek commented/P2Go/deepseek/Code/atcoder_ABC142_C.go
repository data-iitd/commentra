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

	var input string
	fmt.Scan(&input)

	parts := strings.Split(input, " ")
	A := make([][2]int, N)
	for i := 0; i < N; i++ {
		A[i][0] = i + 1
		A[i][1], _ = strconv.Atoi(parts[i])
	}

	sort.Slice(A, func(i, j int) bool {
		return A[i][1] < A[j][1]
	})

	A_ := make([]int, N)
	for i := 0; i < N; i++ {
		A_[i] = A[i][0]
	}

	for i := 0; i < N-1; i++ {
		fmt.Print(A_[i], " ")
	}
	fmt.Println(A_[N-1])
}

