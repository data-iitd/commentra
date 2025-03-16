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
		return // Do nothing if the box is already empty
	} else if b.num == 1 {
		b.num = 0 // Set the current box to empty
		other.num++ // Increment the destination box's number
		if b.red {
			other.red = true // If the current box was red, make the destination box red
		}
		b.red = false // The current box is no longer red
	} else {
		b.num-- // Decrement the current box's number
		other.num++ // Increment the destination box's number
		if b.red {
			other.red = true // If the current box was red, make the destination box red
		}
	}
}

func main() {
	var N, M int
	fmt.Scan(&N) // Read the number of boxes
	fmt.Scan(&M) // Read the number of moves
	B := make([]Box, N)
	B[0] = Box{1, true} // Initialize the first box with num=1 and red=true
	for i := 1; i < N; i++ {
		B[i] = Box{1, false} // Initialize the rest of the boxes with num=1 and red=false
	}
	for i := 0; i < M; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		x-- // Read the source box index (0-based)
		y-- // Read the destination box index (0-based)
		B[x].moveTo(&B[y]) // Move the box from source to destination
	}
	counter := 0
	for _, b := range B {
		if b.red {
			counter++ // Count the number of red boxes
		}
	}
	fmt.Println(counter) // Print the count of red boxes
}

