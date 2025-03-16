package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1] // Remove the newline character

	// Create a map to count occurrences of each character
	counts := make(map[rune]int)
	for _, char := range s {
		counts[char]++
	}

	if len(counts) == 1 {
		fmt.Println(0)
		return
	}

	minCount := len(s)
	for _, count := range counts {
		if count < minCount {
			minCount = count
		}
	}

	ans := minCount * 2
	fmt.Println(ans)
}

// <END-OF-CODE>
