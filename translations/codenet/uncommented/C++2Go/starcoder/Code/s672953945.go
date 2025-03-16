package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, L int
	var v []string
	fmt.Scanf("%d %d", &N, &L)
	for i := 0; i < N; i++ {
		var s string
		fmt.Scanf("%s", &s)
		v = append(v, s)
	}
	sort.Strings(v)
	for i := 0; i < len(v); i++ {
		fmt.Printf("%s", v[i])
	}
	fmt.Println()
}

