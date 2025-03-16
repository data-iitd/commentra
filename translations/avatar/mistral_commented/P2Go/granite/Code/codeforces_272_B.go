
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// This function takes a sequence as input and returns the number of pairs with common FX
func nPairsWithCommonFX(sequence []int) int {
	// Initialize an empty dictionary to store FX values and their corresponding values
	storage := make(map[int][]int)

	// Initialize an empty list to store unique FX values
	FXs := []int{}

	// Iterate through each value in the sequence
	for _, value := range sequence {
		// Compute the FX value for the current value
		fx := f(value)

		// If the FX value is not already in the dictionary, add it along with the value
		if _, ok := storage[fx];!ok {
			storage[fx] = []int{value}
			FXs = append(FXs, fx)
		} else {
			// If the FX value is already in the dictionary, add the current value to the list of values for that FX
			storage[fx] = append(storage[fx], value)
		}
	}

	// Calculate the result using the formula given in the problem statement
	result := (sum(len(storage[fx]) * len(storage[fx]) for _, fx := range FXs) - sum(len(storage[fx]) for _, fx := range FXs)) / 2

	// Return the result
	return result
}

// This function takes an integer as input and returns its FX value
func f(n int) int {
	// Initialize a variable to store the FX value
	fx := 1

	// Perform bitwise operations until the number is reduced to 1
	for n!= 1 {
		// If the number is odd, increment the FX value
		if n%2!= 0 {
			fx++
		}

		// Divide the number by 2 to reduce it further
		n /= 2
	}

	// Return the final FX value
	return fx
}

// This is the main function that takes input and calls the helper function nPairsWithCommonFX
func main() {
	// Read input from standard input
	reader := bufio.NewReader(os.Stdin)
	input()

	// Call the helper function with the sequence obtained from input
	result := nPairsWithCommonFX(map[int]int(input().split()))

	// Print the result
	fmt.Println(result)
}

// This function takes a sequence as input and returns the number of pairs with common FX
func nPairsWithCommonFX(sequence map[int]int) int {
	// Initialize an empty dictionary to store FX values and their corresponding values
	storage := make(map[int][]int)

	// Initialize an empty list to store unique FX values
	FXs := []int{}

	// Iterate through each value in the sequence
	for value := range sequence {
		// Compute the FX value for the current value
		fx := f(value)

		// If the FX value is not already in the dictionary, add it along with the value
		if _, ok := storage[fx];!ok {
			storage[fx] = []int{value}
			FXs = append(FXs, fx)
		} else {
			// If the FX value is already in the dictionary, add the current value to the list of values for that FX
			storage[fx] = append(storage[fx], value)
		}
	}

	// Calculate the result using the formula given in the problem statement
	result := (sum(len(storage[fx]) * len(storage[fx]) for _, fx := range FXs) - sum(len(storage[fx]) for _, fx := range FXs)) / 2

	// Return the result
	return result
}

// This function takes an integer as input and returns its FX value
func f(n int) int {
	// Initialize a variable to store the FX value
	fx := 1

	// Perform bitwise operations until the number is reduced to 1
	for n!= 1 {
		// If the number is odd, increment the FX value
		if n%2!= 0 {
			fx++
		}

		// Divide the number by 2 to reduce it further
		n /= 2
	}

	// Return the final FX value
	return fx
}

// Run the main function if the script is executed directly
func main() {
	// Call the main function and print the result
	fmt.Println(main())
}

// This function takes a sequence as input and returns the number of pairs with common FX
func nPairsWithCommonFX(sequence []int) int {
	// Initialize an empty dictionary to store FX values and their corresponding values
	storage := make(map[int][]int)

	// Initialize an empty list to store unique FX values
	FXs := []int{}

	// Iterate through each value in the sequence
	for _, value := range sequence {
		// Compute the FX value for the current value
		fx := f(value)

		// If the FX value is not already in the dictionary, add it along with the value
		if _, ok := storage[fx];!ok {
			storage[fx] = []int{value}
			FXs = append(FXs, fx)
		} else {
			// If the FX value is already in the dictionary, add the current value to the list of values for that FX
			storage[fx] = append(storage[fx], value)
		}
	}

	// Calculate the result using the formula given in the problem statement
	result := (sum(len(storage[fx]) * len(storage[fx]) for _, fx := range FXs) - sum(len(storage[fx]) for _, fx := range FXs)) / 2

	// Return the result
	return result
}

// This function takes an integer as input and returns its FX value
func f(n int) int {
	// Initialize a variable to store the FX value
	fx := 1

	// Perform bitwise operations until the number is reduced to 1
	for n!= 1 {
		// If the number is odd, increment the FX value
		if n%2!= 0 {
			fx++
		}

		// Divide the number by 2 to reduce it further
		n /= 2
	}

	// Return the final FX value
	return fx
}

// This is the main function that takes input and calls the helper function nPairsWithCommonFX
func main() {
	// Read input from standard input
	reader := bufio.NewReader(os.Stdin)
	input()

	// Call the helper function with the sequence obtained from input
	result := nPairsWithCommonFX(map[int]int(input().split()))

	// Print the result
	fmt.Println(result)
}

// This function takes a sequence as input and returns the number of pairs with common FX
func nPairsWithCommonFX(sequence map[int]int) int {
	// Initialize an empty dictionary to store FX values and their corresponding values
	storage := make(map[int][]int)

	// Initialize an empty list to store unique FX values
	FXs := []int{}

	// Iterate through each value in the sequence
	for value := range sequence {
		// Compute the FX value for the current value
		fx := f(value)

		// If the FX value is not already in the dictionary, add it along with the value
		if _, ok := storage[fx];!ok {
			storage[fx] = []int{value}
			FXs = append(FXs, fx)
		} else {
			// If the FX value is already in the dictionary, add the current value to the list of values for that FX
			storage[fx] = append(storage[fx], value)
		}
	}

	// Calculate the result using the formula given in the problem statement
	result := (sum(len(storage[fx]) * len(storage[fx]) for _, fx := range FXs) - sum(len(storage[fx]) for _, fx := range FXs)) / 2

	// Return the result
	return result
}

// This function takes an integer as input and returns its FX value
func f(n int) int {
	// Initialize a variable to store the FX value
	fx := 1

	// Perform bitwise operations until the number is reduced to 1
	for n!= 1 {
		// If the number is odd, increment the FX value
		if n%2!= 0 {
			fx++
		}

		// Divide the number by 2 to reduce it further
		n /= 2
	}

	// Return the final FX value
	return fx
}

// Run the main function if the script is executed directly
func main() {
	// Call the main function and print the result
	fmt.Println(main())
}

// This function takes a sequence as input and returns the number of pairs with common FX
func nPairsWithCommonFX(sequence []int) int {
	// Initialize an empty dictionary to store FX values and their corresponding values
	storage := make(map[int][]int)

	// Initialize an empty list to store unique FX values
	FXs := []int{}

	// Iterate through each value in the sequence
	for _, value := range sequence {
		// Compute the FX value for the current value
		fx := f(value)

		// If the FX value is not already in the dictionary, add it along with the value
		if _, ok := storage[fx];!ok {
			storage[fx] = []int{value}
			FXs = append(FXs, fx)
		} else {
			// If the FX value is already in the dictionary, add the current value to the list of values for that FX
			storage[fx] = append(storage[fx], value)
		}
	}

	// Calculate the result using the formula given in the problem statement
	result := (sum(len(storage[fx]) * len(storage[fx]) for _, fx := range FXs) - sum(len(storage[fx]) for _, fx := range FXs)) / 2

	// Return the result
	return result
}

// This function takes an integer as input and returns its FX value
func f(n int) int {
	// Initialize a variable to store the FX value
	fx := 1

	// Perform bitwise operations until the number is reduced to 1
	for n!= 1 {
		// If the number is odd, increment the FX value
		if n%2!= 0 {
			fx++
		}

		// Divide the number by 2 to reduce it further
		n /= 2
	}

	// Return the final FX value
	return fx
}

// This is the main function that takes input and calls the helper function nPairsWithCommonFX
func main() {
	// Read input from standard input
	reader := bufio.NewReader(os.Stdin)
	input()

	// Call the helper function with the sequence obtained from input
	result := nPairsWithCommonFX(map[int]int(input().split()))

	// Print the result
	fmt.Println(result)
}

// This function takes a sequence as input and returns the number of pairs with common FX
func nPairsWithCommonFX(sequence map[int]int) int {
	// Initialize an empty dictionary to store FX values and their corresponding values
	storage := make(map[int][]int)

	// Initialize an empty list to store unique FX values
	FXs := []int{}

	// Iterate through each value in the sequence
	for value := range sequence {
		// Compute the FX value for the current value
		fx := f(value)

		// If the FX value is not already in the dictionary, add it along with the value
		if _, ok := storage[fx];!ok {
			storage[fx] = []int{value}
			FXs = append(FXs, fx)
		} else {
			// If the FX value is already in the dictionary, add the current value to the list of values for that FX
			storage[fx] = append(storage[fx], value)
		}
	}

	// Calculate the result using the formula given in the problem statement
	result := (sum(len(storage[fx]) * len(storage[fx]) for _, fx := range FXs) - sum(len(storage[fx]) for _, fx := range FXs)) / 2

	// Return the result
	return result
}

// This function takes an integer as input and returns its FX value
func f(n int) int {
	// Initialize a variable to store the FX value
	fx := 1

	// Perform bitwise opera