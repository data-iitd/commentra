package main

import (
	"fmt"
)

// Method to calculate the new position based on two input positions
func revpos(p, q []int) []int {
	// Initialize a vector to hold the difference between the two positions
	vec := []int{0, 0}
	
	// Calculate the difference between position p and q
	for i := 0; i < len(vec); i++ {
		vec[i] = p[i] - q[i]
	}
	
	// Rotate the vector to get the new direction
	tmp := 0
	tmp = vec[0]
	vec[0] = vec[1]
	vec[1] = -tmp
	
	// Initialize a new position array
	newpos := []int{0, 0}
	
	// Calculate the new position by adding the rotated vector to position q
	for i := 0; i < len(newpos); i++ {
		newpos[i] = q[i] + vec[i]
	}
	
	// Return the newly calculated position
	return newpos
}

func main() {
	// Create a Scanner object to read input from the user
	var input [4]int
	
	// Read four integers from the user input
	for i := 0; i < len(input); i++ {
		fmt.Scan(&input[i])
	}
	
	// Initialize a 2D array to hold positions
	position := [4][2]int{{0, 0}, {0, 0}, {0, 0}, {0, 0}}
	
	// Assign input values to the first two positions
	position[0][0] = input[0]
	position[0][1] = input[1]
	position[1][0] = input[2]
	position[1][1] = input[3]
	
	// Calculate the new position based on the first two positions
	position[2] = revpos([]int{position[0][0], position[0][1]}, []int{position[1][0], position[1][1]})
	
	// Calculate another new position based on the second and third positions
	position[3] = revpos([]int{position[1][0], position[1][1]}, []int{position[2][0], position[2][1]})
	
	// Check if the first position is equal to the result of revpos on the last two positions
	if position[0] == (revpos([]int{position[2][0], position[2][1]}, []int{position[3][0], position[3][1]})) {
		fmt.Println("OK")
	}
	
	// Prepare an output array to hold the results
	var output [4]int
	
	// Assign the calculated positions to the output array
	output[0] = position[2][0]
	output[1] = position[2][1]
	output[2] = position[3][0]
	output[3] = position[3][1]
	
	// Print the output values
	for _, i := range output {
		fmt.Println(i)
	}
}
