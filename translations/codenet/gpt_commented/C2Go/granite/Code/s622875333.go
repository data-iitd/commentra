
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Infinite loop to continuously accept input until a termination condition is met
	for {
		// Read the values of n and r from the user
		n, r := readTwoInt()

		// Check for the termination condition (both n and r are zero)
		if n == 0 && r == 0 {
			break
		}

		// Initialize array a with values from n down to 1
		a := make([]int, n)
		for i := 0; i < n; i++ {
			a[i] = n - i
		}

		// Process r operations as specified by the user
		for i := 0; i < r; i++ {
			// Copy current state of array a to array b
			b := make([]int, n)
			copy(b, a)

			// Read the values of p and c for the current operation
			p, c := readTwoInt()

			// Update the first c elements of array a based on the values from array b
			for j := 0; j < c; j++ {
				a[j] = b[p-1+j]
			}

			// Shift the remaining elements in array a
			for j := c; j < c+p-1; j++ {
				a[j] = b[j-c]
			}
		}

		// Output the first element of array a after all operations
		fmt.Println(a[0])
	}
}

func readTwoInt() (int, int) {
	// Read two integers from the user
	reader := bufio.NewReader(os.Stdin)
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr)
	rStr, _ := reader.ReadString('\n')
	r, _ := strconv.Atoi(rStr)
	return n, r
}

// 