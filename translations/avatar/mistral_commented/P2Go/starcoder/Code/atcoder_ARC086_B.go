
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read input from standard input
func readInput() string {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}

// Function to return an integer input
func readInt() int {
	input := readInput()
	i, _ := strconv.Atoi(input)
	return i
}

// Function to return a list of integers as input
func readInts() []int {
	input := readInput()
	return strings.Split(input, " ")
}

// Function to create a list of lists based on the given number of rows and columns
func make2DList(rows, cols int) [][]int {
	var result [][]int
	for i := 0; i < rows; i++ {
		result = append(result, make([]int, cols))
	}
	return result
}

// Function to print the given list of lists
func print2DList(list [][]int) {
	for _, row := range list {
		for _, col := range row {
			fmt.Printf("%d ", col)
		}
		fmt.Println()
	}
}

// Function to determine the sign of the given value
func mySign(x int) int {
	if x > 0 {
		return 1
	} else if x < 0 {
		return -1
	} else {
		return 0
	}
}

// Function to determine the maximum absolute value and its sign
func maxAbs(a []int) (int, int) {
	maxVal := 0
	maxSign := 0
	maxIndex := -1
	for i, a0 := range a {
		if abs(a0) > maxVal {
			maxVal = abs(a0)
			maxSign = mySign(a0)
			maxIndex = i
		}
	}
	return maxVal, maxSign, maxIndex
}

func main() {
	// Read the number of elements in the list
	N := readInt()
	// Read the list of integers
	a := readInts()
	// Determine the maximum absolute value and its sign
	maxVal, maxSign, maxIndex := maxAbs(a)
	// Determine the output based on the sign of the maximum value
	if maxSign == 0 {
		// If the maximum value is zero, print zero
		fmt.Println(0)
	} else if maxSign == 1 {
		// If the maximum value is positive, print the required output
		fmt.Println(2*N - 1)
		// Print the indices of the maximum value and the first element
		fmt.Printf("%d %d\n", maxIndex+1, 1)
		// Print the indices of the other elements in pairs
		for i := 1; i < N; i++ {
			fmt.Printf("%d %d\n", i+1, i+2)
		}
	} else {
		// If the maximum value is negative, print the required output
		fmt.Println(2*N - 1)
		// Print the indices of the maximum value and the first element
		fmt.Printf("%d %d\n", maxIndex+1, 1)
		// Print the indices of the other elements in reverse order
		for i := N - 1; i > 0; i-- {
			fmt.Printf("%d %d\n", i+1, i)
		}
	}
}

