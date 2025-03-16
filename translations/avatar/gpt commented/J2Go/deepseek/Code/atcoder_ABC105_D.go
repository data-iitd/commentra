package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout

	// Create a scanner to read input data
	scanner := bufio.NewScanner(inputStream)

	// Create a writer to output results
	writer := bufio.NewWriter(outputStream)
	defer writer.Flush()

	// Create an instance of TaskD to solve the problem
	solver := TaskD{}

	// Solve the problem for the first test case
	solver.solve(scanner, writer)
}

type TaskD struct{}

func (td TaskD) solve(scanner *bufio.Scanner, writer io.Writer) {
	// Read the number of elements and the modulus value
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	// Read the array of integers
	scanner.Scan()
	a := parseIntArray(scanner.Text())

	// Initialize a map to store counts of remainders
	dp := make(map[int]int)
	var ans int64 = 0
	var base int = 0

	// Iterate through the array to calculate the answer
	for i := 0; i < n; i++ {
		// Update the base remainder
		base = (base - a[i]%m + m) % m

		// Merge the current remainder into the map
		dp[(base+a[i])%m]++

		// Add the count of occurrences of the current base remainder to the answer
		ans += int64(dp[base])
	}

	// Output the final answer
	fmt.Fprintln(writer, ans)
}

func parseIntArray(s string) []int {
	fields := strings.Fields(s)
	nums := make([]int, len(fields))
	for i, field := range fields {
		num, _ := strconv.Atoi(field)
		nums[i] = num
	}
	return nums
}
