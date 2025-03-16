package main

import (
	"fmt"
)

func main() {
	var t int
	fmt.Scan(&t) // Read the number of test cases

	for t > 0 {
		t--

		var n, a, b int64
		fmt.Scan(&n, &a, &b) // Read input values for each test case

		// Check if n is less than a, if so, output "No"
		if n < a {
			fmt.Println("No")
			continue
		}

		// If a equals b, check if n is a multiple of a
		if a == b {
			if n%a == 0 {
				fmt.Println("Yes")
			} else {
				fmt.Println("No")
			}
			continue
		}

		// Calculate the maximum number of a's that can fit into b
		x := b / (b - a)

		// If n is greater than x * a, output "Yes"
		if n > x*a {
			fmt.Println("Yes")
			continue
		}

		// Binary search to find the largest mid such that mid * a < n
		low, high := int64(1), x+1
		var ans int64 = 1

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
			fmt.Println("No")
		} else {
			fmt.Println("Yes")
		}
	}
}

// <END-OF-CODE>
