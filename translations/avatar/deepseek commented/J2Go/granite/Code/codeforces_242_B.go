
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a Scanner object to read input
	scanner := bufio.NewScanner(os.Stdin)
	n, _ := strconv.Atoi(scanner.Text()) // Reading the integer value of n

	// Initializing two slices to store the elements
	a := make([]int, n)
	b := make([]int, n)

	// Initializing variables to track the minimum and maximum values
	left := 1000000005
	right := 0

	// Looping through n elements to read and update the slices and variables
	for i := 0; i < n; i++ {
		scanner.Scan()
		line := scanner.Text()
		parts := strings.Split(line, " ")
		a[i], _ = strconv.Atoi(parts[0]) // Reading element into slice a
		b[i], _ = strconv.Atoi(parts[1]) // Reading element into slice b
		if a[i] < left {
			left = a[i] // Updating left with the minimum value
		}
		if b[i] > right {
			right = b[i] // Updating right with the maximum value
		}
	}

	// Looping through the slices to find the target element
	for i := 0; i < n; i++ {
		if a[i] == left && b[i] == right {
			fmt.Println(i + 1) // Printing the 1-based index of the target element
			return // Returning from the method after finding the target
		}
	}

	// If no such element is found, print -1
	fmt.Println(-1)
}

