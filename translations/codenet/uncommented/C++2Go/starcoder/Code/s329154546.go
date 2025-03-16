package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var N, L int
	fmt.Scanf("%d %d", &N, &L)
	S := make([]string, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%s", &S[i])
	}
	sort.Strings(S)
	for i := 0; i < N; i++ {
		fmt.Printf("%s", S[i])
	}
	fmt.Println()
}

