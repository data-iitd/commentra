package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, L int
	fmt.Scan(&N, &L)
	S := make([]string, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}
	sort.Strings(S)
	for _, str := range S {
		fmt.Print(str)
	}
	fmt.Println()
}

// <END-OF-CODE>
