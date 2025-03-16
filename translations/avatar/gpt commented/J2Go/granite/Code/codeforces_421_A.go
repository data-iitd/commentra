
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Declare variables for the number of elements and sizes of the two lists
	var n, a, b int

	// Read the values for n, a, and b from the input
	fmt.Fscanf(reader, "%d\n", &n)
	fmt.Fscanf(reader, "%d\n", &a)
	fmt.Fscanf(reader, "%d\n", &b)

	// Initialize two slices to store the elements of the two lists
	list1 := make([]int, a)
	list2 := make([]int, b)

	// Read 'a' integers into list1
	for i := 0; i < a; i++ {
		fmt.Fscanf(reader, "%d\n", &list1[i])
	}

	// Read 'b' integers into list2
	for i := 0; i < b; i++ {
		fmt.Fscanf(reader, "%d\n", &list2[i])
	}

	// Iterate from 0 to n-1 to check the presence of each index in list1
	for i := 0; i < n; i++ {
		// If the current index + 1 is in list1, print 1
		if contains(list1, i+1) {
			fmt.Print(1, " ")
		} else {
			// Otherwise, print 2
			fmt.Print(2, " ")
		}
	}
}

func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

// END-OF-CODE