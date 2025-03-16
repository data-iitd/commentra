package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func solution() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	
	// Remove the newline character
	line = line[:len(line)-1]
	
	// Count the occurrences of each color
	boughtCount := make(map[rune]int)
	for _, color := range line {
		boughtCount[color]++
	}
	
	line, _ = reader.ReadString('\n')
	
	// Remove the newline character
	line = line[:len(line)-1]
	
	// Count the occurrences of each color needed to make the tie
	madeCount := make(map[rune]int)
	for _, color := range line {
		madeCount[color]++
	}
	
	// Calculate the number of colors that can be used to make the tie
	res := 0
	for color := range madeCount {
		if _, exists := boughtCount[color]; !exists {
			fmt.Println(-1)
			return
		}
		res += min(boughtCount[color], madeCount[color])
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
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		solution()
	}
}
