package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Take input from the user
	reader := bufio.NewReader(os.Stdin)
	reader.ReadString('\n')
	// Process the input and call nPairsWithCommonFX with the processed input
	sequence := parseInts(reader.ReadString('\n'))
	fmt.Println(nPairsWithCommonFX(sequence))
}

func parseInts(input string) []int {
	fields := strings.Fields(input)
	ints := make([]int, len(fields))
	for i, field := range fields {
		num, _ := strconv.Atoi(field)
		ints[i] = num
	}
	return ints
}

func nPairsWithCommonFX(sequence []int) int {
	// Initialize a dictionary to store values grouped by their computed property
	storage := make(map[int][]int)
	// List to store the computed property values
	var FXs []int
	for _, value := range sequence {
		// Compute the property for the current value
		y := f(value)
		// If the property is not already in storage, add it with the current value
		if _, exists := storage[y]; !exists {
			storage[y] = []int{value}
			FXs = append(FXs, y)
		} else {
			// Otherwise, append the current value to the list of values for this property
			storage[y] = append(storage[y], value)
		}
	}
	// Calculate the number of pairs with common factor greater than 1
	sum := 0
	for _, y := range FXs {
		sum += len(storage[y]) * len(storage[y])
	}
	return (sum - len(FXs)) / 2
}

func f(n int) int {
	// Initialize y to 1, which will be the result for the property of n
	y := 1
	for n != 1 {
		if n%2 == 1 {
			y += 1
		}
		n /= 2
	}
	return y
}

