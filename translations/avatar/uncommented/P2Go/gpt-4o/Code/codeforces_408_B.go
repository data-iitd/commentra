package main

import (
	"fmt"
	"strings"
)

func solution() {
	var line string
	fmt.Scanln(&line)
	boughtCount := make(map[rune]int)
	for _, color := range line {
		boughtCount[color]++
	}

	fmt.Scanln(&line)
	madeCount := make(map[rune]int)
	for _, color := range line {
		madeCount[color]++
	}

	res := 0
	for color, made := range madeCount {
		if _, exists := boughtCount[color]; !exists {
			fmt.Println(-1)
			return
		}
		res += min(boughtCount[color], made)
	}
	fmt.Println(res)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	t := 1
	for i := 0; i < t; i++ {
		solution()
	}
}

// <END-OF-CODE>
