
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define long long type alias for convenience
type lint int64

// Constants for large values and mathematical constants
const (
	INF = 1001001001001001
	inf = 1000000007
	MOD = 1000000007
	PI  = 3.1415926535897932
)

// Function to update the minimum value
func chmin(a, b int) {
	if a > b {
		a = b
	}
}

// Function to update the maximum value
func chmax(a, b int) {
	if a < b {
		a = b
	}
}

// Macros for convenience in iterating through containers
func all(a []int) []int {
	return a[:]
}
func rall(a []int) []int {
	for i := len(a) - 1; i >= 0; i-- {
		yield a[i]
	}
}

// Function to read input from stdin
func read() (a []int) {
	var line string
	var err error
	if _, err = fmt.Scanln(&line); err!= nil {
		panic(err)
	}
	a = strings.Split(line, " ")
	for i := range a {
		a[i], err = strconv.Atoi(a[i])
		if err!= nil {
			panic(err)
		}
	}
	return
}

// Function to read input from stdin
func readInt() (a int) {
	var line string
	var err error
	if _, err = fmt.Scanln(&line); err!= nil {
		panic(err)
	}
	a, err = strconv.Atoi(line)
	if err!= nil {
		panic(err)
	}
	return
}

// Function to read input from stdin
func readIntSlice() (a []int) {
	var line string
	var err error
	if _, err = fmt.Scanln(&line); err!= nil {
		panic(err)
	}
	a = strings.Split(line, " ")
	for i := range a {
		a[i], err = strconv.Atoi(a[i])
		if err!= nil {
			panic(err)
		}
	}
	return
}

// Function to read input from stdin
func readInt64() (a int64) {
	var line string
	var err error
	if _, err = fmt.Scanln(&line); err!= nil {
		panic(err)
	}
	a, err = strconv.ParseInt(line, 10, 64)
	if err!= nil {
		panic(err)
	}
	return
}

// Function to read input from stdin
func readInt64Slice() (a []int64) {
	var line string
	var err error
	if _, err = fmt.Scanln(&line); err!= nil {
		panic(err)
	}
	a = strings.Split(line, " ")
	for i := range a {
		a[i], err = strconv.ParseInt(a[i], 10, 64)
		if err!= nil {
			panic(err)
		}
	}
	return
}

// Function to read input from stdin
func readFloat64() (a float64) {
	var line string
	var err error
	if _, err = fmt.Scanln(&line); err!= nil {
		panic(err)
	}
	a, err = strconv.ParseFloat(line, 64)
	if err!= nil {
		panic(err)
	}
	return
}

// Function to read input from stdin
func readFloat64Slice() (a []float64) {
	var line string
	var err error
	if _, err = fmt.Scanln(&line); err!= nil {
		panic(err)
	}
	a = strings.Split(line, " ")
	for i := range a {
		a[i], err = strconv.ParseFloat(a[i], 64)
		if err!= nil {
			panic(err)
		}
	}
	return
}

// Function to read input from stdin
func readRuneSlice() (a []rune) {
	var line string
	var err error
	if _, err = fmt.Scanln(&line); err!= nil {
		panic(err)
	}
	a = []rune(line)
	return
}

// Function to read input from stdin
func readRune() (a rune) {
	var line string
	var err error
	if _, err = fmt.Scanln(&line); err!= nil {
		panic(err)
	}
	a, _, err = utf8.DecodeRuneInString(line)
	if err!= nil {
		panic(err)
	}
	return
}

// Function to read input from stdin
func readString() (a string) {
	var line string
	var err error
	if _, err = fmt.Scanln(&line); err!= nil {
		panic(err)
	}
	a = line
	return
}

// Function to read input from stdin
func readStringSlice() (a []string) {
	var line string
	var err error
	if _, err = fmt.Scanln(&line); err!= nil {
		panic(err)
	}
	a = strings.Split(line, " ")
	return
}

// Function to read input from stdin
func readBytes() (a []byte) {
	var line string
	var err error
	if _, err = fmt.Scanln(&line); err!= nil {
		panic(err)
	}
	a = []byte(line)
	return
}

// Function to read input from stdin
func readBytesSlice() (a [][]byte) {
	var line string
	var err error
	if _, err = fmt.Scanln(&line); err!= nil {
		panic(err)
	}
	a = bytes.Split([]byte(line), []byte(" "))
	return
}

// Function to read input from stdin
func readLines(n int) (a []string) {
	var line string
	var err error
	a = make([]string, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = line
	}
	return
}

// Function to read input from stdin
func readLinesBytes(n int) (a [][]byte) {
	var line string
	var err error
	a = make([][]byte, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = []byte(line)
	}
	return
}

// Function to read input from stdin
func readLinesRune(n int) (a [][]rune) {
	var line string
	var err error
	a = make([][]rune, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = []rune(line)
	}
	return
}

// Function to read input from stdin
func readLinesString(n int) (a []string) {
	var line string
	var err error
	a = make([]string, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = line
	}
	return
}

// Function to read input from stdin
func readLinesStringSlice(n int) (a []string) {
	var line string
	var err error
	a = make([]string, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = strings.Split(line, " ")
	}
	return
}

// Function to read input from stdin
func readLinesBytesSlice(n int) (a []string) {
	var line string
	var err error
	a = make([]string, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = bytes.Split([]byte(line), []byte(" "))
	}
	return
}

// Function to read input from stdin
func readLinesRuneSlice(n int) (a []string) {
	var line string
	var err error
	a = make([]string, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = []rune(line)
	}
	return
}

// Function to read input from stdin
func readLinesInt(n int) (a []int) {
	var line string
	var err error
	a = make([]int, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i], err = strconv.Atoi(line)
		if err!= nil {
			panic(err)
		}
	}
	return
}

// Function to read input from stdin
func readLinesIntSlice(n int) (a []int) {
	var line string
	var err error
	a = make([]int, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = strings.Split(line, " ")
	}
	return
}

// Function to read input from stdin
func readLinesInt64(n int) (a []int64) {
	var line string
	var err error
	a = make([]int64, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i], err = strconv.ParseInt(line, 10, 64)
		if err!= nil {
			panic(err)
		}
	}
	return
}

// Function to read input from stdin
func readLinesInt64Slice(n int) (a []int64) {
	var line string
	var err error
	a = make([]int64, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = strings.Split(line, " ")
	}
	return
}

// Function to read input from stdin
func readLinesFloat64(n int) (a []float64) {
	var line string
	var err error
	a = make([]float64, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i], err = strconv.ParseFloat(line, 64)
		if err!= nil {
			panic(err)
		}
	}
	return
}

// Function to read input from stdin
func readLinesFloat64Slice(n int) (a []float64) {
	var line string
	var err error
	a = make([]float64, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = strings.Split(line, " ")
	}
	return
}

// Function to read input from stdin
func readLinesRune(n int) (a []rune) {
	var line string
	var err error
	a = make([]rune, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i], _, err = utf8.DecodeRuneInString(line)
		if err!= nil {
			panic(err)
		}
	}
	return
}

// Function to read input from stdin
func readLinesRuneSlice(n int) (a []rune) {
	var line string
	var err error
	a = make([]rune, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = []rune(line)
	}
	return
}

// Function to read input from stdin
func readLinesString(n int) (a []string) {
	var line string
	var err error
	a = make([]string, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = line
	}
	return
}

// Function to read input from stdin
func readLinesStringSlice(n int) (a []string) {
	var line string
	var err error
	a = make([]string, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = strings.Split(line, " ")
	}
	return
}

// Function to read input from stdin
func readLinesBytes(n int) (a []byte) {
	var line string
	var err error
	a = make([]byte, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = []byte(line)
	}
	return
}

// Function to read input from stdin
func readLinesBytesSlice(n int) (a []byte) {
	var line string
	var err error
	a = make([]byte, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = bytes.Split([]byte(line), []byte(" "))
	}
	return
}

// Function to read input from stdin
func readLinesBytes(n int) (a []byte) {
	var line string
	var err error
	a = make([]byte, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = []byte(line)
	}
	return
}

// Function to read input from stdin
func readLinesBytesSlice(n int) (a []byte) {
	var line string
	var err error
	a = make([]byte, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = bytes.Split([]byte(line), []byte(" "))
	}
	return
}

// Function to read input from stdin
func readLinesBytes(n int) (a []byte) {
	var line string
	var err error
	a = make([]byte, n)
	for i := 0; i < n; i++ {
		if _, err = fmt.Scanln(&line); err!= nil {
			panic(err)
		}
		a[i] = []byte(line)
	}
	return
}

// Function to read input from stdin
func readLinesBytesSlice(n int) (a []byte) {
	var line string
	var err error
	a = make([]byte, n)
	for i := 0; i < n; i++ {
		if _, err 