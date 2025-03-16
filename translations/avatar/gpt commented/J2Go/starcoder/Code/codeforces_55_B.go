package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Variable to store the minimum result found
var min int64 = int64(math.MaxInt64)

func main() {
	// Create a new Scanner to read from stdin
	reader := bufio.NewReader(os.Stdin)

	// Initialize an array to store the input numbers
	arr := make([]int64, 4)

	// Read 4 long integers from user input and add them to the list
	for i := 0; i < 4; i++ {
		arr[i], _ = strconv.ParseInt(readLine(reader), 10, 64)
	}

	// Create an array to store the operations
	ops := make([]string, 3)

	// Read 3 operations from user input
	for i := 0; i < 3; i++ {
		ops[i] = readLine(reader)
	}

	// Call the utility function to compute the minimum result
	util(arr, ops, 0)

	// Print the minimum result found
	fmt.Println(min)
}

// Recursive utility function to perform operations and find the minimum result
func util(arr []int64, ops []string, idx int) {
	// Base case: if all operations have been used, update the minimum result
	if idx == 3 {
		min = int64(math.Min(float64(min), float64(arr[0])))
		return
	}

	// Iterate through all pairs of numbers in the list
	for i := 0; i < len(arr); i++ {
		for j := i + 1; j < len(arr); j++ {
			// Create a new list to hold the remaining numbers after the operation
			a := make([]int64, 0)

			// Add the remaining numbers to the new list
			for k := 0; k < len(arr); k++ {
				if k!= j && k!= i {
					a = append(a, arr[k])
				}
			}

			var res int64
			// Perform the operation based on the current operation in the ops array
			if idx < 3 && ops[idx] == "+" {
				res = arr[i] + arr[j] // Addition operation
			} else {
				res = arr[i] * arr[j] // Multiplication operation
			}

			// Add the result of the operation to the new list
			a = append(a, res)

			// Recursively call util with the new list and the next operation index
			util(a, ops, idx+1)
		}
	}
}

// readLine reads a string from stdin
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

