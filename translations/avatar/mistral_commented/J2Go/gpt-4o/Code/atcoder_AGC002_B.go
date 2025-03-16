package main

import (
	"fmt"
)

type Box struct {
	num int
	red bool
}

func (b *Box) moveTo(other *Box) {
	if b.num == 0 {
		return
	} else if b.num == 1 {
		b.num = 0
		other.num++
		if b.red {
			other.red = true
		}
		b.red = false
	} else {
		b.num--
		other.num++
		if b.red {
			other.red = true
		}
	}
}

func main() {
	var N, M int
	fmt.Scan(&N) // Reading the first integer input (number of boxes)
	fmt.Scan(&M) // Reading the second integer input (number of moves)

	B := make([]Box, N) // Creating a slice of Box objects with size N

	// Initializing the first box with red color
	B[0] = Box{1, true}

	// Initializing the remaining boxes with red color set to false
	for i := 1; i < N; i++ {
		B[i] = Box{1, false}
	}

	// Reading the moves from the user and performing them on the boxes
	for i := 0; i < M; i++ {
		var x, y int
		fmt.Scan(&x) // Reading the x-coordinate of the source box
		fmt.Scan(&y) // Reading the y-coordinate of the destination box
		B[x-1].moveTo(&B[y-1]) // Moving the box at index x to the box at index y
	}

	// Counting the number of red boxes
	counter := 0
	for _, b := range B { // Iterating through all the boxes in the slice
		if b.red { // If the current box has red color
			counter++ // Increment the counter
		}
	}

	// Printing the result
	fmt.Println(counter)
}

// <END-OF-CODE>
