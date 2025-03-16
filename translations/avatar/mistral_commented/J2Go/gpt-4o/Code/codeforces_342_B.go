package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Initialize BufferedReader to read input

	input, _ := reader.ReadString('\n') // Read the first line of input
	inputArr := strings.Fields(input)     // Split it into an array
	m, _ := strconv.Atoi(inputArr[0])    // Read the number of methods
	s, _ := strconv.Atoi(inputArr[2])     // Read the start position
	f, _ := strconv.Atoi(inputArr[3])     // Read the finish position
	maxT := -1                            // Initialize maximum thread ID

	mapThreads := make(map[int][]int) // Create a map to store thread IDs and their arrival and departure times

	// Read the remaining lines of input and store the thread IDs and their arrival and departure times in the map
	for m > 0 {
		mth, _ := reader.ReadString('\n') // Read a line of input
		mthArr := strings.Fields(mth)      // Split it into an array
		k, _ := strconv.Atoi(mthArr[0])    // Read the thread ID
		arrival, _ := strconv.Atoi(mthArr[1]) // Read the arrival time
		departure, _ := strconv.Atoi(mthArr[2]) // Read the departure time
		mapThreads[k] = []int{arrival, departure} // Store arrival and departure times
		if k > maxT {
			maxT = k // Update the maximum thread ID
		}
		m-- // Decrement the number of methods to be read
	}

	var actions strings.Builder // Initialize a strings.Builder to store the output
	var M byte                 // Direction character
	if s < f {
		M = 'R' // Determine the direction of the simulation based on the start and finish positions
	} else {
		M = 'L'
	}
	d := 1 // Determine the direction of the simulation as 1 for right
	if s > f {
		d = -1 // Change direction to left if start is greater than finish
	}
	cur := s // Initialize the current position
	a, b := -1, -1 // Initialize variables for storing the arrival and departure times of the current thread

	// Simulate the execution of threads and generate the output
	for t := 1; t <= maxT; t++ {
		if times, exists := mapThreads[t]; exists { // Check if there is a thread with the given ID
			a = times[0] // Get the arrival time of the thread
			b = times[1] // Get the departure time of the thread

			if (cur >= a && cur <= b) || (cur+d >= a && cur+d <= b) { // Check if the current position is within the execution time of the thread
				actions.WriteByte('X') // Append an 'X' to the output
			} else {
				actions.WriteByte(M) // Append the direction character to the output
				cur += d // Move the current position in the direction of the simulation
			}

			if cur == f { // Break the loop if the finish position is reached
				break
			}
		} else {
			actions.WriteByte(M) // Append the direction character to the output if there is no thread at the current position
			cur += d // Move the current position in the direction of the simulation
		}
	}

	// Print the output to the console
	for cur != f {
		actions.WriteByte(M)
		cur += d
	}
	fmt.Println(actions.String()) // Print the final actions
}

// <END-OF-CODE>
