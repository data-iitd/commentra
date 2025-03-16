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

	input, _ := fmt.Scanln()
	nums := strings.Fields(input)
	A := make([][2]int, N)

	for i, x := range nums {
		val, _ := strconv.Atoi(x)
		A[i] = [2]int{i + 1, val}
	}

	sort.Slice(A, func(i, j int) bool {
		return A[i][1] < A[j][1]
	})

	A_ := make([]int, N)
	for i, a := range A {
		A_[i] = a[0]
	}

	for i := 0; i < N-1; i++ {
		fmt.Print(A_[i], " ")
	}
	fmt.Println(A_[N-1])
}

// <END-OF-CODE>
