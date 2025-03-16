
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the input as a sequence of space-separated integers
	scanner.Scan()
	A := make([]int, 4)
	for i, s := range strings.Fields(scanner.Text()) {
		n, _ := strconv.Atoi(s)
		A[i] = n
	}

	// Check if the second or third element of the list 'A' is less than or equal to the first element
	if A[1] <= A[2] || A[3] <= A[0] {
		// If the condition is true, print '0'
		fmt.Println(0)
	} else {
		// If the condition is false, sort the list 'A' in ascending order
		sort.Ints(A)

		// Print the difference between the third and second elements of the sorted list
		fmt.Println(A[2] - A[1])
	}
}
