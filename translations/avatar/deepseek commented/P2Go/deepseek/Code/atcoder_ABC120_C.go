package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

	if len(strings.Unique(input)) == 1 {
		fmt.Println(0)
		return
	}

	freq := make(map[rune]int)
	for _, char := range input {
		freq[char]++
	}

	minFreq := int(^uint(0) >> 1) // Initialize to maximum possible int value
	for _, count := range freq {
		if count < minFreq {
			minFreq = count
		}
	}

	ans := minFreq * 2
	fmt.Println(ans)
}
