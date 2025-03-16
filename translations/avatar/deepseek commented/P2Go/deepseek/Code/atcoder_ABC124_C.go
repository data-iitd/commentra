package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"collections"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	// Create a Counter object `even` that counts the occurrences of characters at even indices in the string `s`
	even := collections.Counter()
	for i := 0; i < len(s); i += 2 {
		even.Update(string(s[i]))
	}

	// Create a Counter object `odd` that counts the occurrences of characters at odd indices in the string `s`
	odd := collections.Counter()
	for i := 1; i < len(s); i += 2 {
		odd.Update(string(s[i]))
	}

	// Print the minimum of two possible outcomes:
	// 1. The number of characters that need to be flipped to make all even characters '0' and the number of characters that need to be flipped to make all even characters '1', or vice versa.
	fmt.Println(min(len(s) - (even.Get("0") + odd.Get("1")), len(s) - (even.Get("1") + odd.Get("0"))))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
