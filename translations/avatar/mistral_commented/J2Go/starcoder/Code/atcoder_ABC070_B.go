
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// InputReader is a wrapper for the bufio.Reader
type InputReader struct {
	reader *bufio.Reader
}

// NewInputReader returns a new InputReader
func NewInputReader(reader *bufio.Reader) *InputReader {
	return &InputReader{reader: reader}
}

// ReadLine reads a line from the InputReader
func (reader *InputReader) ReadLine() (string, error) {
	return reader.reader.ReadString('\n')
}

// ReadInt reads an integer from the InputReader
func (reader *InputReader) ReadInt() (int, error) {
	str, err := reader.ReadLine()
	if err!= nil {
		return 0, err
	}
	return strconv.Atoi(str)
}

// ReadInts reads a slice of integers from the InputReader
func (reader *InputReader) ReadInts(n int) ([]int, error) {
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		str, err := reader.ReadLine()
		if err!= nil {
			return nil, err
		}
		ints[i], err = strconv.Atoi(str)
		if err!= nil {
			return nil, err
		}
	}
	return ints, nil
}

// ReadInt64s reads a slice of int64s from the InputReader
func (reader *InputReader) ReadInt64s(n int) ([]int64, error) {
	ints := make([]int64, n)
	for i := 0; i < n; i++ {
		str, err := reader.ReadLine()
		if err!= nil {
			return nil, err
		}
		ints[i], err = strconv.ParseInt(str, 10, 64)
		if err!= nil {
			return nil, err
		}
	}
	return ints, nil
}

// ReadFloats reads a slice of floats from the InputReader
func (reader *InputReader) ReadFloats(n int) ([]float64, error) {
	floats := make([]float64, n)
	for i := 0; i < n; i++ {
		str, err := reader.ReadLine()
		if err!= nil {
			return nil, err
		}
		floats[i], err = strconv.ParseFloat(str, 64)
		if err!= nil {
			return nil, err
		}
	}
	return floats, nil
}

// ReadStrings reads a slice of strings from the InputReader
func (reader *InputReader) ReadStrings(n int) ([]string, error) {
	strs := make([]string, n)
	for i := 0; i < n; i++ {
		str, err := reader.ReadLine()
		if err!= nil {
			return nil, err
		}
		strs[i] = str
	}
	return strs, nil
}

// ReadString reads a string from the InputReader
func (reader *InputReader) ReadString() (string, error) {
	str, err := reader.ReadLine()
	if err!= nil {
		return "", err
	}
	return str[:len(str)-1], nil
}

// ReadStringsLine reads a slice of strings from the InputReader
func (reader *InputReader) ReadStringsLine() ([]string, error) {
	str, err := reader.ReadLine()
	if err!= nil {
		return nil, err
	}
	return strings.Split(str, " "), nil
}

// ReadStringSlice reads a slice of strings from the InputReader
func (reader *InputReader) ReadStringSlice(n int) ([]string, error) {
	strs := make([]string, n)
	for i := 0; i < n; i++ {
		str, err := reader.ReadString()
		if err!= nil {
			return nil, err
		}
		strs[i] = str
	}
	return strs, nil
}

// ReadStringSliceLine reads a slice of strings from the InputReader
func (reader *InputReader) ReadStringSliceLine() ([]string, error) {
	strs, err := reader.ReadStringsLine()
	if err!= nil {
		return nil, err
	}
	return strs[:len(strs)-1], nil
}

// ReadFloat64Slice reads a slice of float64s from the InputReader
func (reader *InputReader) ReadFloat64Slice(n int) ([]float64, error) {
	floats := make([]float64, n)
	for i := 0; i < n; i++ {
		str, err := reader.ReadString()
		if err!= nil {
			return nil, err
		}
		floats[i], err = strconv.ParseFloat(str, 64)
		if err!= nil {
			return nil, err
		}
	}
	return floats, nil
}

// ReadFloat64SliceLine reads a slice of float64s from the InputReader
func (reader *InputReader) ReadFloat64SliceLine() ([]float64, error) {
	floats, err := reader.ReadFloat64Slice(len(reader.ReadStringSliceLine()))
	if err!= nil {
		return nil, err
	}
	return floats[:len(floats)-1], nil
}

// ReadInt64Slice reads a slice of int64s from the InputReader
func (reader *InputReader) ReadInt64Slice(n int) ([]int64, error) {
	ints := make([]int64, n)
	for i := 0; i < n; i++ {
		str, err := reader.ReadString()
		if err!= nil {
			return nil, err
		}
		ints[i], err = strconv.ParseInt(str, 10, 64)
		if err!= nil {
			return nil, err
		}
	}
	return ints, nil
}

// ReadInt64SliceLine reads a slice of int64s from the InputReader
func (reader *InputReader) ReadInt64SliceLine() ([]int64, error) {
	ints, err := reader.ReadInt64Slice(len(reader.ReadStringSliceLine()))
	if err!= nil {
		return nil, err
	}
	return ints[:len(ints)-1], nil
}

// ReadIntSlice reads a slice of ints from the InputReader
func (reader *InputReader) ReadIntSlice(n int) ([]int, error) {
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		str, err := reader.ReadString()
		if err!= nil {
			return nil, err
		}
		ints[i], err = strconv.Atoi(str)
		if err!= nil {
			return nil, err
		}
	}
	return ints, nil
}

// ReadIntSliceLine reads a slice of ints from the InputReader
func (reader *InputReader) ReadIntSliceLine() ([]int, error) {
	ints, err := reader.ReadIntSlice(len(reader.ReadStringSliceLine()))
	if err!= nil {
		return nil, err
	}
	return ints[:len(ints)-1], nil
}

// ReadFloat reads a float from the InputReader
func (reader *InputReader) ReadFloat() (float64, error) {
	str, err := reader.ReadLine()
	if err!= nil {
		return 0, err
	}
	return strconv.ParseFloat(str, 64)
}

// ReadFloatLine reads a float from the InputReader
func (reader *InputReader) ReadFloatLine() (float64, error) {
	str, err := reader.ReadString()
	if err!= nil {
		return 0, err
	}
	return strconv.ParseFloat(str, 64)
}

// ReadInt64 reads an int64 from the InputReader
func (reader *InputReader) ReadInt64() (int64, error) {
	str, err := reader.ReadLine()
	if err!= nil {
		return 0, err
	}
	return strconv.ParseInt(str, 10, 64)
}

// ReadInt64Line reads an int64 from the InputReader
func (reader *InputReader) ReadInt64Line() (int64, error) {
	str, err := reader.ReadString()
	if err!= nil {
		return 0, err
	}
	return strconv.ParseInt(str, 10, 64)
}

// ReadInt reads an int from the InputReader
func (reader *InputReader) ReadInt() (int, error) {
	str, err := reader.ReadLine()
	if err!= nil {
		return 0, err
	}
	return strconv.Atoi(str)
}

// ReadIntLine reads an int from the InputReader
func (reader *InputReader) ReadIntLine() (int, error) {
	str, err := reader.ReadString()
	if err!= nil {
		return 0, err
	}
	return strconv.Atoi(str)
}

// ReadString reads a string from the InputReader
func (reader *InputReader) ReadString() (string, error) {
	str, err := reader.ReadLine()
	if err!= nil {
		return "", err
	}
	return str[:len(str)-1], nil
}

// ReadStringLine reads a string from the InputReader
func (reader *InputReader) ReadStringLine() (string, error) {
	str, err := reader.ReadLine()
	if err!= nil {
		return "", err
	}
	return str[:len(str)-1], nil
}

// ReadStrings reads a slice of strings from the InputReader
func (reader *InputReader) ReadStrings(n int) ([]string, error) {
	strs := make([]string, n)
	for i := 0; i < n; i++ {
		str, err := reader.ReadLine()
		if err!= nil {
			return nil, err
		}
		strs[i] = str[:len(str)-1]
	}
	return strs, nil
}

// ReadStringSlice reads a slice of strings from the InputReader
func (reader *InputReader) ReadStringSlice(n int) ([]string, error) {
	strs := make([]string, n)
	for i := 0; i < n; i++ {
		str, err := reader.ReadString()
		if err!= nil {
			return nil, err
		}
		strs[i] = str
	}
	return strs, nil
}

// ReadFloat64Slice reads a slice of float64s from the InputReader
func (reader *InputReader) ReadFloat64Slice(n int) ([]float64, error) {
	floats := make([]float64, n)
	for i := 0; i < n; i++ {
		str, err := reader.ReadString()
		if err!= nil {
			return nil, err
		}
		floats[i], err = strconv.ParseFloat(str, 64)
		if err!= nil {
			return nil, err
		}
	}
	return floats, nil
}

// ReadInt64Slice reads a slice of int64s from the InputReader
func (reader *InputReader) ReadInt64Slice(n int) ([]int64, error) {
	ints := make([]int64, n)
	for i := 0; i < n; i++ {
		str, err := reader.ReadString()
		if err!= nil {
			return nil, err
		}
		ints[i], err = strconv.ParseInt(str, 10, 64)
		if err!= nil {
			return nil, err
		}
	}
	return ints, nil
}

// ReadIntSlice reads a slice of ints from the InputReader
func (reader *InputReader) ReadIntSlice(n int) ([]int, error) {
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		str, err := reader.ReadString()
		if err!= nil {
			return nil, err
		}
		ints[i], err = strconv.Atoi(str)
		if err!= nil {
			return nil, err
		}
	}
	return ints, nil
}

// ReadFloat reads a float from the InputReader
func (reader *InputReader) ReadFloat() (float64, error) {
	str, err := reader.ReadLine()
	if err!= nil {
		return 0, err
	}
	return strconv.ParseFloat(str, 64)
}

// ReadInt64 reads an int64 from the InputReader
func (reader *InputReader) ReadInt64() (int64, error) {
	str, err := reader.ReadLine()
	if err!= nil {
		return 0, err
	}
	return strconv.ParseInt(str, 10, 64)
}

// ReadInt reads an int from the InputReader
func (reader *InputReader) ReadInt() (int, error) {
	str, err := reader.ReadLine()
	if err!= nil {
		return 0, err
	}
	return strconv.Atoi(str)
}

// ReadString reads a string from the InputReader
func (reader *InputReader) ReadString() (string, error) {
	str, err := reader.ReadLine()
	if err!= nil {
		return "", err
	}
	return str[:len(str)-1], nil
}

// ReadStringsLine reads a slice of strings from the InputReader
func (reader *InputReader) ReadStringsLine() ([]string, error) {
	str, err := reader.ReadLine()
	if err!= nil {
		return nil, err
	}
	return strings.Split(str, " "), nil
}

// ReadStringSliceLine reads a slice of strings from the InputReader
func (reader *InputReader) ReadStringSliceLine() ([]string, error) {
	strs, err := reader.ReadStringsLine()
	if err!= nil {
		return nil, err
	}
	return strs[:len(strs)-1], nil
}

// ReadFloat64SliceLine reads a slice of float64s from the InputReader
func (reader *InputReader) ReadFloat64SliceLine() ([]float64, error) {
	floats, err := reader.ReadFloat64Slice(len(reader.ReadStringSliceLine()))
	if err!= nil {
		return nil, err
	}
	return floats[:len(floats)-1], nil
}

// ReadInt64SliceLine reads a slice of int64s from the InputReader
func 