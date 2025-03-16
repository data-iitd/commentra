package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// TaskB...
type TaskB struct {
}

// NewTaskB...
func NewTaskB() *TaskB {
	return &TaskB{}
}

// Solve...
func (t *TaskB) Solve(testNumber int, input *InputReader, output *bufio.Writer) {
	// Read the input string
	x := input.ReadString()
	// Initialize a stack to keep track of characters
	s := make([]rune, 0)
	// Initialize a counter to count balanced pairs
	c := 0
	// Iterate through each character in the input string
	for i := 0; i < len(x); i++ {
		// Push the current character onto the stack
		s = append(s, x[i])
		// While the stack has more than one element, check for balanced pairs
		for len(s) > 1 {
			// Pop the top two elements from the stack
			p := s[len(s)-1]
			q := s[len(s)-2]
			// Check if they form a balanced pair
			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				// Increment the counter if a balanced pair is found
				c++
				continue
			} else {
				// If not a balanced pair, push the popped elements back onto the stack
				s = append(s, q)
				s = append(s, p)
				break
			}
		}
	}
	// Output the result, which is twice the counter value
	output.WriteString(fmt.Sprintf("%d\n", c*2))
}

// Input...
type Input struct {
	In chan string
}

// ReadString...
func (i *Input) ReadString() string {
	return <-i.In
}

// ReadInt...
func (i *Input) ReadInt() int {
	a, _ := strconv.Atoi(<-i.In)
	return a
}

// ReadFloat...
func (i *Input) ReadFloat() float64 {
	a, _ := strconv.ParseFloat(<-i.In, 64)
	return a
}

// ReadPair...
func (i *Input) ReadPair() (int, int) {
	a, b := i.ReadPair2()
	return a, b
}

// ReadPair2...
func (i *Input) ReadPair2() (int, int) {
	a, _ := strconv.Atoi(<-i.In)
	b, _ := strconv.Atoi(<-i.In)
	return a, b
}

// ReadTriplet...
func (i *Input) ReadTriplet() (int, int, int) {
	a, b, _ := i.ReadTriplet3()
	return a, b, c
}

// ReadTriplet3...
func (i *Input) ReadTriplet3() (int, int, int) {
	a, _ := strconv.Atoi(<-i.In)
	b, _ := strconv.Atoi(<-i.In)
	c, _ := strconv.Atoi(<-i.In)
	return a, b, c
}

// ReadArray...
func (i *Input) ReadArray(f func(int) int) []int {
	l, _ := strconv.Atoi(<-i.In)
	a := make([]int, l)
	for j := 0; j < l; j++ {
		a[j] = f(j)
	}
	return a
}

// ReadArrayPair...
func (i *Input) ReadArrayPair(f func(int) int) []Pair {
	l, _ := strconv.Atoi(<-i.In)
	a := make([]Pair, l)
	for j := 0; j < l; j++ {
		a[j].First, a[j].Second = i.ReadPair()
	}
	return a
}

// ReadArrayTriplet...
func (i *Input) ReadArrayTriplet(f func(int) int) []Triplet {
	l, _ := strconv.Atoi(<-i.In)
	a := make([]Triplet, l)
	for j := 0; j < l; j++ {
		a[j].First, a[j].Second, a[j].Third = i.ReadTriplet()
	}
	return a
}

// InputReader...
type InputReader struct {
	In *Input
}

// NewInputReader...
func NewInputReader(in *Input) *InputReader {
	return &InputReader{In: in}
}

// ReadString...
func (i *InputReader) ReadString() string {
	return i.In.ReadString()
}

// ReadInt...
func (i *InputReader) ReadInt() int {
	return i.In.ReadInt()
}

// ReadFloat...
func (i *InputReader) ReadFloat() float64 {
	return i.In.ReadFloat()
}

// ReadPair...
func (i *InputReader) ReadPair() (int, int) {
	return i.In.ReadPair()
}

// ReadPair2...
func (i *InputReader) ReadPair2() (int, int) {
	return i.In.ReadPair2()
}

// ReadTriplet...
func (i *InputReader) ReadTriplet() (int, int, int) {
	return i.In.ReadTriplet()
}

// ReadTriplet3...
func (i *InputReader) ReadTriplet3() (int, int, int) {
	return i.In.ReadTriplet3()
}

// ReadArray...
func (i *InputReader) ReadArray(f func(int) int) []int {
	return i.In.ReadArray(f)
}

// ReadArrayPair...
func (i *InputReader) ReadArrayPair(f func(int) int) []Pair {
	return i.In.ReadArrayPair(f)
}

// ReadArrayTriplet...
func (i *InputReader) ReadArrayTriplet(f func(int) int) []Triplet {
	return i.In.ReadArrayTriplet(f)
}

// Output...
type Output struct {
	Out chan string
}

// WriteString...
func (o *Output) WriteString(s string) {
	o.Out <- s
}

// WriteInt...
func (o *Output) WriteInt(a int) {
	o.Out <- strconv.Itoa(a)
}

// WriteFloat...
func (o *Output) WriteFloat(a float64) {
	o.Out <- strconv.FormatFloat(a, 'f', -1, 64)
}

// WritePair...
func (o *Output) WritePair(a, b int) {
	o.Out <- strconv.Itoa(a)
	o.Out <- strconv.Itoa(b)
}

// WriteTriplet...
func (o *Output) WriteTriplet(a, b, c int) {
	o.Out <- strconv.Itoa(a)
	o.Out <- strconv.Itoa(b)
	o.Out <- strconv.Itoa(c)
}

// WriteArray...
func (o *Output) WriteArray(a []int) {
	o.Out <- strconv.Itoa(len(a))
	for j := 0; j < len(a); j++ {
		o.Out <- strconv.Itoa(a[j])
	}
}

// WriteArrayPair...
func (o *Output) WriteArrayPair(a []Pair) {
	o.Out <- strconv.Itoa(len(a))
	for j := 0; j < len(a); j++ {
		o.Out <- strconv.Itoa(a[j].First)
		o.Out <- strconv.Itoa(a[j].Second)
	}
}

// WriteArrayTriplet...
func (o *Output) WriteArrayTriplet(a []Triplet) {
	o.Out <- strconv.Itoa(len(a))
	for j := 0; j < len(a); j++ {
		o.Out <- strconv.Itoa(a[j].First)
		o.Out <- strconv.Itoa(a[j].Second)
		o.Out <- strconv.Itoa(a[j].Third)
	}
}

// OutputWriter...
type OutputWriter struct {
	Out *Output
}

// NewOutputWriter...
func NewOutputWriter(out *Output) *OutputWriter {
	return &OutputWriter{Out: out}
}

// WriteString...
func (o *OutputWriter) WriteString(s string) {
	o.Out.WriteString(s)
}

// WriteInt...
func (o *OutputWriter) WriteInt(a int) {
	o.Out.WriteInt(a)
}

// WriteFloat...
func (o *OutputWriter) WriteFloat(a float64) {
	o.Out.WriteFloat(a)
}

// WritePair...
func (o *OutputWriter) WritePair(a, b int) {
	o.Out.WritePair(a, b)
}

// WriteTriplet...
func (o *OutputWriter) WriteTriplet(a, b, c int) {
	o.Out.WriteTriplet(a, b, c)
}

// WriteArray...
func (o *OutputWriter) WriteArray(a []int) {
	o.Out.WriteArray(a)
}

// WriteArrayPair...
func (o *OutputWriter) WriteArrayPair(a []Pair) {
	o.Out.WriteArrayPair(a)
}

// WriteArrayTriplet...
func (o *OutputWriter) WriteArrayTriplet(a []Triplet) {
	o.Out.WriteArrayTriplet(a)
}

// Run...
func (t *TaskB) Run(in chan string, out chan string) {
	var input Input
	var output Output
	input.In = in
	output.Out = out
	NewTaskB().Solve(0, NewInputReader(&input), NewOutputWriter(&output))
}

// Run...
func Run(in chan string, out chan string) {
	NewTaskB().Run(in, out)
}

// 