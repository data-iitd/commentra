_

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a function to reverse the order of elements in an array
func revpos(p, q []int) []int {
	vec := make([]int, 2) // Initialize a temporary vector with zeros

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
	newpos := make([]int, 2)
	for i := 0; i < len(newpos); i++ {
		newpos[i] = q[i] + vec[i]
	}

	// Return the new positions
	return newpos
}

// Define the main function to read input and perform the required calculations
func main() {

	// Read four integers as input and store them in an array
	input := make([]int, 4)
	for i := 0; i < len(input); i++ {
		input[i], _ = strconv.Atoi(readLine()) // Read an integer from the standard input stream and store it in input[i]
	}

	// Define a 2D array to store the positions of the four integers
	position := make([][]int, 4)
	position[0] = make([]int, 2)
	position[0][0] = input[0] // Store the first integer as the x-coordinate of the first position
	position[0][1] = input[1] // Store the second integer as the y-coordinate of the first position
	position[1][0] = input[2] // Store the third integer as the x-coordinate of the second position
	position[1][1] = input[3] // Store the fourth integer as the y-coordinate of the second position

	// Calculate the reversed positions of the first and second positions
	reversedPositions := make([][]int, 2)
	reversedPositions[0] = revpos(position[0], position[1])
	reversedPositions[1] = revpos(position[1], position[0])

	// Check if the first and second reversed positions are equal
	if position[0] == reversedPositions[1] { // Compare the first position with the reversed second position
		fmt.Println("OK") // Print "OK" if they are equal
	}

	// Calculate the output array by taking the reversed positions and swapping their x and y coordinates
	output := make([]int, 4)
	output[0] = reversedPositions[2][0] // Store the x-coordinate of the reversed third position in output[0]
	output[1] = reversedPositions[2][1] // Store the y-coordinate of the reversed third position in output[1]
	output[2] = reversedPositions[3][0] // Store the x-coordinate of the reversed fourth position in output[2]
	output[3] = reversedPositions[3][1] // Store the y-coordinate of the reversed fourth position in output[3]

	// Print the output array
	for _, i := range output {
		fmt.Println(i)
	}
}

// ReadLine reads a string from stdin
func readLine() string {
	r := bufio.NewReader(os.Stdin)
	input, _ := r.ReadString('\n')
	return strings.TrimSpace(input)
}

// 