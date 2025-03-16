package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Reading an integer input from the user
	var input string
	fmt.Scanln(&input)
	n, _ := strconv.Atoi(input)

	// Calling the solve function with the input integer
	solve(n)
}

func solve(n int) {
	// Calculating and printing the result based on the input integer n
	// The formula calculates (n / 3) * 2 and adds 1 if n is not divisible by 3
	result := (n / 3) * 2
	if n%3 != 0 {
		result += 1
	}
	fmt.Println(result)
}

// <END-OF-CODE>
