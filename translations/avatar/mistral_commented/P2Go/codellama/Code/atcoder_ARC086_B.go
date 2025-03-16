
package main

import (
	"fmt"
	"math"
	"strconv"
)

// Function to read input from standard input
func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

// Define the modulus value
const mod = 1000000007

// Function to return an integer input
func I() int {
	s := input()
	i, _ := strconv.Atoi(s)
	return i
}

// Function to return a list of integers as input
func III() []int {
	s := input()
	return stringToIntList(s)
}

// Function to create a list of lists based on the given number of rows and columns
func Line(N int, num int) [][]int {
	if N <= 0 {
		return [][]int{{}}
	}
	if num == 1 {
		return stringToIntListList(input())
	}
	readAll := stringToIntListList(input())
	return listToMatrix(readAll, num)
}

// Function to convert a string to a list of integers
func stringToIntList(s string) []int {
	var list []int
	for _, c := range s {
		if c == ' ' {
			continue
		}
		i, _ := strconv.Atoi(string(c))
		list = append(list, i)
	}
	return list
}

// Function to convert a string to a list of lists of integers
func stringToIntListList(s string) [][]int {
	var list [][]int
	for _, c := range s {
		if c == '\n' {
			continue
		}
		list = append(list, stringToIntList(string(c)))
	}
	return list
}

// Function to convert a list of lists to a matrix
func listToMatrix(list [][]int, num int) [][]int {
	var matrix [][]int
	for i := 0; i < len(list); i += num {
		matrix = append(matrix, list[i:i+num])
	}
	return matrix
}

// Function to determine the sign of a number
func my_sign(a int) int {
	if a > 0 {
		return 1
	} else if a < 0 {
		return -1
	} else {
		return 0
	}
}

// Initialize variables
var N = I()
var a = III()
var max_val = 0
var max_sign = 0
var max_index = -1

// Iterate through the list 'a' to find the maximum absolute value and its sign
for i, a0 := range a {
	// Update the maximum value and its sign if the current value is greater
	if abs(a0) > max_val {
		max_val = abs(a0)
		max_sign = my_sign(a0)
		max_index = i
	}
}

// Determine the output based on the sign of the maximum value
if max_sign == 0 {
	// If the maximum value is zero, print zero
	fmt.Println(0)
} else if max_sign == 1 {
	// If the maximum value is positive, print the required output
	fmt.Println(2 * N - 1)
	// Print the indices of the maximum value and the first element
	fmt.Println(max_index + 1, 1)
	// Print the indices of the other elements in pairs
	for i := 1; i < N; i++ {
		fmt.Println(i + 1, i + 2)
	}
} else {
	// If the maximum value is negative, print the required output
	fmt.Println(2 * N - 1)
	// Print the indices of the maximum value and the first element
	fmt.Println(max_index + 1, 1)
	// Print the indices of the other elements in reverse order
	for i := N - 1; i > 0; i-- {
		fmt.Println(i + 1, i)
	}
}

