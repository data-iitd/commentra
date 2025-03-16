package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var N, L int
	fmt.Scan(&N, &L)

	var v []string
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		v = append(v, s)
	}

	sort.Strings(v)

	for _, s := range v {
		fmt.Print(s)
	}
	fmt.Println()
}

