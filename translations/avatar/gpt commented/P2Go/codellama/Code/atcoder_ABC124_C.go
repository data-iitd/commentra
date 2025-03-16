
package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read input string and convert it into a list of characters
	s := strings.Split(strings.TrimSpace(input()), "")

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
	fmt.Println(min(len(s), even["0"]+odd["1"], even["1"]+odd["0"]))
}

func min(a int, b ...int) int {
	min := a
	for _, v := range b {
		if v < min {
			min = v
		}
	}
	return min
}

func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

