package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define constants for the problem
const (
	N = 1000000000 + 7
)

func main() {
	// Initialize scanner for input and print writer for output
	in := bufio.NewScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	// Read the number of test cases
	var t int
	in.Scan()
	t, _ = strconv.Atoi(in.Text())

	// Process each test case
	for t > 0 {
		// Read input values for each test case
		var n, a, b int
		in.Scan()
		n, _ = strconv.Atoi(in.Text())
		in.Scan()
		a, _ = strconv.Atoi(in.Text())
		in.Scan()
		b, _ = strconv.Atoi(in.Text())

		// Check if n is less than a, if so, output "No"
		if n < a {
			fmt.Fprintln(out, "No")
			continue
		}

		// If a equals b, check if n is a multiple of a
		if a == b {
			if n%a == 0 {
				fmt.Fprintln(out, "Yes")
			} else {
				fmt.Fprintln(out, "No")
			}
			continue
		}

		// Calculate the maximum number of a's that can fit into b
		x := b / (b - a)

		// If n is greater than x * a, output "Yes"
		if n > x*a {
			fmt.Fprintln(out, "Yes")
			continue
		}

		// Binary search to find the largest mid such that mid * a < n
		low := 1
		high := x + 1
		ans := 1
		for low <= high {
			mid := (low + high) / 2

			// Adjust the search range based on the condition
			if mid*a < n {
				low = mid + 1
			} else {
				ans = mid
				high = mid - 1
			}
		}

		// Check the final conditions to determine output
		if n > (ans-1)*b && n < ans*a {
			fmt.Fprintln(out, "No")
		} else {
			fmt.Fprintln(out, "Yes")
		}

		// Decrement the number of test cases
		t--
	}

	// Close the output writer
	out.Flush()
}

