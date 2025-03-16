package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements to be processed
	fmt.Print("Enter the number of elements to be processed: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	// Initialize variables to hold the sums of three different sets of integers
	a := 0
	b := 0
	c := 0

	// Read n integers and calculate their sum (a)
	for i := 0; i < n; i++ {
		fmt.Print("Enter the next integer: ")
		input, _ := reader.ReadString('\n')
		a += atoi(strings.TrimSpace(input))
	}

	// Read n-1 integers and calculate their sum (b)
	for i := 0; i < n-1; i++ {
		fmt.Print("Enter the next integer: ")
		input, _ := reader.ReadString('\n')
		b += atoi(strings.TrimSpace(input))
	}

	// Read n-2 integers and calculate their sum (c)
	for i := 0; i < n-2; i++ {
		fmt.Print("Enter the next integer: ")
		input, _ := reader.ReadString('\n')
		c += atoi(strings.TrimSpace(input))
	}

	// Calculate the difference between the sums: x = sum of first set - sum of second set
	x := a - b

	// Calculate the difference between the sums: y = sum of second set - sum of third set
	y := b - c

	// Print the results of the differences
	fmt.Println(x)
	fmt.Println(y)
}

func atoi(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

