package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader is a wrapper around bufio.Reader.
// It provides fast input reading in the form of
// a space-delimited string of words.
type FastReader struct {
	r *bufio.Reader
}

// NewFastReader returns a new instance of FastReader.
func NewFastReader(r *bufio.Reader) *FastReader {
	return &FastReader{r: r}
}

// ReadWord returns the next word from the input,
// or an empty string if an error occurs.
func (f *FastReader) ReadWord() string {
	var (
		isPrefix bool  = true
		err      error = nil
		word     []byte
	)
	for isPrefix && err == nil {
		var b byte
		b, isPrefix, err = f.r.ReadRune()
		if!isPrefix {
			f.r.UnreadRune()
		}
		if b!='' {
			word = append(word, byte(b))
		}
	}
	return strings.TrimSpace(string(word))
}

// ReadInt returns the next integer from the input,
// or 0 if an error occurs.
func (f *FastReader) ReadInt() int {
	word := f.ReadWord()
	if word == "" {
		return 0
	}
	n, err := strconv.Atoi(word)
	if err!= nil {
		return 0
	}
	return n
}

func main() {
	reader := NewFastReader(bufio.NewReader(os.Stdin))
	t := reader.ReadInt()
	for i := 0; i < t; i++ {
		solve(reader)
	}
}

func solve(reader *FastReader) {
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
}

