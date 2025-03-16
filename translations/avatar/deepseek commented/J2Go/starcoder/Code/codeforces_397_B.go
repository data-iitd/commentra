
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables to store the input and output file handles.
var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

// Constants to store the values of N, MOD and MAX_N.
const (
	N        = 1000000000
	MOD      = 1000000007
	MAX_N    = 1000000000
	MAX_ITER = 1000000000
)

// Function to read a single line of input from stdin.
func readLine() string {
	bytes, _, _ := in.ReadLine()
	return string(bytes)
}

// Function to read a single integer from stdin.
func readInt() int {
	i, err := strconv.Atoi(readLine())
	check(err)
	return i
}

// Function to read a single 64-bit integer from stdin.
func readInt64() int64 {
	i, err := strconv.ParseInt(readLine(), 10, 64)
	check(err)
	return i
}

// Function to read a single float-point number from stdin.
func readFloat() float64 {
	f, err := strconv.ParseFloat(readLine(), 64)
	check(err)
	return f
}

// Function to read a line of input as a slice of integers.
func readSlice() []int {
	line := readLine()
	var slice []int
	for _, item := range strings.Split(line, " ") {
		slice = append(slice, int(item))
	}
	return slice
}

// Function to read a line of input as a slice of 64-bit integers.
func readSlice64() []int64 {
	line := readLine()
	var slice []int64
	for _, item := range strings.Split(line, " ") {
		slice = append(slice, int64(item))
	}
	return slice
}

// Function to read a line of input as a slice of floats.
func readFloatSlice() []float64 {
	line := readLine()
	var slice []float64
	for _, item := range strings.Split(line, " ") {
		slice = append(slice, float64(item))
	}
	return slice
}

// Function to read a line of input as a slice of strings.
func readStringSlice() []string {
	line := readLine()
	return strings.Split(line, " ")
}

// Function to read a single integer from stdin.
func readInt() int {
	i, err := strconv.Atoi(readLine())
	check(err)
	return i
}

// Function to read a single 64-bit integer from stdin.
func readInt64() int64 {
	i, err := strconv.ParseInt(readLine(), 10, 64)
	check(err)
	return i
}

// Function to read a single float-point number from stdin.
func readFloat() float64 {
	f, err := strconv.ParseFloat(readLine(), 64)
	check(err)
	return f
}

// Function to read a line of input as a slice of integers.
func readSlice() []int {
	line := readLine()
	var slice []int
	for _, item := range strings.Split(line, " ") {
		slice = append(slice, int(item))
	}
	return slice
}

// Function to read a line of input as a slice of 64-bit integers.
func readSlice64() []int64 {
	line := readLine()
	var slice []int64
	for _, item := range strings.Split(line, " ") {
		slice = append(slice, int64(item))
	}
	return slice
}

// Function to read a line of input as a slice of floats.
func readFloatSlice() []float64 {
	line := readLine()
	var slice []float64
	for _, item := range strings.Split(line, " ") {
		slice = append(slice, float64(item))
	}
	return slice
}

// Function to read a line of input as a slice of strings.
func readStringSlice() []string {
	line := readLine()
	return strings.Split(line, " ")
}

// Function to print the output to stdout.
func printf(str string, args...interface{}) {
	fmt.Fprintf(out, str+"\n", args...)
}

// Function to print the output to stdout.
func printSlice(slice []int) {
	for _, item := range slice {
		printf("%d", item)
	}
	printf("\n")
}

// Function to print the output to stdout.
func printSlice64(slice []int64) {
	for _, item := range slice {
		printf("%d", item)
	}
	printf("\n")
}

// Function to print the output to stdout.
func printFloatSlice(slice []float64) {
	for _, item := range slice {
		printf("%.6f", item)
	}
	printf("\n")
}

// Function to print the output to stdout.
func printStringSlice(slice []string) {
	for _, item := range slice {
		printf("%s", item)
	}
	printf("\n")
}

// Function to check for errors.
func check(err error) {
	if err!= nil {
		panic(err)
	}
}

// Function to read a single line of input from stdin.
func readLine() string {
	bytes, _, _ := in.ReadLine()
	return string(bytes)
}

// Function to read a single integer from stdin.
func readInt() int {
	i, err := strconv.Atoi(readLine())
	check(err)
	return i
}

// Function to read a single 64-bit integer from stdin.
func readInt64() int64 {
	i, err := strconv.ParseInt(readLine(), 10, 64)
	check(err)
	return i
}

// Function to read a single float-point number from stdin.
func readFloat() float64 {
	f, err := strconv.ParseFloat(readLine(), 64)
	check(err)
	return f
}

// Function to read a line of input as a slice of integers.
func readSlice() []int {
	line := readLine()
	var slice []int
	for _, item := range strings.Split(line, " ") {
		slice = append(slice, int(item))
	}
	return slice
}

// Function to read a line of input as a slice of 64-bit integers.
func readSlice64() []int64 {
	line := readLine()
	var slice []int64
	for _, item := range strings.Split(line, " ") {
		slice = append(slice, int64(item))
	}
	return slice
}

// Function to read a line of input as a slice of floats.
func readFloatSlice() []float64 {
	line := readLine()
	var slice []float64
	for _, item := range strings.Split(line, " ") {
		slice = append(slice, float64(item))
	}
	return slice
}

// Function to read a line of input as a slice of strings.
func readStringSlice() []string {
	line := readLine()
	return strings.Split(line, " ")
}

// Function to print the output to stdout.
func printf(str string, args...interface{}) {
	fmt.Fprintf(out, str+"\n", args...)
}

// Function to print the output to stdout.
func printSlice(slice []int) {
	for _, item := range slice {
		printf("%d", item)
	}
	printf("\n")
}

// Function to print the output to stdout.
func printSlice64(slice []int64) {
	for _, item := range slice {
		printf("%d", item)
	}
	printf("\n")
}

// Function to print the output to stdout.
func printFloatSlice(slice []float64) {
	for _, item := range slice {
		printf("%.6f", item)
	}
	printf("\n")
}

// Function to print the output to stdout.
func printStringSlice(slice []string) {
	for _, item := range slice {
		printf("%s", item)
	}
	printf("\n")
}

// Function to check for errors.
func check(err error) {
	if err!= nil {
		panic(err)
	}
}

// Function to check if n is less than a.
func isLess(n, a int) bool {
	return n < a
}

// Function to check if a is equal to b.
func isEqual(a, b int) bool {
	return a == b
}

// Function to check if n is greater than x * a.
func isGreater(n, x, a int) bool {
	return n > x*a
}

// Function to perform binary search to find the minimum ans.
func binarySearch(low, high, n, a int) int {
	ans := 1
	for low <= high {
		mid := (low + high) / 2
		if mid*a < n {
			low = mid + 1
		} else {
			ans = mid
			high = mid - 1
		}
	}
	return ans
}

// Function to check if n lies between (ans - 1) * b and ans * a.
func isBetween(n, ans, b, a int) bool {
	return n > (ans-1)*b && n < ans*a
}

// Main function to read input from stdin and write output to stdout.
func main() {
	// Read the number of test cases.
	t := readInt()
	// Process each test case.
	for t > 0 {
		// Read the values of n, a, and b.
		n := readInt()
		a := readInt()
		b := readInt()
		// Check if n is less than a.
		if isLess(n, a) {
			printf("No")
			t--
			continue
		}
		// Check if a is equal to b.
		if isEqual(a, b) {
			if n%a == 0 {
				printf("Yes")
			} else {
				printf("No")
			}
			t--
			continue
		}
		// Calculate x as b / (b - a).
		x := b / (b - a)
		// Check if n is greater than x * a.
		if isGreater(n, x, a) {
			printf("Yes")
			t--
			continue
		}
		// Perform binary search to find the minimum ans.
		ans := binarySearch(1, x+1, n, a)
		// Check if n lies between (ans - 1) * b and ans * a.
		if isBetween(n, ans, b, a) {
			printf("No")
		} else {
			printf("Yes")
		}
		t--
	}
}

// 