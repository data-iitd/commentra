package main

import (
	"fmt"
	"math"
)

// Variable to store the minimum result found
var min int64 = math.MaxInt64

func main() {
	// Create a Scanner object for user input
	var sc = bufio.NewScanner(os.Stdin)
	
	// Initialize min to the maximum possible value
	min = math.MaxInt64
	
	// Create a slice to store the input numbers
	var arr []int64
	
	// Read 4 long integers from user input and add them to the slice
	for i := 0; i < 4; i++ {
		sc.Scan()
		num := sc.Int64()
		arr = append(arr, num)
	}
	
	// Create a slice to store the operations
	var ops []string
	
	// Read 3 operations from user input
	for i := 0; i < 3; i++ {
		sc.Scan()
		op := sc.Text()
		ops = append(ops, op)
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
	
	// Iterate through all pairs of numbers in the slice
	for i := 0; i < len(arr); i++ {
		for j := i + 1; j < len(arr); j++ {
			// Create a new slice to hold the remaining numbers after the operation
			var a []int64
			
			// Add the remaining numbers to the new slice
			for k := 0; k < len(arr); k++ {
				if k != j && k != i {
					a = append(a, arr[k])
				}
			}
			
			var res int64
			// Perform the operation based on the current operation in the ops slice
			if idx < 3 && ops[idx] == "+" {
				res = arr[i] + arr[j] // Addition operation
			} else {
				res = arr[i] * arr[j] // Multiplication operation
			}
			
			// Add the result of the operation to the new slice
			a = append(a, res)
			
			// Recursively call util with the new slice and the next operation index
			util(a, ops, idx + 1)
		}
	}
}
