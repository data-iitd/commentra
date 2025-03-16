
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read an integer input for the number of elements
	var n int
	fmt.Fscan(bufio.NewReader(os.Stdin), &n)

	// Read a line of input, split it into individual strings, convert them to integers, and store them in a slice
	l1 := make([]int, n)
	for i := 0; i < n; i++ {
		var s string
		fmt.Fscan(bufio.NewReader(os.Stdin), &s)
		l1[i], _ = strconv.Atoi(s)
	}

	// Sort the slice of integers in ascending order
	for i := 0; i < n; i++ {
		for j := 0; j < n-i-1; j++ {
			if l1[j] > l1[j+1] {
				l1[j], l1[j+1] = l1[j+1], l1[j]
			}
		}
	}

	// Assign the maximum value in the slice to variable 'a'
	a := l1[n-1]

	// Assign the minimum value in the slice to variable 'b'
	b := l1[0]

	// Check if the maximum and minimum values are the same
	if a == b {
		// If they are the same, the difference is zero and the number of pairs is n choose 2
		fmt.Println(a - b, n*(n-1)/2)
	} else {
		// Count occurrences of the maximum value 'a' in the slice
		var ac, bc int
		for i := 0; i < n; i++ {
			if l1[i] == a {
				ac++
			}
			if l1[i] == b {
				bc++
			}
		}

		// Calculate the difference between the maximum and minimum values, and the product of their counts
		fmt.Println(a-b, ac*bc)
	}
}
