package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read an integer input which represents the number of lists to process
	n, _ := strconv.Atoi(readLine(reader))

	// Initialize a counter to keep track of lists with a sum greater than 1
	c := 0

	// Loop through the range of n to process each list
	for i := 0; i < n; i++ {
		// Read a line of input, split it into individual string elements, convert them to integers, and store them in a list
		line, _ := reader.ReadString('\n')
		elements := strings.Fields(line)
		l1 := make([]int, len(elements))
		for j, elem := range elements {
			num, _ := strconv.Atoi(elem)
			l1[j] = num
		}

		// Check if the sum of the current list is greater than 1
		if sum(l1) > 1 {
			// Increment the counter if the condition is met
			c = c + 1
		}
	}

	// Print the final count of lists that had a sum greater than 1
	fmt.Println(c)
}

// Helper function to read a line from the reader
func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	line = strings.TrimSuffix(line, "\n")
	return line
}

// Helper function to calculate the sum of a list of integers
func sum(l1 []int) int {
	total := 0
	for _, num := range l1 {
		total += num
	}
	return total
}
