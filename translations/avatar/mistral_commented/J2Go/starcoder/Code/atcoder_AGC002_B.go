package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Defining the Box struct
type Box struct {
	num  int
	red  bool
	move int
}

// Defining the main function
func main() {
	// Reading the number of boxes and moves from the user
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of boxes: ")
	numBoxes, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Print("Enter the number of moves: ")
	numMoves, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Creating an array of Box objects with size numBoxes
	boxes := make([]Box, numBoxes)

	// Initializing the first box with red color
	boxes[0] = Box{1, true, 0}

	// Initializing the remaining boxes with red color set to false
	for i := 1; i < numBoxes; i++ {
		boxes[i] = Box{1, false, 0}
	}

	// Reading the moves from the user and performing them on the boxes
	for i := 0; i < numMoves; i++ {
		fmt.Print("Enter the source box: ")
		source, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		fmt.Print("Enter the destination box: ")
		dest, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		boxes[source-1].moveTo(boxes[dest-1])
	}

	// Counting the number of red boxes
	counter := 0
	for _, box := range boxes {
		if box.red {
			counter++
		}
	}

	// Printing the result
	fmt.Println(counter)
}

// Defining the moveTo method for moving the box to another box
func (b *Box) moveTo(other *Box) {
	if b.num == 0 { // If the current box is empty
		return // Do nothing
	} else if b.num == 1 { // If the current box has only one item
		b.num = 0 // Setting the current box to be empty
		other.num++ // Incrementing the number of items in the other box
		if b.red { // If the current box was red
			other.red = true // Setting the other box to be red
		}
		b.red = false // Setting the current box to be empty and not red
	} else { // If the current box has more than one item
		b.num-- // Decrementing the number of items in the current box
		other.num++ // Incrementing the number of items in the other box
		if b.red { // If the current box was red
			other.red = true // Setting the other box to be red
		}
	}
}

