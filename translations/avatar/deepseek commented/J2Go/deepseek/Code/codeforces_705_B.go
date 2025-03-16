package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type FastReader struct {
	sc *bufio.Scanner
}

func NewFastReader() *FastReader {
	return &FastReader{sc: bufio.NewScanner(os.Stdin)}
}

func (r *FastReader) Next() string {
	r.sc.Scan()
	return r.sc.Text()
}

func (r *FastReader) NextInt() int {
	num, _ := strconv.Atoi(r.Next())
	return num
}

func (r *FastReader) NextLong() int64 {
	num, _ := strconv.ParseInt(r.Next(), 10, 64)
	return num
}

func (r *FastReader) NextDouble() float64 {
	num, _ := strconv.ParseFloat(r.Next(), 64)
	return num
}

func (r *FastReader) NextLine() string {
	r.sc.Scan()
	return r.sc.Text()
}

func main() {
	reader := NewFastReader()
	t := reader.NextInt()
	arr := make([]int, t)
	for i := 0; i < len(arr); i++ {
		arr[i] = reader.NextInt()
	}
	prevWinner := 0
	for i := 0; i < len(arr); i++ {
		if arr[i] == 1 {
			if prevWinner == 0 {
				prevWinner = 2
			}
		}
		if prevWinner == 2 || prevWinner == 0 {
			if (arr[i]-1)%2 == 0 {
				fmt.Println(2)
				prevWinner = 2
			} else {
				fmt.Println(1)
				prevWinner = 1
			}
		} else {
			if (arr[i]-1)%2 == 0 {
				fmt.Println(1)
				prevWinner = 1
			} else {
				fmt.Println(2)
				prevWinner = 2
			}
		}
	}
}
