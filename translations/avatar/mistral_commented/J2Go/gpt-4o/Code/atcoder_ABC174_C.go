package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a buffered reader for input
	reader := bufio.NewReader(os.Stdin)
	
	// Read the input value of K
	input, _ := reader.ReadString('\n')
	K, _ := strconv.Atoi(strings.TrimSpace(input))

	// Call the solve function and print the result
	result := solve(K)
	fmt.Println(result)
}

// solve function to find the answer based on the value of K
func solve(K int) int {
	// Checking if K is even or a multiple of 5, returning -1 if true
	if K%2 == 0 || K%5 == 0 {
		return -1
	}

	// If K is a multiple of 7, divide it by 7 and multiply it by 9
	if K%7 == 0 {
		K /= 7
	}
	K *= 9

	// Initializing the answer variable and the remainder variable
	ans := 1
	remainder := 10 % K

	// Using a loop to find the answer
	for remainder != 1 {
		ans++ // Incrementing the answer variable
		remainder = (remainder * 10) % K // Updating the remainder variable
	}

	// Returning the answer
	return ans
}

// <END-OF-CODE>
