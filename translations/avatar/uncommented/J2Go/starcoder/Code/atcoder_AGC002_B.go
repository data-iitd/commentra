package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Box struct {
	num  int
	red  bool
	next *Box
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of boxes")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString(byte('\n'))))
	fmt.Println("Enter the number of moves")
	M, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString(byte('\n'))))
	B := make([]Box, N)
	B[0] = Box{1, true, nil}
	for i := 1; i < N; i++ {
		B[i] = Box{1, false, nil}
	}
	for i := 0; i < M; i++ {
		x, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString(byte('\n'))))
		y, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString(byte('\n'))))
		B[x-1].moveTo(B[y-1])
	}
	counter := 0
	for _, b := range B {
		if b.red {
			counter++
		}
	}
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

