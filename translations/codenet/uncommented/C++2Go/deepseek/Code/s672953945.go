package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var N, L int
	var v []string

	fmt.Scan(&N, &L)
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		v = append(v, s)
	}

	sort.Strings(v)

	for i := 0; i < len(v); i++ {
		fmt.Print(v[i])
	}
	fmt.Println()
}

