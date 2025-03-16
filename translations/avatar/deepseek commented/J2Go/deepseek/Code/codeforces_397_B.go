package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new scanner to read input from the standard input stream.
	scanner := bufio.NewScanner(os.Stdin)
	// Create a new PrintWriter to write output to the standard output stream.
	writer := bufio.NewWriter(os.Stdout)
	// Read the number of test cases.
	scanner.Scan()
	t := 0
	fmt.Sscan(scanner.Text(), &t)
	// Process each test case.
	for t > 0 {
		t--
		// Read the values of n, a, and b.
		var n, a, b int64
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &n, &a, &b)
		// Check if n is less than a.
		if n < a {
			writer.WriteString("No\n")
			continue
		}
		// Check if a is equal to b.
		if a == b {
			if n%a == 0 {
				writer.WriteString("Yes\n")
			} else {
				writer.WriteString("No\n")
			}
			continue
		}
		// Calculate x as b / (b - a).
		x := b / (b - a)
		// Check if n is greater than x * a.
		if n > x*a {
			writer.WriteString("Yes\n")
			continue
		}
		// Perform binary search to find the minimum ans.
		low := int64(1)
		high := x + 1
		ans := int64(1)
		for low <= high {
			mid := (low + high) / 2
			if mid*a < n {
				low = mid + 1
			} else {
				ans = mid
				high = mid - 1
			}
		}
		// Check if n lies between (ans - 1) * b and ans * a.
		if n > (ans-1)*b && n < ans*a {
			writer.WriteString("No\n")
		} else {
			writer.WriteString("Yes\n")
		}
	}
	// Flush the output to ensure all data is written.
	writer.Flush()
}

