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
	// Initialize input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := bufio.NewReader(inputStream)
	out := bufio.NewWriter(outputStream)

	// Create an instance of TaskD and solve the problem
	solver := TaskD{}
	solver.solve(1, in, out)

	// Close the output stream
	out.Flush()
}

// TaskD class containing the solve method
type TaskD struct{}

func (solver *TaskD) solve(testNumber int, in *bufio.Reader, out *bufio.Writer) {
	// Read the number of elements and the modulo value
	n, m := readIntArray(in)

	// Read the array of elements
	a := readIntArray(in)

	// HashMap to store the frequency of remainders
	dp := make(map[int]int)

	// Initialize the answer and base variable
	ans := 0
	base := 0

	// Iterate through the array to calculate the answer
	for i := 0; i < n; i++ {
		// Update the base variable
		base = (base - a[i]%m + m) % m

		// Update the frequency of remainders in the HashMap
		dp[base+a[i]]++

		// Add the frequency of the current remainder to the answer
		ans += dp[base]
	}

	// Print the final answer
	fmt.Fprintln(out, ans)
}

// Read the next string from the input
func readString(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscan(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readInt(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscan(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Read the next array of integers from the input
func readIntArray(in *bufio.Reader) []int {
	var n int
	_, err := fmt.Fscan(in, &n)
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readInt(in)
	}
	return a
}

// Read the next string from the input
func readLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readIntLine(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Read the next array of integers from the input
func readIntArrayLine(in *bufio.Reader) []int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readIntLine(in)
	}
	return a
}

// Read the next string from the input
func readStringLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readIntLine(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Read the next array of integers from the input
func readIntArrayLine(in *bufio.Reader) []int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readIntLine(in)
	}
	return a
}

// Read the next string from the input
func readStringLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readIntLine(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Read the next array of integers from the input
func readIntArrayLine(in *bufio.Reader) []int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readIntLine(in)
	}
	return a
}

// Read the next string from the input
func readStringLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readIntLine(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Read the next array of integers from the input
func readIntArrayLine(in *bufio.Reader) []int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readIntLine(in)
	}
	return a
}

// Read the next string from the input
func readStringLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readIntLine(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Read the next array of integers from the input
func readIntArrayLine(in *bufio.Reader) []int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readIntLine(in)
	}
	return a
}

// Read the next string from the input
func readStringLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readIntLine(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Read the next array of integers from the input
func readIntArrayLine(in *bufio.Reader) []int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readIntLine(in)
	}
	return a
}

// Read the next string from the input
func readStringLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readIntLine(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Read the next array of integers from the input
func readIntArrayLine(in *bufio.Reader) []int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readIntLine(in)
	}
	return a
}

// Read the next string from the input
func readStringLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readIntLine(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Read the next array of integers from the input
func readIntArrayLine(in *bufio.Reader) []int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readIntLine(in)
	}
	return a
}

// Read the next string from the input
func readStringLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readIntLine(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Read the next array of integers from the input
func readIntArrayLine(in *bufio.Reader) []int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readIntLine(in)
	}
	return a
}

// Read the next string from the input
func readStringLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readIntLine(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Read the next array of integers from the input
func readIntArrayLine(in *bufio.Reader) []int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readIntLine(in)
	}
	return a
}

// Read the next string from the input
func readStringLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readIntLine(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Read the next array of integers from the input
func readIntArrayLine(in *bufio.Reader) []int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readIntLine(in)
	}
	return a
}

// Read the next string from the input
func readStringLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readIntLine(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Read the next array of integers from the input
func readIntArrayLine(in *bufio.Reader) []int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readIntLine(in)
	}
	return a
}

// Read the next string from the input
func readStringLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readIntLine(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Read the next array of integers from the input
func readIntArrayLine(in *bufio.Reader) []int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readIntLine(in)
	}
	return a
}

// Read the next string from the input
func readStringLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Read the next integer from the input
func readIntLine(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Re