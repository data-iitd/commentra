package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Function to read input from stdin
func readInput(reader *bufio.Reader) string {
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}

// Function to read input from stdin
func readInt(reader *bufio.Reader) int {
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	return strconv.Atoi(input)
}

// Function to read input from stdin
func readInts(reader *bufio.Reader, n int) []int {
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		ints[i] = readInt(reader)
	}
	return ints
}

// Function to read input from stdin
func readStringArray(reader *bufio.Reader) []string {
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	return strings.Split(input, " ")
}

// Function to read input from stdin
func readStringMatrix(reader *bufio.Reader, n int) [][]string {
	matrix := make([][]string, n)
	for i := 0; i < n; i++ {
		matrix[i] = readStringArray(reader)
	}
	return matrix
}

// Function to print output to stdout
func printOutput(writer *bufio.Writer, output string) {
	fmt.Fprintln(writer, output)
}

// Function to print output to stdout
func printInts(writer *bufio.Writer, output []int) {
	for _, v := range output {
		fmt.Fprint(writer, v, " ")
	}
	fmt.Fprintln(writer)
}

// Function to print output to stdout
func printStringMatrix(writer *bufio.Writer, output [][]string) {
	for _, v := range output {
		printStrings(writer, v)
	}
	fmt.Fprintln(writer)
}

// Function to print output to stdout
func printStrings(writer *bufio.Writer, output []string) {
	for _, v := range output {
		fmt.Fprint(writer, v, " ")
	}
	fmt.Fprintln(writer)
}

// Function to sort an array in parallel
func parallelSort(a []int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

// Function to calculate the answer
func calculateAnswer(a []int, k int) int {
	parallelSort(a)
	ans := 0
	for i := 0; i < k; i++ {
		ans += a[i]
	}
	return ans
}

// Function to solve the problem
func solve(reader *bufio.Reader, writer *bufio.Writer) {
	// Read input: number of elements n and the number of summands k
	n := readInt(reader)
	k := readInt(reader)

	// Read input array a of size n
	a := readInts(reader, n)

	// Calculate the answer: sum of first k elements of sorted array a
	ans := calculateAnswer(a, k)

	// Write the answer to the output stream
	printOutput(writer, ans)
}

// Main function
func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read output from stdout
	writer := bufio.NewWriter(os.Stdout)

	// Solve the problem
	solve(reader, writer)

	// Close the output stream
	writer.Flush()
}

