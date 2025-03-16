package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type FastReader struct {
	scanner *bufio.Scanner
}

func NewFastReader() *FastReader {
	return &FastReader{scanner: bufio.NewScanner(os.Stdin)}
}

func (fr *FastReader) Next() string {
	fr.scanner.Scan()
	return fr.scanner.Text()
}

func (fr *FastReader) NextInt() int {
	val, _ := strconv.Atoi(fr.Next())
	return val
}

func solve() {
	fr := NewFastReader()
	t := fr.NextInt()
	arr := make([]int, t)

	for i := 0; i < t; i++ {
		arr[i] = fr.NextInt()
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

func main() {
	solve()
}

// <END-OF-CODE>
