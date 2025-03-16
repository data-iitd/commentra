
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// FastReader is a custom struct for reading input efficiently
type FastReader struct {
	r *bufio.Reader
}

// NewFastReader returns a new instance of FastReader
func NewFastReader() *FastReader {
	return &FastReader{r: bufio.NewReader(os.Stdin)}
}

// ReadString reads a string from the input
func (f *FastReader) ReadString() string {
	line, _ := f.r.ReadString('\n')
	return strings.TrimSpace(line)
}

// ReadInt reads an integer from the input
func (f *FastReader) ReadInt() int {
	n, _ := strconv.Atoi(f.ReadString())
	return n
}

// ReadLong reads a long integer from the input
func (f *FastReader) ReadLong() int64 {
	n, _ := strconv.ParseInt(f.ReadString(), 10, 64)
	return n
}

// ReadDouble reads a double from the input
func (f *FastReader) ReadDouble() float64 {
	n, _ := strconv.ParseFloat(f.ReadString(), 64)
	return n
}

// ReadLine reads a line from the input
func (f *FastReader) ReadLine() string {
	line, _ := f.r.ReadString('\n')
	return line
}

// ReadLines reads multiple lines from the input
func (f *FastReader) ReadLines() []string {
	var lines []string
	for {
		line := f.ReadLine()
		if line == "" {
			break
		}
		lines = append(lines, line)
	}
	return lines
}

// ReadInts reads multiple integers from the input
func (f *FastReader) ReadInts() []int {
	var ints []int
	for {
		n := f.ReadInt()
		if n == 0 {
			break
		}
		ints = append(ints, n)
	}
	return ints
}

// ReadLongs reads multiple long integers from the input
func (f *FastReader) ReadLongs() []int64 {
	var longs []int64
	for {
		n := f.ReadLong()
		if n == 0 {
			break
		}
		longs = append(longs, n)
	}
	return longs
}

// ReadDoubles reads multiple doubles from the input
func (f *FastReader) ReadDoubles() []float64 {
	var doubles []float64
	for {
		n := f.ReadDouble()
		if n == 0 {
			break
		}
		doubles = append(doubles, n)
	}
	return doubles
}

// ReadLinesAsInts reads multiple lines from the input and converts them to integers
func (f *FastReader) ReadLinesAsInts() []int {
	lines := f.ReadLines()
	var ints []int
	for _, line := range lines {
		n, _ := strconv.Atoi(line)
		ints = append(ints, n)
	}
	return ints
}

// ReadLinesAsLongs reads multiple lines from the input and converts them to long integers
func (f *FastReader) ReadLinesAsLongs() []int64 {
	lines := f.ReadLines()
	var longs []int64
	for _, line := range lines {
		n, _ := strconv.ParseInt(line, 10, 64)
		longs = append(longs, n)
	}
	return longs
}

// ReadLinesAsDoubles reads multiple lines from the input and converts them to doubles
func (f *FastReader) ReadLinesAsDoubles() []float64 {
	lines := f.ReadLines()
	var doubles []float64
	for _, line := range lines {
		n, _ := strconv.ParseFloat(line, 64)
		doubles = append(doubles, n)
	}
	return doubles
}

// Println prints a line to the output
func Println(a ...interface{}) {
	fmt.Println(a...)
}

// Printf prints a formatted string to the output
func Printf(format string, a ...interface{}) {
	fmt.Printf(format, a...)
}

// Print prints a string to the output
func Print(a ...interface{}) {
	fmt.Print(a...)
}

// Printlnf prints a formatted string to the output
func Printlnf(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// PrintfLine prints a formatted string to the output
func PrintfLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnln prints a line to the output
func Printlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLine prints a formatted string to the output
func PrintlnfLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnln prints a line to the output
func Printlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLine prints a formatted string to the output
func PrintlnfLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnln prints a line to the output
func Printlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLine prints a formatted string to the output
func PrintlnfLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnlnlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnlnlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLineLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnlnlnlnlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnlnlnlnlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLineLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLineLineLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLineLineLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLineLineLineLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLineLineLineLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLineLineLineLineLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLineLineLineLineLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLineLineLineLineLineLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLineLineLineLineLineLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLineLineLineLineLineLineLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLineLineLineLineLineLineLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLineLineLineLineLineLineLineLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLineLineLineLineLineLineLineLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLineLineLineLineLineLineLineLineLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLineLineLineLineLineLineLineLineLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLineLineLineLineLineLineLineLineLineLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLineLineLineLineLineLineLineLineLineLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLineLineLineLineLineLineLineLineLineLineLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLineLineLineLineLineLineLineLineLineLineLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLineLineLineLineLineLineLineLineLineLineLineLineLineLine(format string, a ...interface{}) {
	fmt.Printf(format+"\n", a...)
}

// Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln prints a line to the output
func Printlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnlnln(a ...interface{}) {
	fmt.Println(a...)
}

// PrintlnfLineLineLineLineLineLineLineLineLineLineLineLineLineLineLineLineLineLine prints a formatted string to the output
func PrintlnfLineLineLineLineLineLineLineLineLineLineLineLineLineLineLineLineLineLi