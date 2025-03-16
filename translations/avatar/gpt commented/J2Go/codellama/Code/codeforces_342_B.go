package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize a scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input and split it into an array
	input := strings.Split(scanner.Text(), " ")

	// Parse the number of movements (m), start position (s), and final position (f)
	m, _ := strconv.Atoi(input[1])
	s, _ := strconv.Atoi(input[2])
	f, _ := strconv.Atoi(input[3])

	// Initialize maxT to keep track of the maximum time step
	maxT := -1

	// Create a map to store the movements at each time step
	map := make(map[int][]int)

	// Read the movements for each time step
	for m > 0 {
		// Read the movement data for the current time step
		mth := strings.Split(scanner.Text(), " ")
		k, _ := strconv.Atoi(mth[0])

		// Initialize the list for the current time step and add the movement range
		map[k] = make([]int, 2)
		map[k][0], _ = strconv.Atoi(mth[1])
		map[k][1], _ = strconv.Atoi(mth[2])

		// Update maxT to the highest time step encountered
		maxT = max(maxT, k)
		m--
	}

	// Prepare a string builder to store the actions taken
	actions := ""

	// Determine the direction of movement based on start and final positions
	mth := "R"
	d := 1
	if s > f {
		mth = "L"
		d = -1
	}

	// Initialize current position to start position
	cur := s
	a := -1
	b := -1

	// Iterate through each time step from 1 to maxT
	for t := 1; t <= maxT; t++ {
		// Check if there are movements defined for the current time step
		if _, ok := map[t]; ok {
			a = map[t][0] // Get the start of the movement range
			b = map[t][1] // Get the end of the movement range
		}

		// Check if the current position or the next position is within the movement range
		if _, ok := map[t]; ok && (cur >= a && cur <= b || cur+d >= a && cur+d <= b) {
			actions += "X" // Append 'X' if within the range
		} else {
			actions += mth // Append the movement direction
			cur += d      // Update the current position
		}

		// Break the loop if the current position reaches the final position
		if cur == f {
			break
		}
	}

	// Continue moving until the current position reaches the final position
	for cur != f {
		actions += mth // Append the movement direction
		cur += d      // Update the current position
	}

	// Output the sequence of actions taken
	fmt.Println(actions)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 