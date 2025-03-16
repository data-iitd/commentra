
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize bufio.Scanner to read input from the console
	reader := bufio.NewScanner(os.Stdin)

	// Read the first line of input and split it into an array
	reader.Scan()
	input := strings.Split(reader.Text(), " ")

	// Parse the number of movements (m), start position (s), and final position (f)
	m, _ := strconv.Atoi(input[1])
	s, _ := strconv.Atoi(input[2])
	f, _ := strconv.Atoi(input[3])

	// Initialize maxT to keep track of the maximum time step
	maxT := -1

	// Create a map to store the movements at each time step
	movements := make(map[int][]int)

	// Read the movements for each time step
	for m > 0 {
		// Read the movement data for the current time step
		reader.Scan()
		input := strings.Split(reader.Text(), " ")
		k, _ := strconv.Atoi(input[0])

		// Initialize the list for the current time step and add the movement range
		movements[k] = []int{
			strconv.Atoi(input[1]),
			strconv.Atoi(input[2]),
		}

		// Update maxT to the highest time step encountered
		maxT = int(math.Max(float64(maxT), float64(k)))
		m--
	}

	// Prepare a StringBuilder to store the actions taken
	var actions strings.Builder

	// Determine the direction of movement based on start and final positions
	M := 'R'
	if s > f {
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
		if _, ok := movements[t]; ok {
			a = movements[t][0] // Get the start of the movement range
			b = movements[t][1] // Get the end of the movement range
		}

		// Check if the current position or the next position is within the movement range
		if _, ok := movements[t]; ok && ((cur >= a && cur <= b) || (cur+d >= a && cur+d <= b)) {
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

