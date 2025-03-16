
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading the number of balls (N) and the number of operations (M)
	N, M := readTwoNums(bufio.NewReader(os.Stdin))

	// Initializing the list of balls with pairs [white pieces, red pieces]
	balls := make([][]int, N)
	for i := 0; i < N; i++ {
		balls[i] = make([]int, 2)
	}

	// Special initialization for the first ball
	balls[0][0], balls[0][1] = 0, 1

	// Loop to process each operation
	for i := 0; i < M; i++ {
		x, y := readTwoNums(bufio.NewReader(os.Stdin))  // Reading the indices of the balls to be swapped
		w_x, r_x := balls[x-1][0], balls[x-1][1]  // Extracting the current state of ball x
		w_y, r_y := balls[y-1][0], balls[y-1][1]  // Extracting the current state of ball y

		// Swapping the balls if possible
		if w_x >= 1 && r_x >= 1 {
			balls[x-1][0] -= 1
			balls[y-1][1] += 1
		} else if w_x == 0 {
			balls[x-1][1] -= 1
			balls[y-1][1] += 1
		} else {
			balls[x-1][0] -= 1
			balls[y-1][0] += 1
		}
	}

	// Counting the number of balls with at least one red or white piece
	ans := 0
	for i := 0; i < N; i++ {
		if balls[i][1] > 0 {
			ans++
		}
	}

	// Printing the final count
	fmt.Println(ans)
}

// Function to read a single line of input from stdin
func readSingleLine(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

// Function to read a single integer from stdin
func readNum(reader *bufio.Reader) (a int) {
	a, _ = strconv.Atoi(readSingleLine(reader))
	return
}

// Function to read two integers from stdin
func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

// Function to read n integers from stdin
func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	a := readNNums(reader, n)
	for i := 0; i < n; i++ {
		res[i] = a[i]
	}
	return res
}

// Function to print a single line of output to stdout
func printSingleLine(a interface{}) {
	fmt.Println(a)
}

// Function to print a single integer to stdout
func printNum(a int) {
	printSingleLine(a)
}

// Function to print two integers to stdout
func printTwoNums(a int, b int) {
	printSingleLine(a, b)
}

// Function to print n integers to stdout
func printNNums(a...int) {
	printSingleLine(a...)
}

// Function to print a single line of output to stdout
func printlnSingleLine(a...interface{}) {
	fmt.Println(a...)
}

// Function to print a single integer to stdout
func printlnNum(a int) {
	printlnSingleLine(a)
}

// Function to print two integers to stdout
func printlnTwoNums(a int, b int) {
	printlnSingleLine(a, b)
}

// Function to print n integers to stdout
func printlnNNums(a...int) {
	printlnSingleLine(a...)
}

// Function to read a single line of input from stdin
func readSingleLine(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

// Function to read a single integer from stdin
func readNum(reader *bufio.Reader) (a int) {
	a, _ = strconv.Atoi(readSingleLine(reader))
	return
}

// Function to read two integers from stdin
func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

// Function to read n integers from stdin
func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	a := readNNums(reader, n)
	for i := 0; i < n; i++ {
		res[i] = a[i]
	}
	return res
}

// Function to print a single line of output to stdout
func printSingleLine(a interface{}) {
	fmt.Println(a)
}

// Function to print a single integer to stdout
func printNum(a int) {
	printSingleLine(a)
}

// Function to print two integers to stdout
func printTwoNums(a int, b int) {
	printSingleLine(a, b)
}

// Function to print n integers to stdout
func printNNums(a...int) {
	printSingleLine(a...)
}

// Function to print a single line of output to stdout
func printlnSingleLine(a...interface{}) {
	fmt.Println(a...)
}

// Function to print a single integer to stdout
func printlnNum(a int) {
	printlnSingleLine(a)
}

// Function to print two integers to stdout
func printlnTwoNums(a int, b int) {
	printlnSingleLine(a, b)
}

// Function to print n integers to stdout
func printlnNNums(a...int) {
	printlnSingleLine(a...)
}

