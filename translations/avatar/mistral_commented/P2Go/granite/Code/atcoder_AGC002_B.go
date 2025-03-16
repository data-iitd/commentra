
###
# Code
###

package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Define constants
const (
	EOF = -1
	SP = " "
	endl = "\n"
)

// Define global variables
var (
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

// Define helper functions
func read() (s string) {
	buf := new(bytes.Buffer)
	buf.ReadBytes('\n')
	s = buf.String()
	s = s[:len(s)-1]
	return
}

func readInt() (i int) {
	s := read()
	i, _ = fmt.Sscanf(s, "%d")
	return
}

func readInt64() (i int64) {
	s := read()
	i, _ = fmt.Sscanf(s, "%d")
	return
}

func readFloat64() (f float64) {
	s := read()
	f, _ = fmt.Sscanf(s, "%f")
	return
}

func readStr() (s string) {
	s = read()
	return
}

func readStrs() (ss []string) {
	s := read()
	ss = strings.Split(s, SP)
	return
}

func readInts() (is []int) {
	s := readStrs()
	for _, raw := range s {
		i, _ := fmt.Sscanf(raw, "%d")
		is = append(is, i)
	}
	return
}

func readInt64s() (is []int64) {
	s := readStrs()
	for _, raw := range s {
		i, _ := fmt.Sscanf(raw, "%d")
		is = append(is, i)
	}
	return
}

// Main function
func main() {
	// Read input number of balls and number of events
	N, M := readInt(), readInt()

	// Initialize list of balls with their weight and position
	balls := make([][2]int, N)
	for i := 0; i < N; i++ {
		balls[i] = [2]int{1, 0}
	}
	balls[0] = [2]int{0, 1}

	// Process each event
	for i := 0; i < M; i++ {
		// Read x and y coordinates of the event
		x, y := readInt(), readInt()

		// Get weight and position of balls at x and y
		w_x, r_x := balls[x-1][0], balls[x-1][1]
		w_y, r_y := balls[y-1][0], balls[y-1][1]

		// Update balls' weights and positions based on the event
		if w_x >= 1 && r_x >= 1 {
			// Ball x collides with ball y
			balls[x-1][0] -= 1
			balls[y-1][1] += 1
		} else if w_x == 0 {
			// Ball x is stationary and ball y collides with another ball
			balls[x-1][1] -= 1
			balls[y-1][1] += 1
		} else {
			// Ball x is moving and collides with ball y
			balls[x-1][0] -= 1
			balls[y-1][0] += 1
		}
	}

	// Calculate answer
	ans := 0
	// Iterate through the list of balls and count the number of moving balls
	for i := 0; i < N; i++ {
		if balls[i][1] > 0 {
			ans += 1
		}
	}

	// Print the answer
	fmt.Fprintln(out, ans)
	out.Flush()
}
