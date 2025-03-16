package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize scanner for input and print writer for output
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of test cases
	scanner.Scan()
	t := 0
	fmt.Sscan(scanner.Text(), &t)

	// Process each test case
	for t > 0 {
		t--

		// Read input values for each test case
		var n, a, b int64
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &n, &a, &b)

		// Check if n is less than a, if so, output "No"
		if n < a {
			fmt.Fprintln(writer, "No")
			continue
		}

		// If a equals b, check if n is a multiple of a
		if a == b {
			if n%a == 0 {
				fmt.Fprintln(writer, "Yes")
			} else {
				fmt.Fprintln(writer, "No")
			}
			continue
		}

		// Calculate the maximum number of a's that can fit into b
		x := b / (b - a)

		// If n is greater than x * a, output "Yes"
		if n > x*a {
			fmt.Fprintln(writer, "Yes")
			continue
		}

		// Binary search to find the largest mid such that mid * a < n
		low := int64(1)
		high := x + 1
		ans := int64(1)
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
			fmt.Fprintln(writer, "No")
		} else {
			fmt.Fprintln(writer, "Yes")
		}
	}
}
