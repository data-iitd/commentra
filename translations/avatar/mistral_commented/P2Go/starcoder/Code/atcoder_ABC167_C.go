package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read dimensions and threshold from user
	n, m, x, _ := readInput(reader)

	// Initialize 2D array 'c' with dimensions (n, m)
	c := make([][]int, n)
	for i := range c {
		c[i] = make([]int, m)
	}

	// Read input into 2D array 'c'
	readInputInto2DArray(reader, c)

	// Initialize empty lists 'l' for storing combinations and'rem' for storing indices
	l := make([][]int, m+1)
	rem := make([]int, 0)

	// Initialize variable 'ans' for storing minimum number of tests
	ans := 0

	// Loop through all possible combinations of 'pre' indices
	for i := 0; i <= len(pre); i++ {
		// Generate all combinations of 'pre' indices of size 'i'
		for j := range combinations(pre, i) {
			// Append the combination to list 'l'
			l[i] = append(l[i], j)
		}
	}

	// Loop through each iteration 'i' of test cases
	for i := 1; i <= m; i++ {
		// Initialize variable 'ca' to 0 for sum of tests in current combination
		ca := 0

		// Loop through each index 'j' in current combination
		for _, j := range l[i] {
			// Add the test result at index 'j' and test case 'i' to 'ca'
			ca += c[j][i]
		}

		// If the sum of tests in current combination is less than threshold 'x',
		// add the index of the current combination to'rem' list
		if ca < x {
			rem = append(rem, i)
		}
		// If the sum of tests in current combination is greater than or equal to threshold 'x',
		// continue to next combination
		else {
			continue
		}

		// If'rem' list is not empty, remove the combinations with indices in'rem' from 'l' list
		if len(rem) > 0 {
			for _, j := range rem {
				l[i] = append(l[i][:j], l[i][j+1:]...)
			}
			rem = make([]int, 0)
		}

		// If 'l' list is empty, print -1 and break the loop
		if len(l[i]) == 0 {
			fmt.Println(-1)
			break
		}
	}

	// If the loop completes without finding a valid combination,
	// calculate the minimum number of tests in all valid combinations
	else {
		// Initialize variable 'ca' to 0 for sum of tests in current combination
		ca := 0

		// Loop through each valid combination and calculate the sum of tests
		for _, i := range l[m] {
			ca = 0
			for j := 0; j < m; j++ {
				ca += c[i][j]
			}

			// Update 'ans' with minimum number of tests among all valid combinations
			if ans == 0 {
				ans = ca
			} else {
				ans = min(ans, ca)
		}

		// Print the minimum number of tests required
		fmt.Println(ans)
	}
}

// readInput reads input from stdin
func readInput(reader *bufio.Reader) (n, m, x int, pre []int) {
	// Read dimensions and threshold from user
	line, _ := reader.ReadString('\n')
	line = strings.TrimSuffix(line, "\n")
	n, m, x = parseInput(line)

	// Read indices of pre-selected tests from user
	line, _ = reader.ReadString('\n')
	line = strings.TrimSuffix(line, "\n")
	pre = parseInput(line)

	return n, m, x, pre
}

// readInputInto2DArray reads input into 2D array 'c'
func readInputInto2DArray(reader *bufio.Reader, c [][]int) {
	// Read input into 2D array 'c'
	for i := range c {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSuffix(line, "\n")
		c[i] = parseInput(line)
	}
}

// parseInput parses input into integers
func parseInput(line string) []int {
	// Split input by space
	line = strings.Split(line, " ")

	// Convert each element to integer
	line = convertToInt(line)

	return line
}

// convertToInt converts each element to integer
func convertToInt(line []string) []int {
	for i := range line {
		line[i], _ = strconv.Atoi(line[i])
	}

	return line
}

// combinations returns all combinations of 'pre' indices of size 'i'
func combinations(pre []int, i int) [][]int {
	var comb [][]int

	// Loop through all combinations of 'pre' indices of size 'i'
	for j := range pre {
		for k := range combinations(pre[j+1:], i-1) {
			comb = append(comb, append([]int{pre[j]}, k...))
		}
	}

	// If 'i' is 0, return the list 'pre'
	if i == 0 {
		comb = append(comb, pre)
	}

	return comb
}

// min returns the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}

	return b
}

