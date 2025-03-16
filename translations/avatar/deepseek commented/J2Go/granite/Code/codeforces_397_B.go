

package main

import (
	"bufio"
	"fmt"
	"os"
)

// Constants
const MOD = 1000000007

// Global variables
var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	// Read the number of test cases.
	t, _ := fmt.Fscanf(in, "%d\n", &t)
	// Process each test case.
	for t > 0 {
		// Read the values of n, a, and b.
		var n, a, b int
		fmt.Fscanf(in, "%d %d %d\n", &n, &a, &b)
		// Check if n is less than a.
		if n < a {
			fmt.Fprintln(out, "No")
			continue
		}
		// Check if a is equal to b.
		if a == b {
			if n%a == 0 {
				fmt.Fprintln(out, "Yes")
			} else {
				fmt.Fprintln(out, "No")
			}
			continue
		}
		// Calculate x as b / (b - a).
		x := b / (b - a)
		// Check if n is greater than x * a.
		if n > x*a {
			fmt.Fprintln(out, "Yes")
			continue
		}
		// Perform binary search to find the minimum ans.
		low, high := int64(1), int64(x+1)
		var ans int64
		for low <= high {
			mid := (low + high) / 2
			if mid*a < int64(n) {
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
	// Flush the output.
	out.Flush()
}

