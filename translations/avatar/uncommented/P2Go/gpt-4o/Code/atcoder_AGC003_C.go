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
		var input int
		fmt.Scan(&input)
		A[i] = input*N + i
	}

	sort.Ints(A)

	cnt := 0
	for i := 0; i < N; i++ {
		d := (A[i] % N) % 2
		if d%2 != i%2 {
			cnt++
		}
	}
	fmt.Println(cnt / 2)
}

// <END-OF-CODE>
