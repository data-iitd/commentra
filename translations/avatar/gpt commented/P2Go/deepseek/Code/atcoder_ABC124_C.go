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

	// Convert input string to a slice of characters
	s := strings.Split(input, "")

	// Count the occurrences of '0' and '1' at even indices
	even := make(map[string]int)
	for i := 0; i < len(s); i += 2 {
		even[s[i]]++
	}

	// Count the occurrences of '0' and '1' at odd indices
	odd := make(map[string]int)
	for i := 1; i < len(s); i += 2 {
		odd[s[i]]++
	}

	// Calculate the minimum number of changes needed to make the string alternate
	// Option 1: Change all even indexed '0's to '1's and odd indexed '1's to '0's
	// Option 2: Change all even indexed '1's to '0's and odd indexed '0's to '1's
	// Print the minimum of the two options
	option1 := len(s) - (even["0"] + odd["1"])
	option2 := len(s) - (even["1"] + odd["0"])
	fmt.Println(min(option1, option2))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
