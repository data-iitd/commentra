
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Initialize an empty string's' by reading input from the user
	s := bufio.NewReader(os.Stdin)
	input, _, _ := s.ReadLine()
	s = string(input)

	// Create two maps 'even' and 'odd' to count the frequency of '0' and '1' in the first and second half of the string's' respectively
	even := make(map[string]int)
	odd := make(map[string]int)
	for _, v := range strings.Split(s[:len(s)/2], "") {
		even[v]++
	}
	for _, v := range strings.Split(s[len(s)/2:], "") {
		odd[v]++
	}

	// Print the minimum difference between the length of the string's' and the sum of the frequencies of '0' and '1' in either half of the string
	fmt.Println(min(len(s)-(even["0"]+odd["1"]), len(s)-(even["1"]+odd["0"])))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

