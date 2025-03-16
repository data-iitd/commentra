package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	arrs := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arrs[i])
	}

	length := make([]int, n)
	for i := 0; i < n; i++ {
		dexG := indexOf(arrs[i], "G")
		dexS := indexOf(arrs[i], "S")
		if dexG > dexS {
			fmt.Println(-1)
			return
		}
		length[i] = dexS - dexG
	}

	set := make(map[int]bool)
	for _, len := range length {
		set[len] = true
	}

	fmt.Println(len(set))
}

func indexOf(s, substr string) int {
	for i := 0; i < len(s); i++ {
		if s[i:i+len(substr)] == substr {
			return i
		}
	}
	return -1
}

