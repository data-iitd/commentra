package main // Defining the main package

import (
	"fmt" // Importing the fmt package for formatted I/O
	"math" // Importing the math package for mathematical constants and functions
)

var min int64 // Initializing the minimum value to math.MaxInt64

func main() { // Starting the main function
	var arr []int64 // Creating a slice of int64 to store the input numbers
	min = math.MaxInt64 // Setting the initial value of min to math.MaxInt64

	// Reading 4 numbers from the standard input and storing them in the slice
	for i := 0; i < 4; i++ {
		var num int64
		fmt.Scan(&num) // Scanning the input number
		arr = append(arr, num) // Appending the number to the slice
	}

	ops := make([]string, 3) // Creating a slice of string to store the operators

	// Reading 3 operators from the standard input and storing them in the slice
	for i := 0; i < 3; i++ {
		fmt.Scan(&ops[i]) // Scanning the input operator
	}

	util(arr, ops, 0) // Calling the util function with the slice, the slice of operators, and the index of the first operator

	fmt.Println(min) // Printing the minimum value found during the execution
}

func util(arr []int64, ops []string, idx int) { // Starting the util function
	if idx == 3 { // Checking if the index of the operator is equal to 3 (the last operator)
		if arr[0] < min { // Updating the minimum value with the first number in the slice
			min = arr[0]
		}
		return // Exiting the function
	}

	for i := 0; i < len(arr); i++ { // Iterating through the slice to find two numbers for the current operator
		for j := i + 1; j < len(arr); j++ {
			a := make([]int64, 0) // Creating a new slice to store the result of the current operation

			for k := 0; k < len(arr); k++ { // Iterating through the slice to exclude the current and previous numbers
				if k != j && k != i {
					a = append(a, arr[k]) // Adding the excluded number to the new slice
				}
			}

			var res int64 // Initializing the result variable

			if ops[idx] == "+" { // Checking if the current operator is '+'
				res = arr[i] + arr[j] // Performing the addition operation
			} else { // Else, the current operator is '*'
				res = arr[i] * arr[j] // Performing the multiplication operation
			}

			a = append(a, res) // Adding the result to the new slice
			util(a, ops, idx+1) // Recursively calling the util function with the new slice, the slice of operators, and the index of the next operator
		}
	}
}

// <END-OF-CODE>
