package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read two integers from the user, separated by a space
	var input string
	fmt.Scanln(&input)
	numbers := strings.Split(input, " ")
	A, _ := strconv.Atoi(numbers[0])
	B, _ := strconv.Atoi(numbers[1])

	// Calculate the difference between A and 2 times B
	ans := A - 2 * B

	// Check if the difference is negative
	if ans < 0 {
		// If it is, set it to zero
		ans = 0
	}

	// Print the final answer
	fmt.Println(ans)
}
