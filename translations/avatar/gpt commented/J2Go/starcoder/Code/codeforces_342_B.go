package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the first line of input and split it into an array
	input := strings.Split(readLine(), " ")

	// Parse the number of movements (m), start position (s), and final position (f)
	m, _ := strconv.Atoi(input[1])
	s, _ := strconv.Atoi(input[2])
	f, _ := strconv.Atoi(input[3])

	// Initialize maxT to keep track of the maximum time step
	maxT := -1

	// Create a HashMap to store the movements at each time step
	map := make(map[int][]int)

	// Read the movements for each time step
	for m > 0 {
		// Read the movement data for the current time step
		input := strings.Split(readLine(), " ")
		k, _ := strconv.Atoi(input[0])

		// Initialize the list for the current time step and add the movement range
		map[k] = make([]int, 2)
		map[k][0], _ = strconv.Atoi(input[1])
		map[k][1], _ = strconv.Atoi(input[2])

		// Update maxT to the highest time step encountered
		maxT = int(math.Max(float64(maxT), float64(k)))
		m--
	}

	// Prepare a StringBuilder to store the actions taken
	actions := new(strings.Builder)

	// Determine the direction of movement based on start and final positions
	var M byte
	if s < f {
		M = 'R'
	} else {
		M = 'L'
	}
	d := 1
	if s > f {
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
		if _, ok := map[t]; ok && ((cur >= a && cur <= b) || (cur+d >= a && cur+d <= b)) {
			actions.WriteString("X") // Append 'X' if within the range
		} else {
			actions.WriteString(string(M)) // Append the movement direction
			cur += d // Update the current position
		}

		// Break the loop if the current position reaches the final position
		if cur == f {
			break
		}
	}

	// Continue moving until the current position reaches the final position
	for cur!= f {
		actions.WriteString(string(M)) // Append the movement direction
		cur += d // Update the current position
	}

	// Output the sequence of actions taken
	fmt.Println(actions.String())
}

func readLine() string {
	r := bufio.NewReader(os.Stdin)
	input, _ := r.ReadString('\n')
	return strings.TrimSpace(input)
}

