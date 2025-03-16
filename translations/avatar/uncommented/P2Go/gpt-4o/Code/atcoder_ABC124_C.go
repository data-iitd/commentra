package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)

	even := make(map[rune]int)
	odd := make(map[rune]int)

	for i, char := range s {
		if i%2 == 0 {
			even[char]++
		} else {
			odd[char]++
		}
	}

	countEven0 := even['0']
	countEven1 := even['1']
	countOdd0 := odd['0']
	countOdd1 := odd['1']

	result := min(len(s)-(countEven0+countOdd1), len(s)-(countEven1+countOdd0))
	fmt.Println(result)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
