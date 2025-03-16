
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	B := make([]Box, N)
	B[0] = Box{1, true}
	for i := 1; i < N; i++ {
		B[i] = Box{1, false}
	}
	for i := 0; i < M; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		x--
		y--
		B[x].moveTo(B[y])
	}
	counter := 0
	for _, b := range B {
		if b.red {
			counter++
		}
	}
	fmt.Println(counter)
}

type Box struct {
	num  int
	red  bool
}

func (b *Box) moveTo(other Box) {
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

