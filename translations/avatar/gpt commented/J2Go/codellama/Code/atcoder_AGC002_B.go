package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the user
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of boxes (N) and the number of moves (M)
	N, _ := strconv.Atoi(sc.Text())
	M, _ := strconv.Atoi(sc.Text())

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
		x, _ := strconv.Atoi(sc.Text())
		y, _ := strconv.Atoi(sc.Text())
		// Move the contents from box x to box y
		B[x-1].moveTo(&B[y-1])
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

// Box class representing a box with a number and a color state
type Box struct {
	num  int
	red  bool
}

// Method to move items from this box to another box
func (b *Box) moveTo(other *Box) {
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

