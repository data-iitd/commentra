
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read two integers n and d from input
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	d, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Initialize an empty list to store the elements
	x := make([]int, n)
	// Initialize variables to keep track of the total adjustments (m) and the current adjustment count (q)
	m := 0
	q := 0

	// Read the elements of the list from input and split them into individual strings
	xStr := readLine(reader)
	xStrs := strings.Split(xStr, " ")

	// Convert the list of strings into a list of integers
	for i := 0; i < n; i++ {
		x[i], _ = strconv.Atoi(xStrs[i])
	}

	// Iterate through the list to compare adjacent elements
	for a := 0; a < n-1; a++ {
		// Check if the current element is greater than or equal to the next element
		if x[a] >= x[a+1] {
			// Calculate how many increments of d are needed to make x[a + 1] greater than x[a]
			q = int((x[a] - x[a+1]) / d + 1)
			// Update the total adjustments made
			m = m + q
			// Adjust the next element by adding the necessary increments of d
			x[a+1] = x[a+1] + q * d
		}
	}

	// Print the total number of adjustments made
	fmt.Println(m)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	return ""
}

