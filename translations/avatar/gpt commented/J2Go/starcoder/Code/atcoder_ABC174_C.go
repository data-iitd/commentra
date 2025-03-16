package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the integer K from input
	K, _ := strconv.Atoi(readLine())

	// Check if K is even or divisible by 5, return -1 if true
	if K%2 == 0 || K%5 == 0 {
		fmt.Println(-1)
		return
	}

	// If K is divisible by 7, divide it by 7
	if K%7 == 0 {
		K /= 7
	}

	// Multiply K by 9 as part of the calculation
	K *= 9

	// Initialize the answer counter
	ans := 1

	// Calculate the remainder of 10 divided by K
	remainder := 10 % K

	// Loop until the remainder is 1
	for remainder!= 1 {
		// Increment the answer counter
		ans++
		// Update the remainder for the next iteration
		remainder = remainder * 10 % K
	}

	// Return the final answer
	fmt.Println(ans)
}

func readLine() string {
	if _, err := fmt.Scanln(&line); err!= nil {
		panic(err)
	}
	return line
}

var (
	line string
)

