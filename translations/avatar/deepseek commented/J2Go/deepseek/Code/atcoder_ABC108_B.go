package main

import (
	"fmt"
)

// revpos function calculates the difference between two positions,
// swaps the components of the difference vector, and then adds the modified
// difference vector to the second position.
func revpos(p, q []int) []int {
	vec := []int{0, 0} // Initialize the vector to store the difference
	for i := 0; i < len(vec); i++ {
		vec[i] = p[i] - q[i] // Calculate the difference between p and q
	}
	tmp := 0 // Temporary variable to swap the components of the vector
	tmp = vec[0] // Swap the first component
	vec[0] = vec[1] // Swap the second component to the first position
	vec[1] = -tmp // Negate the first component and store it in the second position
	newpos := []int{0, 0} // Initialize the new position vector
	for i := 0; i < len(newpos); i++ {
		newpos[i] = q[i] + vec[i] // Add the modified difference vector to the second position
	}
	return newpos // Return the new position
}

func main() {
	var input [4]int // Initialize the input array to store four integers
	for i := 0; i < len(input); i++ {
		fmt.Scan(&input[i]) // Read four integers from the user
	}
	position := [4][2]int{{0, 0}, {0, 0}, {0, 0}, {0, 0}} // Initialize the position array
	position[0][0] = input[0] // Assign the first integer to the first position's x-coordinate
	position[0][1] = input[1] // Assign the second integer to the first position's y-coordinate
	position[1][0] = input[2] // Assign the third integer to the second position's x-coordinate
	position[1][1] = input[3] // Assign the fourth integer to the second position's y-coordinate
	position[2] = revpos(position[0][:], position[1][:]) // Compute the new position using revpos
	position[3] = revpos(position[1][:], position[2][:]) // Compute another new position using revpos
	if position[0] == revpos(position[2][:], position[3][:]) { // Check if the first position is equal to the result of revpos on the second and third positions
		fmt.Println("OK") // Print "OK" if they are equal
	}
	output := [4]int{0, 0, 0, 0} // Initialize the output array
	output[0] = position[2][0] // Assign the x-coordinate of the second new position to the output array
	output[1] = position[2][1] // Assign the y-coordinate of the second new position to the output array
	output[2] = position[3][0] // Assign the x-coordinate of the third new position to the output array
	output[3] = position[3][1] // Assign the y-coordinate of the third new position to the output array
	for _, i := range output {
		fmt.Println(i) // Print each element of the output array
	}
}
