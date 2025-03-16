package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var N, L int
	fmt.Scan(&N, &L)
	S := make([]string, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}
	sort.Strings(S)
	for i := 0; i < N; i++ {
		fmt.Print(S[i])
	}
	fmt.Println()
}

