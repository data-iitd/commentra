package main

import (
	"bufio"
	"fmt"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

	even := make(map[rune]int)
	odd := make(map[rune]int)

	for i, char := range input {
		if i%2 == 0 {
			even[char]++
		} else {
			odd[char]++
		}
	}

	minFlips := func(even, odd map[rune]int) int {
		return min(len(input), len(input)-(even['0']+odd['1']), len(input)-(even['1']+odd['0']))
	}

	fmt.Println(minFlips(even, odd))
}

func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		}
		return c
	}
	if b < c {
		return b
	}
	return c
}

