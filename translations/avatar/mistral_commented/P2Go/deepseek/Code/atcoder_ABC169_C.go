package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set the recursion limit to a large value
	// This is not necessary in Go as it uses a stack-based recursion by default

	// Import other required modules
	// Go does not have equivalent modules like os, collections, etc.
	// We will use standard library functions instead

	// Define a debug function to print debug messages
	// This function is used only when running the program in an IDE or terminal
	setDebug := func(something ...interface{}) {
		if os.Getenv("TERM_PROGRAM") != "" {
			fmt.Println(something...)
		}
	}

	// Define the input function to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)
	input := func() string {
		scanner.Scan()
		return strings.TrimSpace(scanner.Text())
	}

	// Define a function to read multiple integers as a list
	LMIIS := func() []int {
		line := input()
		parts := strings.Split(line, " ")
		nums := make([]int, len(parts))
		for i, part := range parts {
			num, _ := strconv.Atoi(part)
			nums[i] = num
		}
		return nums
	}

	// Define input reading functions for single integer and string
	II := func() int {
		line := input()
		num, _ := strconv.Atoi(line)
		return num
	}

	const P = 1000000007
	const INF = 10000000010

	// Read input for two numbers 'a' and 'b'
	sa, sb := input(), input()
	a, _ := strconv.Atoi(sa)
	bFloat, _ := strconv.ParseFloat(sb, 64)
	b := int(bFloat * 100)

	// Calculate the product of 'a' and 'b' and print the result
	result := a * b / 100
	fmt.Println(result)
}

