package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Take input from the user
	fmt.Scanln()
	// Process the input and call nPairsWithCommonFX with the processed input
	fmt.Println(nPairsWithCommonFX(processInput(fmt.Scanln())))
}

func processInput(input string) []int {
	// Split the input by spaces and convert each element to an integer
	ints := make([]int, 0)
	for _, s := range strings.Split(input, " ") {
		i, _ := strconv.Atoi(s)
		ints = append(ints, i)
	}
	return ints
}

func nPairsWithCommonFX(sequence []int) int {
	// Initialize a dictionary to store values grouped by their computed property
	storage := make(map[int][]int)
	// List to store the computed property values
	FXs := make([]int, 0)
	for _, value := range sequence {
		// Compute the property for the current value
		y := f(value)
		// If the property is not already in storage, add it with the current value
		if _, ok := storage[y]; !ok {
			storage[y] = []int{value}
			FXs = append(FXs, y)
		} else {
			// Otherwise, append the current value to the list of values for this property
			storage[y] = append(storage[y], value)
		}
	}
	// Calculate the number of pairs with common factor greater than 1
	return (sum(len(storage[y]) * len(storage[y]) for y in FXs) - sum(len(storage[y]) for y in FXs)) / 2
}

func f(n int) int {
	// Initialize y to 1, which will be the result for the property of n
	y := 1
	for n != 1 {
		if n%2 != 0 {
			y += 1
		}
		n /= 2
	}
	return y
}

func sum(iterable []int) int {
	sum := 0
	for _, i := range iterable {
		sum += i
	}
	return sum
}

// 