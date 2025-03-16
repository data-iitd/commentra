
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Box struct {
	num int
	red bool
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	M, _ := strconv.Atoi(sc.Text())
	B := make([]Box, N)
	B[0] = Box{1, true}
	for i := 1; i < N; i++ {
		B[i] = Box{1, false}
	}
	for i := 0; i < M; i++ {
		sc.Scan()
		x, _ := strconv.Atoi(sc.Text())
		sc.Scan()
		y, _ := strconv.Atoi(sc.Text())
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

