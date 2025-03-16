package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

type FastScanner struct {
	sc *bufio.Scanner
}

func NewFastScanner(input io.Reader) *FastScanner {
	sc := bufio.NewScanner(input)
	sc.Split(bufio.ScanWords)
	return &FastScanner{sc: sc}
}

func (fs *FastScanner) next() string {
	fs.sc.Scan()
	return fs.sc.Text()
}

func (fs *FastScanner) nextInt() int {
	i, _ := strconv.Atoi(fs.next())
	return i
}

func (fs *FastScanner) nextLong() int64 {
	i, _ := strconv.ParseInt(fs.next(), 10, 64)
	return i
}

func (fs *FastScanner) nextDouble() float64 {
	i, _ := strconv.ParseFloat(fs.next(), 64)
	return i
}

func (fs *FastScanner) nextLine() string {
	fs.sc.Scan()
	return fs.sc.Text()
}

func main() {
	input := NewFastScanner(os.Stdin)
	n := input.nextInt()

	mapa := make(map[int]int)

	for i := 0; i < n; i++ {
		val := input.nextInt()
		mapa[val]++
	}

	max := 0
	for _, value := range mapa {
		if value > max {
			max = value
		}
	}

	fmt.Println(max, len(mapa))
}

