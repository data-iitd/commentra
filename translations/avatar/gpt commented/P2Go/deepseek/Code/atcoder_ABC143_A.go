package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read two integers A and B from user input, separated by a space
	var input string
	fmt.Scanln(&input)
	numbers := strings.Split(input, " ")
	A, _ := strconv.Atoi(numbers[0])
	B, _ := strconv.Atoi(numbers[1])

	// Calculate the result by subtracting twice the value of B from A
	ans := A - 2 * B

	// If the result is negative, set it to zero
	if ans < 0 {
		ans = 0
	}

	// Print the final result
	fmt.Println(ans)
}
