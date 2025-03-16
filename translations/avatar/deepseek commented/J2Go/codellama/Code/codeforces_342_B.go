
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a bufio.Scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the input and split it into an array of strings
	scanner.Scan()
	input := strings.Split(scanner.Text(), " ")

	// Parse the required integers from the input
	m, _ := strconv.Atoi(input[1])
	s, _ := strconv.Atoi(input[2])
	f, _ := strconv.Atoi(input[3])

	// Initialize the maximum time and a map to store the intervals
	maxT := -1
	map := make(map[int][]int)

	// Read the intervals from the input and store them in the map
	for m > 0 {
		scanner.Scan()
		mth := strings.Split(scanner.Text(), " ")
		k, _ := strconv.Atoi(mth[0])
		map[k] = make([]int, 2)
		map[k][0], _ = strconv.Atoi(mth[1])
		map[k][1], _ = strconv.Atoi(mth[2])
		maxT = max(maxT, k)
		m--
	}

	// Initialize a string builder to build the sequence of actions
	actions := ""

	// Determine the direction of movement and initialize the current position
	var mth []int
	var a, b int
	var d int
	if s < f {
		d = 1
	} else {
		d = -1
	}
	cur := s

	// Build the sequence of actions based on the intervals and the current position
	for t := 1; t <= maxT; t++ {
		if map[t] != nil {
			a = map[t][0]
			b = map[t][1]
		}
		if map[t] != nil && (cur >= a && cur <= b || cur+d >= a && cur+d <= b) {
			actions += "X"
		} else {
			actions += "L"
			cur += d
		}
		if cur == f {
			break
		}
	}

	// Continue moving in the determined direction until reaching the final position
	for cur != f {
		actions += "L"
		cur += d
	}

	// Print the sequence of actions
	fmt.Println(actions)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 