package main

import (
	"fmt"
)

type Box struct {
	num  int
	red  bool
}

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	B := make([]Box, N)

	// Initializing the first box with red color
	B[0] = Box{num: 1, red: true}

	// Initializing the remaining boxes with red color set to false
	for i := 1; i < N; i++ {
		B[i] = Box{num: 1, red: false}
	}

	// Reading the moves from the user and performing them on the boxes
	for i := 0; i < M; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		B[x-1].moveTo(&B[y-1])
	}

	// Counting the number of red boxes
	counter := 0
	for _, b := range B {
		if b.red {
			counter++
		}
	}

	// Printing the result
	fmt.Println(counter)
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

