
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of rows (n) from user input
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Read n rows of integers into a 2D slice (matrix) m
	m := make([][]int, n)
	for i := 0; i < n; i++ {
		s := bufio.NewReader(os.Stdin).Scan()
		m[i] = make([]int, 2)
		m[i][0], _ = strconv.Atoi(strings.Split(s, " ")[0])
		m[i][1], _ = strconv.Atoi(strings.Split(s, " ")[1])
	}

	// Sort the matrix m in descending order based on the first element of each row
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if m[i][0] < m[j][0] {
				m[i], m[j] = m[j], m[i]
			}
		}
	}

	// Initialize a variable a with the first row of the sorted matrix
	a := m[0]

	// Iterate through the remaining rows of the sorted matrix
	for i := 1; i < n; i++ {
		// Check if the second element of the current row is greater than the second element of the previous row
		if m[i][1] > a[1] {
			// If true, print 'Happy Alex' and exit the loop
			fmt.Println("Happy Alex")
			return
		}
		// Update a to the current row for the next iteration
		a = m[i]
	}
	// If the loop completes without finding a greater second element, print 'Poor Alex'
	fmt.Println("Poor Alex")
}
