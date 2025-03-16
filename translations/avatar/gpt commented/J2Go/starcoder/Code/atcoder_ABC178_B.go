package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader is a wrapper around bufio.Reader.
// It provides fast input reading in the form of strings.
type FastReader struct {
	r *bufio.Reader
}

// NewFastReader returns a new instance of FastReader.
func NewFastReader(r *bufio.Reader) *FastReader {
	return &FastReader{r: r}
}

// ReadString reads a line from the input,
// removes the trailing newline and returns it as a string.
func (f *FastReader) ReadString() string {
	s, _ := f.r.ReadString('\n')
	return strings.TrimSuffix(s, "\n")
}

// ReadInt reads a single integer from the input.
func (f *FastReader) ReadInt() int {
	i, _ := strconv.Atoi(f.ReadString())
	return i
}

// ReadLong reads a single integer from the input.
func (f *FastReader) ReadLong() int64 {
	i, _ := strconv.ParseInt(f.ReadString(), 10, 64)
	return i
}

// ReadFloat reads a single float from the input.
func (f *FastReader) ReadFloat() float64 {
	i, _ := strconv.ParseFloat(f.ReadString(), 64)
	return i
}

// ReadStringSlice reads a line from the input,
// removes the trailing newline and returns it as a slice of strings.
func (f *FastReader) ReadStringSlice() []string {
	return strings.Split(f.ReadString(), " ")
}

// ReadIntSlice reads a line from the input,
// removes the trailing newline and returns it as a slice of integers.
func (f *FastReader) ReadIntSlice() []int {
	slice := f.ReadStringSlice()
	var i []int
	for _, s := range slice {
		if s!= "" {
			if num, err := strconv.Atoi(s); err == nil {
				i = append(i, num)
			}
		}
	}
	return i
}

// ReadInt64Slice reads a line from the input,
// removes the trailing newline and returns it as a slice of integers.
func (f *FastReader) ReadInt64Slice() []int64 {
	slice := f.ReadStringSlice()
	var i []int64
	for _, s := range slice {
		if s!= "" {
			if num, err := strconv.ParseInt(s, 10, 64); err == nil {
				i = append(i, num)
			}
		}
	}
	return i
}

// ReadFloat64Slice reads a line from the input,
// removes the trailing newline and returns it as a slice of floats.
func (f *FastReader) ReadFloat64Slice() []float64 {
	slice := f.ReadStringSlice()
	var i []float64
	for _, s := range slice {
		if s!= "" {
			if num, err := strconv.ParseFloat(s, 64); err == nil {
				i = append(i, num)
			}
		}
	}
	return i
}

// ReadUint64Slice reads a line from the input,
// removes the trailing newline and returns it as a slice of uint64.
func (f *FastReader) ReadUint64Slice() []uint64 {
	slice := f.ReadStringSlice()
	var i []uint64
	for _, s := range slice {
		if s!= "" {
			if num, err := strconv.ParseUint(s, 10, 64); err == nil {
				i = append(i, num)
			}
		}
	}
	return i
}

// ReadInt64 reads a single integer from the input.
func (f *FastReader) ReadInt64() int64 {
	i, _ := strconv.ParseInt(f.ReadString(), 10, 64)
	return i
}

// ReadUint64 reads a single integer from the input.
func (f *FastReader) ReadUint64() uint64 {
	i, _ := strconv.ParseUint(f.ReadString(), 10, 64)
	return i
}

// ReadFloat64 reads a single float from the input.
func (f *FastReader) ReadFloat64() float64 {
	i, _ := strconv.ParseFloat(f.ReadString(), 64)
	return i
}

// ReadRune reads a single UTF-8 encoded Unicode character from the input.
func (f *FastReader) ReadRune() rune {
	ch, _, _ := f.r.ReadRune()
	return ch
}

// ReadByte reads a single byte from the input.
func (f *FastReader) ReadByte() byte {
	ch, _ := f.r.ReadByte()
	return ch
}

// ReadBool reads a single boolean value from the input.
func (f *FastReader) ReadBool() bool {
	s := f.ReadString()
	if s == "true" {
		return true
	}
	return false
}

// ReadIntN reads N integers from the input.
func (f *FastReader) ReadIntN(n int) []int {
	var i []int
	for j := 0; j < n; j++ {
		i = append(i, f.ReadInt())
	}
	return i
}

// ReadInt64N reads N integers from the input.
func (f *FastReader) ReadInt64N(n int) []int64 {
	var i []int64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadInt64())
	}
	return i
}

// ReadUint64N reads N integers from the input.
func (f *FastReader) ReadUint64N(n int) []uint64 {
	var i []uint64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadUint64())
	}
	return i
}

// ReadFloat64N reads N integers from the input.
func (f *FastReader) ReadFloat64N(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadRuneN reads N integers from the input.
func (f *FastReader) ReadRuneN(n int) []rune {
	var i []rune
	for j := 0; j < n; j++ {
		i = append(i, f.ReadRune())
	}
	return i
}

// ReadByteN reads N integers from the input.
func (f *FastReader) ReadByteN(n int) []byte {
	var i []byte
	for j := 0; j < n; j++ {
		i = append(i, f.ReadByte())
	}
	return i
}

// ReadBoolN reads N integers from the input.
func (f *FastReader) ReadBoolN(n int) []bool {
	var i []bool
	for j := 0; j < n; j++ {
		i = append(i, f.ReadBool())
	}
	return i
}

// ReadStrings reads lines from the input and returns them as a slice of strings.
func (f *FastReader) ReadStrings(n int) []string {
	var i []string
	for j := 0; j < n; j++ {
		i = append(i, f.ReadString())
	}
	return i
}

// ReadInts reads lines from the input and returns them as a slice of integers.
func (f *FastReader) ReadInts(n int) []int {
	var i []int
	for j := 0; j < n; j++ {
		i = append(i, f.ReadInt())
	}
	return i
}

// ReadInt64s reads lines from the input and returns them as a slice of integers.
func (f *FastReader) ReadInt64s(n int) []int64 {
	var i []int64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadInt64())
	}
	return i
}

// ReadUint64s reads lines from the input and returns them as a slice of integers.
func (f *FastReader) ReadUint64s(n int) []uint64 {
	var i []uint64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadUint64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadRunes reads lines from the input and returns them as a slice of runes.
func (f *FastReader) ReadRunes(n int) []rune {
	var i []rune
	for j := 0; j < n; j++ {
		i = append(i, f.ReadRune())
	}
	return i
}

// ReadBytes reads lines from the input and returns them as a slice of bytes.
func (f *FastReader) ReadBytes(n int) []byte {
	var i []byte
	for j := 0; j < n; j++ {
		i = append(i, f.ReadByte())
	}
	return i
}

// ReadBools reads lines from the input and returns them as a slice of bools.
func (f *FastReader) ReadBools(n int) []bool {
	var i []bool
	for j := 0; j < n; j++ {
		i = append(i, f.ReadBool())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

// ReadFloat64s reads lines from the input and returns them as a slice of floats.
func (f *FastReader) ReadFloat64s(n int) []float64 {
	var i []float64
	for j := 0; j < n; j++ {
		i = append(i, f.ReadFloat64())
	}
	return i
}

