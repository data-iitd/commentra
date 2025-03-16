package main

import (
	"fmt"
	"sort"
)

func main() {
	var W string
	fmt.Scan(&W)

	// Convert string to a slice of runes for sorting
	runes := []rune(W)
	sort.Slice(runes, func(i, j int) bool {
		return runes[i] < runes[j]
	})

	for i := 0; i < len(runes); i += 2 {
		if i+1 >= len(runes) || runes[i] != runes[i+1] {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}

// <END-OF-CODE>
