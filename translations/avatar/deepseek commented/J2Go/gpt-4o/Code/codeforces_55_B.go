package main

import (
	"fmt"
	"math"
)

var min int64 // Declaring a variable to keep track of the minimum result

func main() {
	min = math.MaxInt64 // Initializing min to the maximum possible int64 value
	var arr []int64     // Creating a slice to store the numbers

	// Reading four numbers and adding them to the slice
	for i := 0; i < 4; i++ {
		var num int64
		fmt.Scan(&num)
		arr = append(arr, num)
	}

	// Reading three operations and storing them in a slice
	var ops [3]string
	for i := 0; i < 3; i++ {
		fmt.Scan(&ops[i])
	}

	// Calling the recursive function to find the minimum result
	util(arr, ops, 0)

	// Outputting the minimum result
	fmt.Println(min)
}

// Recursive function to find the minimum result by applying operations
func util(arr []int64, ops [3]string, idx int) {
	if idx == 3 { // Base case: when all operations are applied
		if arr[0] < min { // Update min with the current result
			min = arr[0]
		}
		return
	}

	// Iterating through the slice to apply operations between two numbers
	for i := 0; i < len(arr); i++ {
		for j := i + 1; j < len(arr); j++ {
			a := make([]int64, 0) // Temporary slice to store remaining numbers
			for k := 0; k < len(arr); k++ {
				if k != j && k != i {
					a = append(a, arr[k]) // Adding remaining numbers to the temporary slice
				}
			}

			var res int64 // Variable to store the result of the operation
			if ops[idx] == "+" {
				res = arr[i] + arr[j] // Applying addition
			} else {
				res = arr[i] * arr[j] // Applying multiplication
			}

			a = append(a, res) // Adding the result to the temporary slice
			util(a, ops, idx+1) // Recursively calling util with the updated slice and index
		}
	}
}

// <END-OF-CODE>
