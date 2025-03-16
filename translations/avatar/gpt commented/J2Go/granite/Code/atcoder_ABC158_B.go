
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	scan := bufio.NewScanner(os.Stdin)

	// Read three long integers from input: N, A, and B
	var N, A, B int64
	fmt.Fscan(scan, &N)
	fmt.Fscan(scan, &A)
	fmt.Fscan(scan, &B)

	// Initialize a variable k to count how many complete cycles of (A + B) can fit into N
	k := int64(0)

	// Check if the input values are within the specified constraints
	if 1 <= N && N <= int64(1e18) && 0 <= A && 0 <= B && 0 < A+B && A+B <= int64(1e18) {

		// Case 1: If the sum of A and B is less than or equal to N
		if A+B <= N {
			// Calculate how many complete cycles of (A + B) fit into N
			k = N / (A + B)

			// Check if the remaining part after k cycles is greater than A
			if N-k*(A+B) > A {
				// Print the total amount produced using k cycles and the remaining part
				fmt.Println(A*k + (N-k*(A+B))-(N-(k*(A+B)+A)))
			} else {
				// Print the total amount produced using k cycles and the remaining part
				fmt.Println(A*k + (N - k*(A+B)))
			}
		}
		// Case 2: If the sum of A and B is greater than N but A is less than or equal to N
		else if A+B > N && A <= N {
			// If A is less than or equal to N, print A
			fmt.Println(A)
		}
		// Case 3: If A + B is greater than N and A is greater than N
		else {
			// Print the total amount N, as no complete cycles can be formed
			fmt.Println(N)
		}
	}
}
