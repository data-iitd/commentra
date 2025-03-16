package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	input := NewFastScanner()
	n := input.nextInt()
	mapa := make(map[int]int)
	for i := 0; i < n; i++ {
		val := input.nextInt()
		mapa[val] = mapa[val] + 1
	}
	max := -1 << 31
	for _, value := range mapa {
		if value > max {
			max = value
		}
	}
	fmt.Println(strconv.Itoa(max) + " " + strconv.Itoa(len(mapa)))
}

type FastScanner struct {
	sc *bufio.Scanner
}

func NewFastScanner() *FastScanner {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	return &FastScanner{sc: sc}
}

func (s *FastScanner) next() string {
	s.sc.Scan()
	return s.sc.Text()
}

func (s *FastScanner) nextInt() int {
	i, _ := strconv.Atoi(s.next())
	return i
}

func (s *FastScanner) nextLong() int64 {
	i, _ := strconv.ParseInt(s.next(), 10, 64)
	return i
}

func (s *FastScanner) nextDouble() float64 {
	i, _ := strconv.ParseFloat(s.next(), 64)
	return i
}

func (s *FastScanner) nextLine() string {
	s.sc.Scan()
	return s.sc.Text()
}

