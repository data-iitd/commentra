
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read an integer
func readInt(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

// Function to read multiple integers
func readInts(s string) []int {
	ss := strings.Split(s, " ")
	is := make([]int, len(ss))
	for i := 0; i < len(ss); i++ {
		is[i] = readInt(ss[i])
	}
	return is
}

// Function to read a line
func readLine(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

// Function to read multiple lines
func readLines(reader *bufio.Reader) []string {
	var lines []string
	for {
		str, isPrefix, err := reader.ReadLine()
		if err!= nil {
			break
		}
		if isPrefix {
			lines = append(lines, string(str))
		} else {
			lines = append(lines, string(str))
			break
		}
	}
	return lines
}

// Function to print an integer
func printInt(i int) {
	fmt.Println(i)
}

// Function to print multiple integers
func printInts(is []int) {
	for i := 0; i < len(is); i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(is[i])
	}
	fmt.Println()
}

// Function to print a line
func printLine(s string) {
	fmt.Println(s)
}

// Function to print multiple lines
func printLines(ss []string) {
	for i := 0; i < len(ss); i++ {
		fmt.Println(ss[i])
	}
}

// Main function
func main() {
	// Reading input values: N, A, and B
	reader := bufio.NewReader(os.Stdin)
	N, A, B := readInts(readLine(reader))

	// Initializing the answer variable to 0
	ans := 0

	// Calculating the number of repetitions
	rep := N / (A + B)

	// Adding the number of blocks that can be fully covered by A and B in one repetition
	ans += rep * A

	// Calculating the remaining number of blocks
	res := N - rep * (A + B)

	// Adding the number of blocks that can be covered by A in the remaining blocks
	ans += min(res, A)

	// Printing the final answer
	printInt(ans)
}

// Function to return the minimum of two values
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

