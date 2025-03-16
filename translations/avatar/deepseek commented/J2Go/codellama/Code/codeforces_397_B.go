
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Scanner to read input from the standard input stream.
	in := bufio.NewScanner(os.Stdin)
	// PrintWriter to write output to the standard output stream.
	out := bufio.NewWriter(os.Stdout)
	// Read the number of test cases.
	var t int
	in.Scan()
	t, _ = strconv.Atoi(in.Text())
	// Process each test case.
	for t > 0 {
		// Read the values of n, a, and b.
		var n, a, b int64
		in.Scan()
		n, _ = strconv.ParseInt(in.Text(), 10, 64)
		in.Scan()
		a, _ = strconv.ParseInt(in.Text(), 10, 64)
		in.Scan()
		b, _ = strconv.ParseInt(in.Text(), 10, 64)
		// Check if n is less than a.
		if n < a {
			fmt.Fprintln(out, "No")
			t--
			continue
		}
		// Check if a is equal to b.
		if a == b {
			if n%a == 0 {
				fmt.Fprintln(out, "Yes")
			} else {
				fmt.Fprintln(out, "No")
			}
			t--
			continue
		}
		// Calculate x as b / (b - a).
		x := b / (b - a)
		// Check if n is greater than x * a.
		if n > x*a {
			fmt.Fprintln(out, "Yes")
			t--
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
			fmt.Fprintln(out, "No")
		} else {
			fmt.Fprintln(out, "Yes")
		}
		t--
	}
	// Close the PrintWriter to flush the output.
	out.Flush()
}

