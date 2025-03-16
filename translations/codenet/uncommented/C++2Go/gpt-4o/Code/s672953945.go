package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, L int
	fmt.Scan(&N, &L)

	v := make([]string, N)
	for i := 0; i < N; i++ {
		var s string
		fmt.Scan(&s)
		v[i] = s
	}

	sort.Strings(v)

	for _, str := range v {
		fmt.Print(str)
	}
	fmt.Println()
}

// <END-OF-CODE>
