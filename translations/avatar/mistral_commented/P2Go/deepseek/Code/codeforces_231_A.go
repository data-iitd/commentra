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

	// Read the integer 'n' from the user
	n, _ := strconv.Atoi(readLine(reader))

	// Initialize a counter 'c' to 0
	c := 0

	// Iterate through the range of 'n'
	for i := 0; i < n; i++ {
		// Read 'n' lists of integers as input from the user
		line := readLine(reader)
		nums := strings.Fields(line)
		sum := 0
		for _, numStr := range nums {
			num, _ := strconv.Atoi(numStr)
			sum += num
		}

		// Check if the sum of the elements in the current list is greater than 1
		if sum > 1 {
			// Increment the counter 'c' by 1 if the condition is true
			c += 1
		}
	}

	// Print the value of the counter 'c'
	fmt.Println(c)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimRight(line, "\n")
}

