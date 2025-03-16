package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of test cases 'n'
	n, _ := strconv.Atoi(readLine(reader))

	// Read the list 'l' of length 'n' containing 'n' integers
	l := readList(reader)

	// Sort the list 'l' in ascending order
	sort.Ints(l)

	// Initialize variable 'f' to 1
	f := 1

	// Initialize variable 'c' to 0
	c := 0

	// Iterate through the list 'l'
	for _, i := range l {
		// If the current element 'i' is greater than the previous count 'c', increment 'c' by 1
		if i > c {
			c += 1
		}
	}

	// Print the final result, which is the number of unique elements in the list 'l' plus 1
	fmt.Println(c + 1)
}

// Function to read a line from standard input
func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	line = strings.TrimRight(line, "\n")
	return line
}

// Function to read a list of integers from standard input
func readList(reader *bufio.Reader) []int {
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}
