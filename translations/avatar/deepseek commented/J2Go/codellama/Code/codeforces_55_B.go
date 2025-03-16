package main

import (
	"fmt"
	"math"
)

var min int64 = math.MaxInt64 // Declaring a static variable to keep track of the minimum result

func main() {
	sc := make([]int64, 4) // Creating an array to store the numbers
	for i := 0; i < 4; i++ {
		fmt.Scan(&sc[i])
	}

	ops := make([]string, 3) // Creating an array to store the operations
	for i := 0; i < 3; i++ {
		fmt.Scan(&ops[i])
	}

	util(sc, ops, 0) // Calling the recursive function to find the minimum result

	fmt.Println(min) // Outputting the minimum result
}

// Recursive function to find the minimum result by applying operations
func util(sc []int64, ops []string, idx int) {
	if idx == 3 { // Base case: when all operations are applied
		min = int64(math.Min(float64(min), float64(sc[0]))) // Update min with the current result
		return
	}

	// Iterating through the array to apply operations between two numbers
	for i := 0; i < len(sc); i++ {
		for j := i + 1; j < len(sc); j++ {
			a := make([]int64, len(sc)-2) // Temporary array to store remaining numbers
			k := 0
			for l := 0; l < len(sc); l++ {
				if l != j && l != i {
					a[k] = sc[l] // Adding remaining numbers to the temporary array
					k++
				}
			}

			var res int64 // Variable to store the result of the operation
			if idx < 3 && ops[idx] == "+" {
				res = sc[i] + sc[j] // Applying addition
			} else {
				res = sc[i] * sc[j] // Applying multiplication
			}

			a = append(a, res) // Adding the result to the temporary array
			util(a, ops, idx+1) // Recursively calling util with the updated array and index
		}
	}
}

