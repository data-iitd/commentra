package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// revpos calculates the difference between two positions, swaps the components of the difference vector, and then adds the modified difference vector to the second position.
func revpos(p, q []int) []int {
	vec := make([]int, 2) // Initialize the vector to store the difference
	for i := 0; i < len(vec); i++ {
		vec[i] = p[i] - q[i] // Calculate the difference between p and q
	}
	tmp := 0 // Temporary variable to swap the components of the vector
	tmp = vec[0] // Swap the first component
	vec[0] = vec[1] // Swap the second component to the first position
	vec[1] = -tmp // Negate the first component and store it in the second position
	newpos := make([]int, 2) // Initialize the new position vector
	for i := 0; i < len(newpos); i++ {
		newpos[i] = q[i] + vec[i] // Add the modified difference vector to the second position
	}
	return newpos // Return the new position
}

func main() {
	scan := bufio.NewScanner(os.Stdin) // Create a Scanner object to read input
	input := make([]int, 4) // Initialize the input array to store four integers
	for i := 0; i < len(input); i++ {
		scan.Scan() // Read a line of input from the user
		input[i], _ = strconv.Atoi(strings.TrimSpace(scan.Text())) // Read an integer from the user
	}
	position := make([][]int, 4) // Initialize the position array
	position[0] = make([]int, 2) // Initialize the first position
	position[0][0] = input[0] // Assign the first integer to the first position's x-coordinate
	position[0][1] = input[1] // Assign the second integer to the first position's y-coordinate
	position[1] = make([]int, 2) // Initialize the second position
	position[1][0] = input[2] // Assign the third integer to the second position's x-coordinate
	position[1][1] = input[3] // Assign the fourth integer to the second position's y-coordinate
	position[2] = revpos(position[0], position[1]) // Compute the new position using revpos
	position[3] = revpos(position[1], position[2]) // Compute another new position using revpos
	if position[0] == revpos(position[2], position[3]) { // Check if the first position is equal to the result of revpos on the second and third positions
		fmt.Println("OK") // Print "OK" if they are equal
	}
	output := make([]int, 4) // Initialize the output array
	output[0] = position[2][0] // Assign the x-coordinate of the second new position to the output array
	output[1] = position[2][1] // Assign the y-coordinate of the second new position to the output array
	output[2] = position[3][0] // Assign the x-coordinate of the third new position to the output array
	output[3] = position[3][1] // Assign the y-coordinate of the third new position to the output array
	for _, i := range output {
		fmt.Println(i) // Print each element of the output array
	}
}

