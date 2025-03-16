package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read a line of input, split it into components, and convert each component to an integer
	a := make([]int, 0)
	for _, i := range strings.Split(input(), " ") {
		j, _ := strconv.Atoi(i)
		a = append(a, j)
	}

	// Iterate over the list 'a' using enumerate to get both the index (e) and the value (i)
	for e, i := range a {
		// Check if the current value is zero
		if i == 0 {
			// Print the index (1-based) of the first occurrence of zero
			fmt.Println(e + 1)
			// Exit the loop after finding the first zero
			break
		}
	}
}

// 