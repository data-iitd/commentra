
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Function to read a line of input and strip the newline character
func input() string {
	return strings.TrimSpace(string(os.ReadFile(os.DevNull)))
}

// Function to read an integer from input
func I() int {
	i, _ := strconv.Atoi(input())
	return i
}

// Function to read a list of integers from input
func II() []int {
	return []int{I(), I(), I()}
}

// Function to read a list of integers and return it as a list
func III() []int {
	return []int{I(), I(), I(), I()}
}

// Function to read a specific format of input based on the number of elements
func Line(N int, num int) [][]int {
	// If N is less than or equal to 0, return an empty list
	if N <= 0 {
		return [][]int{{}}
	}
	// If num is 1, read N integers and return them as a list
	if num == 1 {
		return [][]int{III()}
	}
	// Otherwise, read N tuples of integers and return them as a transposed list
	read_all := [][]int{II(), II(), II(), II()}
	return [][]int{read_all[0], read_all[1], read_all[2], read_all[3]}
}

// Function to determine the sign of a number
func my_sign(x int) int {
	if x > 0 {
		return 1
	} else if x < 0 {
		return -1
	} else {
		return 0
	}
}

// Read the number of elements
N := I()

// Read the list of integers
a := III()

// Initialize variables to track the maximum absolute value, its sign, and index
max_val := 0
max_sign := 0
max_index := -1

// Loop through the list to find the maximum absolute value and its properties
for i, a0 := range a {
	if abs(a0) > max_val {
		max_val = abs(a0)
		max_sign = my_sign(a0)
		max_index = i
	}
}

// Check the sign of the maximum value and print results accordingly
if max_sign == 0 {
	// If the maximum sign is zero, print 0
	fmt.Println(0)
} else if max_sign == 1 {
	// If the maximum sign is positive, print the number of operations and the operations
	fmt.Println(2 * N - 1)
	for i := 0; i < N; i++ {
		fmt.Println(max_index + 1, i + 1)
	}
	for i := 0; i < N-1; i++ {
		fmt.Println(i + 1, i + 2)
	}
} else {
	// If the maximum sign is negative, print the number of operations and the operations
	fmt.Println(2 * N - 1)
	for i := 0; i < N; i++ {
		fmt.Println(max_index + 1, i + 1)
	}
	for i := 1; i < N; i++ {
		fmt.Println(i + 1, i)
	}
}

// END-OF-CODE
