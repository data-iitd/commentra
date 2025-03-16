
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a buffered reader to read input from stdin.
	reader := bufio.NewReader(os.Stdin)

	// Read the input and split it into an array of strings.
	input, _ := reader.ReadString('\n')
	input = strings.Split(input, " ")

	// Parse the required integers from the input.
	m, _ := strconv.Atoi(input[1])
	s, _ := strconv.Atoi(input[2])
	f, _ := strconv.Atoi(input[3])

	// Initialize the maximum time and a map to store the intervals.
	maxT := -1
	map := make(map[int][]int)

	// Read the intervals from the input and store them in the map.
	for m > 0 {
		input, _ := reader.ReadString('\n')
		input = strings.Split(input, " ")
		k, _ := strconv.Atoi(input[0])
		map[k] = make([]int, 2)
		map[k][0], _ = strconv.Atoi(input[1])
		map[k][1], _ = strconv.Atoi(input[2])
		maxT = int(math.Max(float64(maxT), float64(k)))
		m--
	}

	// Initialize a string builder to build the sequence of actions.
	actions := new(strings.Builder)

	// Determine the direction of movement and initialize the current position.
	var M byte
	if s < f {
		M = 'R'
	} else {
		M = 'L'
	}
	d := 1
	if s < f {
		d = +1
	} else {
		d = -1
	}
	cur := s

	// Variables to store the current interval's start and end.
	a := -1
	b := -1

	// Build the sequence of actions based on the intervals and the current position.
	for t := 1; t <= maxT; t++ {
		if _, ok := map[t]; ok {
			a = map[t][0]
			b = map[t][1]
		}
		if _, ok := map[t]; ok && ((cur >= a && cur <= b) || (cur+d >= a && cur+d <= b)) {
			actions.WriteString("X")
		} else {
			actions.WriteString(string(M))
			cur += d
		}
		if cur == f {
			break
		}
	}

	// Continue moving in the determined direction until reaching the final position.
	for cur!= f {
		actions.WriteString(string(M))
		cur += d
	}

	// Print the sequence of actions.
	fmt.Println(actions)
}

