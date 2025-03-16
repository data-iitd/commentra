package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input which represents the number of elements
	n, _ := strconv.Atoi(readLine())

	// Read a line of input, split it by spaces, and convert it to a list of integers
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.Split(readLine(), " ")[i])
	}

	// Initialize the current level and counters
	current_level := 0
	counter := 0
	counter_turns := -1 // Start with -1 to account for the first turn increment

	// Loop until all elements have been processed
	for counter < len(a) {
		counter_turns += 1 // Increment the turn counter

		// Iterate through the list to find elements that can be processed
		for i := 0; i < len(a); i++ {
			// Check if the current element is not marked (-1) and is less than or equal to the current counter
			if a[i]!= -1 && a[i] <= counter {
				counter += 1 // Increment the counter as we can process this element
				a[i] = -1    // Mark the element as processed by setting it to -1
		}

		// Reverse the list to prepare for the next round of processing
		a = reverse(a)
	}

	// Print the total number of turns taken to process all elements
	fmt.Println(counter_turns)
}

func reverse(a []int) []int {
	for i := 0; i < len(a)/2; i++ {
		a[i], a[len(a)-i-1] = a[len(a)-i-1], a[i]
	}
	return a
}

func readLine() string {
	r := bufio.NewReader(os.Stdin)
	input, _ := r.ReadString('\n')
	return strings.TrimSpace(input)
}

