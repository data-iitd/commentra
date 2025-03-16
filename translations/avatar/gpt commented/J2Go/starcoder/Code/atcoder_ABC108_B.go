package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// revpos calculates the new position based on two input positions
func revpos(p, q []int) []int {
	// Initialize a vector to hold the difference between the two positions
	vec := make([]int, 2)
	
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
	newpos := make([]int, 2)
	
	// Calculate the new position by adding the rotated vector to position q
	for i := 0; i < len(newpos); i++ {
		newpos[i] = q[i] + vec[i]
	}
	
	// Return the newly calculated position
	return newpos
}

func main() {
	// Create a new Scanner to read input from stdin
	scan := bufio.NewScanner(os.Stdin)
	
	// Initialize an array to hold the input values
	input := make([]int, 4)
	
	// Read four integers from stdin
	for i := 0; i < len(input); i++ {
		scan.Scan()
		input[i], _ = strconv.Atoi(scan.Text())
	}
	
	// Initialize a 2D array to hold positions
	position := make([][]int, 4)
	
	// Assign input values to the first two positions
	position[0] = []int{input[0], input[1]}
	position[1] = []int{input[2], input[3]}
	
	// Calculate the new position based on the first two positions
	position[2] = revpos(position[0], position[1])
	
	// Calculate another new position based on the second and third positions
	position[3] = revpos(position[1], position[2])
	
	// Check if the first position is equal to the result of revpos on the last two positions
	if position[0] == revpos(position[2], position[3]) {
		fmt.Println("OK")
	}
	
	// Prepare an output array to hold the results
	output := make([]int, 4)
	
	// Assign the calculated positions to the output array
	output[0] = position[2][0]
	output[1] = position[2][1]
	output[2] = position[3][0]
	output[3] = position[3][1]
	
	// Print the output values
	fmt.Println(strings.Trim(fmt.Sprint(output), "[]"))
}

