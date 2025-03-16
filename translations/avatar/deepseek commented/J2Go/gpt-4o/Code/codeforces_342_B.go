package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a BufferedReader to read input from the standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the input and split it into an array of strings
	input, _ := reader.ReadString('\n')
	inputArr := strings.Fields(input)

	// Parse the required integers from the input
	m, _ := strconv.Atoi(inputArr[1])
	s, _ := strconv.Atoi(inputArr[2])
	f, _ := strconv.Atoi(inputArr[3])

	// Initialize the maximum time and a map to store the intervals
	maxT := -1
	mapIntervals := make(map[int][]int)

	// Read the intervals from the input and store them in the map
	for m > 0 {
		mth, _ := reader.ReadString('\n')
		mthArr := strings.Fields(mth)
		k, _ := strconv.Atoi(mthArr[0])
		a, _ := strconv.Atoi(mthArr[1])
		b, _ := strconv.Atoi(mthArr[2])
		mapIntervals[k] = []int{a, b}
		if k > maxT {
			maxT = k
		}
		m--
	}

	// Initialize a StringBuilder to build the sequence of actions
	var actions strings.Builder

	// Determine the direction of movement and initialize the current position
	var M byte
	var d int
	if s < f {
		M = 'R'
		d = 1
	} else {
		M = 'L'
		d = -1
	}
	cur := s

	// Variables to store the current interval's start and end
	a, b := -1, -1

	// Build the sequence of actions based on the intervals and the current position
	for t := 1; t <= maxT; t++ {
		if interval, exists := mapIntervals[t]; exists {
			a = interval[0]
			b = interval[1]
		}
		if _, exists := mapIntervals[t]; exists && ((cur >= a && cur <= b) || (cur+d >= a && cur+d <= b)) {
			actions.WriteByte('X')
		} else {
			actions.WriteByte(M)
			cur += d
		}
		if cur == f {
			break
		}
	}

	// Continue moving in the determined direction until reaching the final position
	for cur != f {
		actions.WriteByte(M)
		cur += d
	}

	// Print the sequence of actions
	fmt.Println(actions.String())
}

// <END-OF-CODE>
