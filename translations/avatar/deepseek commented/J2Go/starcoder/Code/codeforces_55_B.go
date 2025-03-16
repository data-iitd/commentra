package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a new Scanner object for input.
	sc := bufio.NewScanner(os.Stdin)
	min := int64(math.MaxInt64) // Initializing min to the maximum possible int64 value
	arr := make([]int64, 4)      // Creating an array to store the numbers
	ops := make([]string, 3)     // Creating an array to store the operations

	// Reading four numbers and adding them to the array
	for i := 0; i < 4; i++ {
		sc.Scan()
		arr[i], _ = strconv.ParseInt(sc.Text(), 10, 64)
	}

	// Reading three operations and storing them in the array
	sc.Scan()
	ops = strings.Split(sc.Text(), " ")

	// Calling the recursive function to find the minimum result
	util(arr, ops, 0, &min)

	// Outputting the minimum result
	fmt.Println(min)
}

// Recursive function to find the minimum result by applying operations
func util(arr []int64, ops []string, idx int, min *int64) {
	if idx == 3 { // Base case: when all operations are applied
		*min = int64(math.Min(*min, arr[0])) // Update min with the current result
		return
	}

	// Iterating through the array to apply operations between two numbers
	for i := 0; i < len(arr); i++ {
		for j := i + 1; j < len(arr); j++ {
			a := make([]int64, 0) // Temporary array to store remaining numbers
			for k := 0; k < len(arr); k++ {
				if k!= j && k!= i {
					a = append(a, arr[k]) // Adding remaining numbers to the temporary array
				}
			}

			res := int64(0) // Variable to store the result of the operation
			if idx < 3 && ops[idx] == "+" {
				res = arr[i] + arr[j] // Applying addition
			} else {
				res = arr[i] * arr[j] // Applying multiplication
			}

			a = append(a, res) // Adding the result to the temporary array
			util(a, ops, idx+1, min) // Recursively calling util with the updated array and index
		}
	}
}

