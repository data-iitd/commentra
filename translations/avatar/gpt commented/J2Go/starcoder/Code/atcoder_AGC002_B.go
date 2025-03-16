package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Box class representing a box with a number and a color state
type Box struct {
	num  int
	red  bool
}

// MoveTo method to move items from this box to another box
func (b *Box) MoveTo(other *Box) {
	// If this box is empty, do nothing
	if b.num == 0 {
		return
	}
	// If this box has one item, transfer it to the other box
	if b.num == 1 {
		b.num = 0
		other.num++
		// If this box is red, the other box becomes red
		if b.red {
			other.red = true
		}
		b.red = false // This box is no longer red
	}
	// If this box has more than one item, transfer one item to the other box
	if b.num > 1 {
		b.num--
		other.num++
		// If this box is red, the other box becomes red
		if b.red {
			other.red = true
		}
	}
}

func main() {
	// Create a new scanner to read from stdin
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of boxes (N) and the number of moves (M)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	M, _ := strconv.Atoi(scanner.Text())

	// Initialize an array of Box objects
	B := make([]Box, N)

	// Create the first box as red and the rest as not red
	B[0] = Box{1, true}
	for i := 1; i < N; i++ {
		B[i] = Box{1, false}
	}

	// Process M moves based on user input
	for i := 0; i < M; i++ {
		// Read the indices of the boxes to move from and to
		scanner.Scan()
		x, _ := strconv.Atoi(strings.TrimSpace(scanner.Text()))
		scanner.Scan()
		y, _ := strconv.Atoi(strings.TrimSpace(scanner.Text()))
		// Move the contents from box x to box y
		B[x-1].MoveTo(&B[y-1])
	}

	// Count the number of red boxes after all moves
	counter := 0
	for _, b := range B {
		if b.red {
			counter++
		}
	}

	// Output the count of red boxes
	fmt.Println(counter)
}

// 