package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	input := bufio.NewReader(os.Stdin) // Setting up input reader
	output := bufio.NewWriter(os.Stdout) // Setting up output writer
	defer output.Flush() // Ensure output is flushed at the end

	var n int
	fmt.Fscan(input, &n) // Reading the number of elements

	array := make([]int, 1001) // Initializing an array to count occurrences
	for i := 0; i < n; i++ { // Looping through each element
		var index int
		fmt.Fscan(input, &index) // Reading the current element
		array[index]++ // Incrementing the count of the current element
	}

	countMax := -1 // Initializing the maximum count to -1
	for i := 1; i < len(array); i++ { // Looping through the array to find the maximum count
		if countMax < array[i] {
			countMax = array[i] // Updating the maximum count if necessary
		}
	}

	if n%2 == 0 { // Checking if n is even
		if countMax <= n/2 { // Checking if the maximum count is less than or equal to half of n
			fmt.Fprintln(output, "YES") // Printing "YES" if the condition is met
		} else {
			fmt.Fprintln(output, "NO") // Printing "NO" if the condition is not met
		}
	} else { // If n is odd
		if countMax <= n/2+1 { // Checking if the maximum count is less than or equal to half of n rounded up
			fmt.Fprintln(output, "YES") // Printing "YES" if the condition is met
		} else {
			fmt.Fprintln(output, "NO") // Printing "NO" if the condition is not met
		}
	}
}

// <END-OF-CODE>
