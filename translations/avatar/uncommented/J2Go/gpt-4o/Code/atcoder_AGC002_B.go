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
	fmt.Scan(&N, &M)

	B := make([]Box, N)
	B[0] = Box{num: 1, red: true}
	for i := 1; i < N; i++ {
		B[i] = Box{num: 1, red: false}
	}

	for i := 0; i < M; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		B[x-1].moveTo(&B[y-1])
	}

	counter := 0
	for _, b := range B {
		if b.red {
			counter++
		}
	}
	fmt.Println(counter)
}

// <END-OF-CODE>
