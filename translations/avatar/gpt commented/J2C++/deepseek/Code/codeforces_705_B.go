package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader struct to handle fast input
type FastReader struct {
	sc *bufio.Scanner
}

// NewFastReader creates a new FastReader instance
func NewFastReader() *FastReader {
	return &FastReader{sc: bufio.NewScanner(os.Stdin)}
}

// ReadString reads the next token from input
func (r *FastReader) ReadString() string {
	r.sc.Scan()
	return r.sc.Text()
}

// ReadInt reads the next integer from input
func (r *FastReader) ReadInt() int {
	num, _ := strconv.Atoi(r.ReadString())
	return num
}

// ReadFloat reads the next float from input
func (r *FastReader) ReadFloat() float64 {
	num, _ := strconv.ParseFloat(r.ReadString(), 64)
	return num
}

// ReadLine reads the next line from input
func (r *FastReader) ReadLine() string {
	return r.ReadString()
}

func main() {
	reader := NewFastReader()
	t := reader.ReadInt()
	arr := make([]int, t)

	for i := 0; i < t; i++ {
		arr[i] = reader.ReadInt()
	}

	prevWinner := 0

	for i := 0; i < t; i++ {
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
