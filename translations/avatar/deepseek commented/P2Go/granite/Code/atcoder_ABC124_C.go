

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Take a string input from the user and store it in the variable `s`
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	// Create a Counter object `even` that counts the occurrences of characters at even indices in the string `s`
	even := make(map[string]int)
	for i, c := range s {
		if i%2 == 0 {
			even[string(c)]++
		}
	}

	// Create a Counter object `odd` that counts the occurrences of characters at odd indices in the string `s`
	odd := make(map[string]int)
	for i, c := range s {
		if i%2 == 1 {
			odd[string(c)]++
		}
	}

	// Print the minimum of two possible outcomes:
	// 1. The number of characters that need to be flipped to make all even characters '0' and the number of characters that need to be flipped to make all even characters '1', or vice versa.
	fmt.Println(min(len(s)-(even["0"]+odd["1"]), len(s)-(even["1"]+odd["0"])))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
