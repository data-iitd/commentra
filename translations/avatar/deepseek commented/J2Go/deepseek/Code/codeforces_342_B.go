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
	input = strings.TrimSpace(input)
	inputs := strings.Split(input, " ")
	
	// Parse the required integers from the input
	m, _ := strconv.Atoi(inputs[1])
	s, _ := strconv.Atoi(inputs[2])
	f, _ := strconv.Atoi(inputs[3])
	
	// Initialize the maximum time and a HashMap to store the intervals
	maxT := -1
	mp := make(map[int][]int)
	
	// Read the intervals from the input and store them in the HashMap
	for m > 0 {
		interval, _ := reader.ReadString('\n')
		interval = strings.TrimSpace(interval)
		mth := strings.Split(interval, " ")
		k, _ := strconv.Atoi(mth[0])
		mp[k] = []int{0, 0}
		mp[k][0], _ = strconv.Atoi(mth[1])
		mp[k][1], _ = strconv.Atoi(mth[2])
		if k > maxT {
			maxT = k
		}
		m--
	}
	
	// Initialize a StringBuilder to build the sequence of actions
	var actions strings.Builder
	
	// Determine the direction of movement and initialize the current position
	var M = 'R'
	if s > f {
		M = 'L'
	}
	d := 1
	if s > f {
		d = -1
	}
	cur := s
	
	// Variables to store the current interval's start and end
	var a, b int
	
	// Build the sequence of actions based on the intervals and the current position
	for t := 1; t <= maxT; t++ {
		if val, ok := mp[t]; ok {
			a, b = val[0], val[1]
		}
		if val, ok := mp[t]; ok && ((cur >= a && cur <= b) || (cur+d >= a && cur+d <= b)) {
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
