package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader is a wrapper around bufio.Reader.
// It provides fast reading methods.
type FastReader struct {
	r *bufio.Reader
}

// NewFastReader returns a FastReader instance.
func NewFastReader(r *bufio.Reader) *FastReader {
	return &FastReader{r: r}
}

// ReadString reads a string.
func (f *FastReader) ReadString() string {
	var (
		isPrefix bool  = true
		err      error = nil
		line, ln []byte
	)
	for isPrefix && err == nil {
		line, isPrefix, err = f.r.ReadLine()
		ln = append(ln, line...)
	}
	return strings.TrimSpace(string(ln))
}

// ReadInt reads an integer.
func (f *FastReader) ReadInt() int {
	i, err := strconv.Atoi(f.ReadString())
	if err!= nil {
		panic(err)
	}
	return i
}

// ReadInt64 reads an integer.
func (f *FastReader) ReadInt64() int64 {
	i, err := strconv.ParseInt(f.ReadString(), 10, 64)
	if err!= nil {
		panic(err)
	}
	return i
}

// ReadFloat64 reads a float.
func (f *FastReader) ReadFloat64() float64 {
	i, err := strconv.ParseFloat(f.ReadString(), 64)
	if err!= nil {
		panic(err)
	}
	return i
}

// ReadStringSlice reads a string slice.
func (f *FastReader) ReadStringSlice() []string {
	var ss []string
	s := f.ReadString()
	for s!= "