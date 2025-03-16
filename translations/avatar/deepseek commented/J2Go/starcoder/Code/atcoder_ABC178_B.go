package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// FastReader is a wrapper around bufio.Reader.
// It provides fast input reading in terms of both time and space.
type FastReader struct {
	r *bufio.Reader
}

// NewFastReader returns a FastReader instance.
func NewFastReader(r *bufio.Reader) *FastReader {
	return &FastReader{r: r}
}

// ReadLine returns a string containing the contents of a line without the ending newline character.
// The returned error is always nil, not EOF.
// If the input is completely empty, ReadLine returns an empty string and nil.
func (f *FastReader) ReadLine() (string, error) {
	s, err := f.r.ReadString('\n')
	if err!= nil {
		return s, err
	}
	if len(s) > 0 && s[len(s)-1] == '\n' {
		s = s[:len(s)-1]
	}
	return s, nil
}

// ReadInt returns an integer from the input, or an error.
func (f *FastReader) ReadInt() (int, error) {
	s, err := f.ReadLine()
	if err!= nil {
		return 0, err
	}
	i, err := strconv.Atoi(s)
	if err!= nil {
		return 0, err
	}
	return i, nil
}

// ReadLong returns a long integer from the input, or an error.
func (f *FastReader) ReadLong() (int64, error) {
	s, err := f.ReadLine()
	if err!= nil {
		return 0, err
	}
	i, err := strconv.ParseInt(s, 10, 64)
	if err!= nil {
		return 0, err
	}
	return i, nil
}

// ReadFloat returns a float from the input, or an error.
func (f *FastReader) ReadFloat() (float64, error) {
	s, err := f.ReadLine()
	if err!= nil {
		return 0, err
	}
	i, err := strconv.ParseFloat(s, 64)
	if err!= nil {
		return 0, err
	}
	return i, nil
}

// ReadString returns a string from the input, or an error.
func (f *FastReader) ReadString() (string, error) {
	s, err := f.ReadLine()
	if err!= nil {
		return "", err
	}
	return s, nil
}

// ReadStrings returns a slice of strings from the input, or an error.
func (f *FastReader) ReadStrings(n int) ([]string, error) {
	var ss []string
	for i := 0; i < n; i++ {
		s, err := f.ReadString()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, s)
	}
	return ss, nil
}

// ReadIntSlice returns a slice of integers from the input, or an error.
func (f *FastReader) ReadIntSlice(n int) ([]int, error) {
	var ss []int
	for i := 0; i < n; i++ {
		s, err := f.ReadInt()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, s)
	}
	return ss, nil
}

// ReadInt64Slice returns a slice of 64-bit integers from the input, or an error.
func (f *FastReader) ReadInt64Slice(n int) ([]int64, error) {
	var ss []int64
	for i := 0; i < n; i++ {
		s, err := f.ReadLong()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, s)
	}
	return ss, nil
}

// ReadFloat64Slice returns a slice of 64-bit floats from the input, or an error.
func (f *FastReader) ReadFloat64Slice(n int) ([]float64, error) {
	var ss []float64
	for i := 0; i < n; i++ {
		s, err := f.ReadFloat()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, s)
	}
	return ss, nil
}

// ReadFloat32Slice returns a slice of 32-bit floats from the input, or an error.
func (f *FastReader) ReadFloat32Slice(n int) ([]float32, error) {
	var ss []float32
	for i := 0; i < n; i++ {
		s, err := f.ReadFloat()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, float32(s))
	}
	return ss, nil
}

// ReadBoolSlice returns a slice of bools from the input, or an error.
func (f *FastReader) ReadBoolSlice(n int) ([]bool, error) {
	var ss []bool
	for i := 0; i < n; i++ {
		s, err := f.ReadString()
		if err!= nil {
			return nil, err
		}
		b, err := strconv.ParseBool(s)
		if err!= nil {
			return nil, err
		}
		ss = append(ss, b)
	}
	return ss, nil
}

// ReadStringSlice returns a slice of strings from the input, or an error.
func (f *FastReader) ReadStringSlice(n int) ([]string, error) {
	var ss []string
	for i := 0; i < n; i++ {
		s, err := f.ReadString()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, s)
	}
	return ss, nil
}

// ReadRuneSlice returns a slice of runes from the input, or an error.
func (f *FastReader) ReadRuneSlice(n int) ([]rune, error) {
	var ss []rune
	for i := 0; i < n; i++ {
		s, err := f.ReadString()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, []rune(s)[0])
	}
	return ss, nil
}

// ReadByteSlice returns a slice of bytes from the input, or an error.
func (f *FastReader) ReadByteSlice(n int) ([]byte, error) {
	var ss []byte
	for i := 0; i < n; i++ {
		s, err := f.ReadString()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, []byte(s)[0])
	}
	return ss, nil
}

// ReadUint64Slice returns a slice of 64-bit unsigned integers from the input, or an error.
func (f *FastReader) ReadUint64Slice(n int) ([]uint64, error) {
	var ss []uint64
	for i := 0; i < n; i++ {
		s, err := f.ReadLong()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, uint64(s))
	}
	return ss, nil
}

// ReadInt32Slice returns a slice of 32-bit integers from the input, or an error.
func (f *FastReader) ReadInt32Slice(n int) ([]int32, error) {
	var ss []int32
	for i := 0; i < n; i++ {
		s, err := f.ReadInt()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, int32(s))
	}
	return ss, nil
}

// ReadUint32Slice returns a slice of 32-bit unsigned integers from the input, or an error.
func (f *FastReader) ReadUint32Slice(n int) ([]uint32, error) {
	var ss []uint32
	for i := 0; i < n; i++ {
		s, err := f.ReadInt()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, uint32(s))
	}
	return ss, nil
}

// ReadInt16Slice returns a slice of 16-bit integers from the input, or an error.
func (f *FastReader) ReadInt16Slice(n int) ([]int16, error) {
	var ss []int16
	for i := 0; i < n; i++ {
		s, err := f.ReadInt()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, int16(s))
	}
	return ss, nil
}

// ReadUint16Slice returns a slice of 16-bit unsigned integers from the input, or an error.
func (f *FastReader) ReadUint16Slice(n int) ([]uint16, error) {
	var ss []uint16
	for i := 0; i < n; i++ {
		s, err := f.ReadInt()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, uint16(s))
	}
	return ss, nil
}

// ReadInt8Slice returns a slice of 8-bit integers from the input, or an error.
func (f *FastReader) ReadInt8Slice(n int) ([]int8, error) {
	var ss []int8
	for i := 0; i < n; i++ {
		s, err := f.ReadInt()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, int8(s))
	}
	return ss, nil
}

// ReadUint8Slice returns a slice of 8-bit unsigned integers from the input, or an error.
func (f *FastReader) ReadUint8Slice(n int) ([]uint8, error) {
	var ss []uint8
	for i := 0; i < n; i++ {
		s, err := f.ReadInt()
		if err!= nil {
			return nil, err
		}
		ss = append(ss, uint8(s))
	}
	return ss, nil
}

// ReadMapStringInt32 reads a map of string to 32-bit integer from the input, or an error.
func (f *FastReader) ReadMapStringInt32(n int) (map[string]int32, error) {
	m := make(map[string]int32)
	for i := 0; i < n; i++ {
		s, err := f.ReadString()
		if err!= nil {
			return nil, err
		}
		i, err := f.ReadInt()
		if err!= nil {
			return nil, err
		}
		m[s] = int32(i)
	}
	return m, nil
}

// ReadMapStringInt64 reads a map of string to 64-bit integer from the input, or an error.
func (f *FastReader) ReadMapStringInt64(n int) (map[string]int64, error) {
	m := make(map[string]int64)
	for i := 0; i < n; i++ {
		s, err := f.ReadString()
		if err!= nil {
			return nil, err
		}
		i, err := f.ReadLong()
		if err!= nil {
			return nil, err
		}
		m[s] = i
	}
	return m, nil
}

// ReadMapStringFloat64 reads a map of string to 64-bit float from the input, or an error.
func (f *FastReader) ReadMapStringFloat64(n int) (map[string]float64, error) {
	m := make(map[string]float64)
	for i := 0; i < n; i++ {
		s, err := f.ReadString()
		if err!= nil {
			return nil, err
		}
		i, err := f.ReadFloat()
		if err!= nil {
			return nil, err
		}
		m[s] = i
	}
	return m, nil
}

// ReadMapStringBool reads a map of string to bool from the input, or an error.
func (f *FastReader) ReadMapStringBool(n int) (map[string]bool, error) {
	m := make(map[string]bool)
	for i := 0; i < n; i++ {
		s, err := f.ReadString()
		if err!= nil {
			return nil, err
		}
		b, err := f.ReadBool()
		if err!= nil {
			return nil, err
		}
		m[s] = b
	}
	return m, nil
}

// ReadMapInt32Int32 reads a map of 32-bit integer to 32-bit integer from the input, or an error.
func (f *FastReader) ReadMapInt32Int32(n int) (map[int32]int32, error) {
	m := make(map[int32]int32)
	for i := 0; i < n; i++ {
		i, err := f.ReadInt()
		if err!= nil {
			return nil, err
		}
		j, err := f.ReadInt()
		if err!= nil {
			return nil, err
		}
		m[int32(i)] = int32(j)
	}
	return m, nil
}

// ReadMapInt64Int64 reads a map of 64-bit integer to 64-bit integer from the input, or an error.
func (f *FastReader) ReadMapInt64Int64(n int) (map[int64]int64, error) {
	m := make(map[int64]int64)
	for i := 0; i < n; i++ {
		i, err := f.ReadLong()
		if err!= nil {
			return nil, err
		}
		j, err := f.ReadLong()
		if err!= nil {
			return nil, err
		}
		m[i] = j
	}
	return m, nil
}

// ReadMapInt32Float64 reads a map of 32-bit integer to 64-bit float from the input, or an error.
func (f *FastReader) ReadMapInt32Float64(n int) (map[int32]float64, error) {
	m := make(map[int32]float64)
	for i := 0; i < n; i++ {
		i, err := f.ReadInt()
		if err!= nil {
			return nil, err
		}
		j, err := f.ReadFloat()
		if err!= nil {
			return nil, err
		}
		m[int32(i)] = j
	}
	return m, nil
}

// ReadMapInt32Bool reads a map of 32-bit integer to bool from the input, or an error.
func (f *FastReader) ReadMapInt32Bool(n int) (map[int32]bool, error) {
	m := make(map[int32]bool)
	for i := 0; i < n; i++ {
		i, err := f.ReadInt()
		if err!= nil {
			return nil, err
		}
		b, err := f.ReadBool()
		if err!= nil {
			return nil, err
		}
		m[int32(i)] = b
	}
	return m, nil
}

// ReadMapInt64Float64 reads a map of 64-bit integer to 64-bit float from the input, or an error.
func (f *FastReader) ReadMapInt64Float64(n int) (map[int64]float64, error) {
	m := make(map[int64]float64)
	for i := 0; i < n; i++ {
		i, err := f.ReadLong()
		if err!= nil {
			return nil, err
		}
		j, err := f.Read