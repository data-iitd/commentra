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
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of rows (n) from user input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Read n rows of integers into a 2D slice (matrix) m
	m := make([][]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		row := scanner.Text()
		elements := strings.Split(row, " ")
		m[i] = make([]int, len(elements))
		for j, x := range elements {
			m[i][j], _ = strconv.Atoi(x)
		}
	}

	// Sort the matrix m in descending order based on the first element of each row
	sort.Slice(m, func(i, j int) bool {
		return m[i][0] > m[j][0]
	})

	// Initialize a variable a with the first row of the sorted matrix
	a := m[0]

	// Iterate through the remaining rows of the sorted matrix
	for _, i := range m[1:] {
		// Check if the second element of the current row is greater than the second element of the previous row
		if i[1] > a[1] {
			// If true, print 'Happy Alex' and exit the loop
			fmt.Println("Happy Alex")
			return
		}
		// Update a to the current row for the next iteration
		a = i
	}

	// If the loop completes without finding a greater second element, print 'Poor Alex'
	fmt.Println("Poor Alex")
}

