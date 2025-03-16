
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a line of input and strip whitespace
func readInput() string {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}

// Function to read an integer from input
func readInt() int {
	input := readInput()
	value, _ := strconv.Atoi(input)
	return value
}

// Function to read a list of integers from input
func readInts(n int) []int {
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		ints[i] = readInt()
	}
	return ints
}

func main() {
	// Read the number of balls (N) and the number of operations (M)
	N, M := readInts(2)

	// Initialize a list to represent the state of each ball (weight and radius)
	balls := make([][2]int, N)
	balls[0] = [0, 1]  // Set the first ball's state

	// Process each operation
	for i := 0; i < M; i++ {
		x, y := readInts(2)  // Read the indices of the balls to operate on
		w_x, r_x := balls[x - 1]  // Get the state of ball x
		w_y, r_y := balls[y - 1]  // Get the state of ball y

		// Update the states of the balls based on their weights and radii
		if w_x >= 1 && r_x >= 1 {
			balls[x - 1][0] -= 1  // Decrease weight of ball x
			balls[y - 1][1] += 1  // Increase radius of ball y
		} else if w_x == 0 {
			balls[x - 1][1] -= 1  // Decrease radius of ball x
			balls[y - 1][1] += 1  // Increase radius of ball y
		} else {
			balls[x - 1][0] -= 1  // Decrease weight of ball x
			balls[y - 1][0] += 1  // Increase weight of ball y
	}

	// Calculate the number of balls with a non-zero radius
	ans := 0
	for i := 0; i < N; i++ {
		if balls[i][1] > 0 {  // Check if the radius of the ball is non-zero
			ans += 1  // Increment the count of balls with non-zero radius
	}

	// Print the final count of balls with non-zero radius
	fmt.Println(ans)
}

