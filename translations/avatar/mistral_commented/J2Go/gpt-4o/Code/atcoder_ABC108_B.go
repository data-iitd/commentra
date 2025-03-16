package main

import (
	"fmt"
)

// Function to reverse the order of elements in an array
func revpos(p, q []int) []int {
	vec := []int{0, 0} // Initialize a temporary vector with zeros

	// Calculate the differences
	for i := 0; i < len(vec); i++ {
		vec[i] = p[i] - q[i] // Subtract corresponding elements of p and q
	}

	// Swap the first and second elements of the vector
	tmp := vec[0]
	vec[0] = vec[1]
	vec[1] = -tmp

	// Calculate the new positions
	newpos := []int{0, 0}
	for i := 0; i < len(newpos); i++ {
		newpos[i] = q[i] + vec[i]
	}

	// Return the new positions
	return newpos
}

func main() {
	// Read four integers as input
	var input [4]int
	for i := 0; i < len(input); i++ {
		fmt.Scan(&input[i]) // Read an integer from the standard input
	}

	// Define a 2D array to store the positions of the four integers
	position := [][2]int{
		{input[0], input[1]}, // First position
		{input[2], input[3]}, // Second position
	}

	// Calculate the reversed positions
	reversedPositions := [][2]int{
		revpos(position[0][:], position[1][:]),
		revpos(position[1][:], position[0][:]),
	}

	// Check if the first and second reversed positions are equal
	if position[0] == reversedPositions[1] {
		fmt.Println("OK") // Print "OK" if they are equal
	}

	// Calculate the output array by taking the reversed positions
	output := [4]int{
		reversedPositions[0][0], // x-coordinate of the first reversed position
		reversedPositions[0][1], // y-coordinate of the first reversed position
		reversedPositions[1][0], // x-coordinate of the second reversed position
		reversedPositions[1][1], // y-coordinate of the second reversed position
	}

	// Print the output array
	for _, i := range output {
		fmt.Println(i)
	}
}

// <END-OF-CODE>
