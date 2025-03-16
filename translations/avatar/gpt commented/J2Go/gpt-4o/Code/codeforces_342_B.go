package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize BufferedReader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input and split it into an array
	input, _ := reader.ReadString('\n')
	inputArr := strings.Fields(input)

	// Parse the number of movements (m), start position (s), and final position (f)
	m, _ := strconv.Atoi(inputArr[1])
	s, _ := strconv.Atoi(inputArr[2])
	f, _ := strconv.Atoi(inputArr[3])

	// Initialize maxT to keep track of the maximum time step
	maxT := -1

	// Create a map to store the movements at each time step
	movementMap := make(map[int][]int)

	// Read the movements for each time step
	for m > 0 {
		// Read the movement data for the current time step
		mth, _ := reader.ReadString('\n')
		mthArr := strings.Fields(mth)
		k, _ := strconv.Atoi(mthArr[0])
		start, _ := strconv.Atoi(mthArr[1])
		end, _ := strconv.Atoi(mthArr[2])

		// Store the movement range in the map
		movementMap[k] = []int{start, end}

		// Update maxT to the highest time step encountered
		if k > maxT {
			maxT = k
		}
		m--
	}

	// Prepare a StringBuilder to store the actions taken
	var actions strings.Builder

	// Determine the direction of movement based on start and final positions
	var M rune
	var d int
	if s < f {
		M = 'R'
		d = 1
	} else {
		M = 'L'
		d = -1
	}

	// Initialize current position to start position
	cur := s
	var a, b int

	// Iterate through each time step from 1 to maxT
	for t := 1; t <= maxT; t++ {
		// Check if there are movements defined for the current time step
		if movement, exists := movementMap[t]; exists {
			a = movement[0] // Get the start of the movement range
			b = movement[1] // Get the end of the movement range
		}

		// Check if the current position or the next position is within the movement range
		if _, exists := movementMap[t]; exists && ((cur >= a && cur <= b) || (cur+d >= a && cur+d <= b)) {
			actions.WriteRune('X') // Append 'X' if within the range
		} else {
			actions.WriteRune(M) // Append the movement direction
			cur += d             // Update the current position
		}

		// Break the loop if the current position reaches the final position
		if cur == f {
			break
		}
	}

	// Continue moving until the current position reaches the final position
	for cur != f {
		actions.WriteRune(M) // Append the movement direction
		cur += d             // Update the current position
	}

	// Output the sequence of actions taken
	fmt.Println(actions.String())
}

// <END-OF-CODE>
