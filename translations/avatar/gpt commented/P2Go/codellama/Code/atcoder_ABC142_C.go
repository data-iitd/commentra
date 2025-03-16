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

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	sort.Ints(A)

	for i := 0; i < N-1; i++ {
		fmt.Print(A[i], " ")
	}
	fmt.Println(A[N-1])
}

