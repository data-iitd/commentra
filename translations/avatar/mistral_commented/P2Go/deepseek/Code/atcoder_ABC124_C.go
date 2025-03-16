package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = input[:len(input)-1] // Remove the newline character

	s := []rune(input)
	half := len(s) / 2

	even := make(map[rune]int)
	odd := make(map[rune]int)

	for i := 0; i < half; i++ {
		even[s[i]]++
	}
	for i := half; i < len(s); i++ {
		odd[s[i]]++
	}

	minDiff := func(a, b int) int {
		if a < b {
			return a
		}
		return b
	}

	fmt.Println(minDiff(len(s)-(even['0']+odd['1']), len(s)-(even['1']+odd['0'])))
}

