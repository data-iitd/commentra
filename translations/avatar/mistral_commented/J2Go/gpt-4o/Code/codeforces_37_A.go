package main

import (
	"bufio" // Import bufio for buffered I/O
	"fmt"   // Import fmt for formatted I/O
	"os"    // Import os for standard input
	"strconv" // Import strconv for string conversion
)

func main() {
	scanner := bufio.NewScanner(os.Stdin) // Create a new scanner for reading input
	scanner.Scan() // Read the first line of input
	n, _ := strconv.Atoi(scanner.Text()) // Convert the first line to an integer

	// Initialize a map to count occurrences of each integer
	counts := make(map[int]int)

	// Iterate through the given number of integers and add each integer to the map with its count
	for i := 0; i < n; i++ {
		scanner.Scan() // Read the next line of input
		val, _ := strconv.Atoi(scanner.Text()) // Convert the line to an integer
		counts[val]++ // Increment the count for this integer
	}

	// Initialize a variable to track the maximum count
	max := 0
	for _, value := range counts {
		// Update the maximum count if the current value is greater
		if value > max {
			max = value
		}
	}

	// Print the maximum count and the size of the map
	fmt.Println(max, len(counts))
}

// <END-OF-CODE>
