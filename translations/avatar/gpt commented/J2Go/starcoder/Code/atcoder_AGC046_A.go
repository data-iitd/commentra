package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader is a wrapper around bufio.Reader.
// It provides convenient read methods without needing to specify the type of
// the variable to read.
type FastReader struct {
	r *bufio.Reader
}

// NewFastReader returns a FastReader instance.
func NewFastReader(r *bufio.Reader) *FastReader {
	return &FastReader{r: r}
}

// ReadString reads the input string.
func (f *FastReader) ReadString() string {
	s, _ := f.r.ReadString('\n')
	return strings.TrimRight(s, "\r\n")
}

// ReadInt reads the input integer.
func (f *FastReader) ReadInt() int {
	i, _ := strconv.Atoi(f.ReadString())
	return i
}

// ReadInt64 reads the input integer.
func (f *FastReader) ReadInt64() int64 {
	i, _ := strconv.ParseInt(f.ReadString(), 10, 64)
	return i
}

// ReadFloat reads the input float.
func (f *FastReader) ReadFloat() float64 {
	i, _ := strconv.ParseFloat(f.ReadString(), 64)
	return i
}

// ReadStringSlice reads the input string slice.
func (f *FastReader) ReadStringSlice() []string {
	var line string
	var strs []string
	line, _ = f.r.ReadString('\n')
	for _, s := range strings.Split(strings.TrimRight(line, "\r\n"), " ") {
		strs = append(strs, s)
	}
	return strs
}

func main() {
	// uncomment the below line to read input from a file
	// f := FastReader{bufio.NewReader(os.Stdin)}
	f := NewFastReader(bufio.NewReader(os.Stdin))
	x := f.ReadInt()
	count := 0
	tmp := x
	x = 0
	for x!= 360 {
		x = x + tmp
		if x > 360 {
			x = x - 360
		}
		count++
	}
	fmt.Println(count)
}

