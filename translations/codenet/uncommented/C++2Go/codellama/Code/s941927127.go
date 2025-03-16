package main

import (
	"fmt"
	"sort"
)

func main() {
	var W string
	fmt.Scan(&W)

	sort.Slice(W, func(i, j int) bool {
		return W[i] < W[j]
	})

	for i := 0; i < len(W); i += 2 {
		if W[i] != W[i+1] {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}

