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
	input := strings.Split(readLine(reader), " ")
	
	// Parse the number of movements (m), start position (s), and final position (f)
	m, _ := strconv.Atoi(input[1])
	s, _ := strconv.Atoi(input[2])
	f, _ := strconv.Atoi(input[3])
	
	// Initialize maxT to keep track of the maximum time step
	maxT := -1
	
	// Create a map to store the movements at each time step
	moveMap := make(map[int][]int)
	
	// Read the movements for each time step
	for m > 0 {
		// Read the movement data for the current time step
		mth := strings.Split(readLine(reader), " ")
		k, _ := strconv.Atoi(mth[0])
		
		// Add the movement range to the map
		moveMap[k] = []int{parseInt(mth[1]), parseInt(mth[2])}
		
		// Update maxT to the highest time step encountered
		if k > maxT {
			maxT = k
		}
		m--
	}
	
	// Prepare a StringBuilder to store the actions taken
	var actions strings.Builder
	
	// Determine the direction of movement based on start and final positions
	dir := 'R'
	if s > f {
		dir = 'L'
	}
	
	// Initialize current position to start position
	cur := s
	
	// Iterate through each time step from 1 to maxT
	for t := 1; t <= maxT; t++ {
		// Check if there are movements defined for the current time step
		if move, ok := moveMap[t]; ok {
			a, b := move[0], move[1]
			// Check if the current position or the next position is within the movement range
			if (cur >= a && cur <= b) || (cur+1 >= a && cur+1 <= b) {
				actions.WriteByte('X') // Append 'X' if within the range
			} else {
				actions.WriteByte(byte(dir)) // Append the movement direction
				cur += 1 // Update the current position
			}
		} else {
			actions.WriteByte(byte(dir)) // Append the movement direction
			cur += 1 // Update the current position
		}
		
		// Break the loop if the current position reaches the final position
		if cur == f {
			break
		}
	}
	
	// Continue moving until the current position reaches the final position
	for cur != f {
		actions.WriteByte(byte(dir)) // Append the movement direction
		cur += 1 // Update the current position
	}
	
	// Output the sequence of actions taken
	fmt.Println(actions.String())
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}

func parseInt(s string) int {
	n, err := strconv.Atoi(s)
	if err != nil {
		panic(err)
	}
	return n
}
<END-OF-CODE>.