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

	// Read the number of elements
	n, _ := strconv.Atoi(readLine(reader))

	// Read the list of integers
	line, _ := reader.ReadString('\n')
	fields := strings.Fields(line)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		l[i], _ = strconv.Atoi(fields[i])
	}

	// Sort the list to facilitate counting unique elements
	sort.Ints(l)

	// Initialize a variable to track unique counts
	f := 1

	// Initialize a counter for unique elements
	c := 0

	// Iterate through the sorted list to count unique elements
	for _, i := range l {
		if i > c {
			c += 1
		}
	}

	// Output the total count of unique elements
	fmt.Println(c + 1)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	line = strings.TrimRight(line, "\n")
	return line
}
