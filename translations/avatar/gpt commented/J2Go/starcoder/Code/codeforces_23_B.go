package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	scan := bufio.NewScanner(os.Stdin)

	// Read the number of test cases
	var t int
	scan.Scan()
	t, _ = strconv.Atoi(scan.Text())

	// Loop through each test case
	for i := 0; i < t; i++ {
		// Read the integer n for the current test case
		var n int
		scan.Scan()
		n, _ = strconv.Atoi(scan.Text())

		// Call the maxLeft function and print the result
		fmt.Println(maxLeft(n))
	}
}

// Function to calculate the maximum value based on the input n
func maxLeft(n int) int {
	// Return n - 2 if n is greater than 2, otherwise return 0
	if n > 2 {
		return n - 2
	}
	return 0
}

