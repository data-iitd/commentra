package main

import (
	"fmt"
)

// Define a function to reverse the order of elements in an array
func revpos(p, q []int) []int {
	vec := []int{0, 0} // Initialize a temporary vector with zeros

	// Iterate through the elements of the vector and calculate their differences
	for i := 0; i < len(vec); i++ {
		vec[i] = p[i] - q[i] // Subtract corresponding elements of p and q and store the result in vec[i]
	}

	// Swap the first and second elements of the vector
	tmp := 0
	tmp = vec[0]
	vec[0] = vec[1]
	vec[1] = -tmp

	// Calculate the new positions by adding the vector elements to the corresponding elements of q
	newpos := []int{0, 0}
	for i := 0; i < len(newpos); i++ {
		newpos[i] = q[i] + vec[i]
	}

	// Return the new positions
	return newpos
}

func main() {
	// Create a new Scanner object to read input from the standard input stream
	// Note: In Go, we don't have a built-in Scanner object, so we'll use fmt.Scan to read input
	var input [4]int

	// Read four integers as input and store them in an array
	for i := 0; i < len(input); i++ {
		fmt.Scan(&input[i]) // Read an integer from the standard input stream and store it in input[i]
	}

	// Define a 2D array to store the positions of the four integers
	position := [2][2]int{
		{input[0], input[1]},
		{input[2], input[3]},
	}

	// Calculate the reversed positions of the first and second positions
	reversedPositions := [2][2]int{
		revpos([]int{position[0][0], position[0][1]}, []int{position[1][0], position[1][1]}),
		revpos([]int{position[1][0], position[1][1]}, []int{position[0][0], position[0][1]}),
	}

	// Check if the first and second reversed positions are equal
	if position[0] == reversedPositions[1] { // Compare the first position with the reversed second position
		fmt.Println("OK") // Print "OK" if they are equal
	}

	// Calculate the output array by taking the reversed positions and swapping their x and y coordinates
	output := [4]int{
		reversedPositions[1][0],
		reversedPositions[1][1],
		reversedPositions[0][0],
		reversedPositions[0][1],
	}

	// Print the output array
	for _, i := range output {
		fmt.Println(i)
	}
}

