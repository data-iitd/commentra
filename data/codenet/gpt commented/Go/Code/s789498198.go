package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
	"unsafe"
)

func main() {
	// Read two integers from input
	AB := sc.nextInts()
	A := AB[0]
	B := AB[1]

	// Check if the sum of A and B is even
	if (A+B)%2 == 0 {
		// If even, print the average
		fmt.Println((A + B) / 2)
		return
	}
	// If odd, print "IMPOSSIBLE"
	fmt.Println("IMPOSSIBLE")
}

var (
	// Initialize a scanner for reading input
	sc scanner
)

func init() {
	// Set up the scanner with a buffer and a reader
	sc = scanner{
		buf: make([]string, 0, 0),
		cur: 0,
		r:   bufio.NewReader(os.Stdin),
	}
}

// scanner struct to handle input reading
type scanner struct {
	buf []string // buffer to hold split input
	cur int      // current index in the buffer
	r   *bufio.Reader // reader for input
}

// readln reads a line from input and splits it into words
func (s *scanner) readln() {
	rbuf := make([]byte, 0, 0)
	for {
		line, prefix, err := s.r.ReadLine()
		if err != nil {
			panic(err) // handle read error
		}
		rbuf = append(rbuf, line...)
		if prefix == false {
			break // exit loop if line is complete
		}
	}
	// Split the read line into words and store in buffer
	s.cur = 0
	s.buf = strings.Split(*(*string)(unsafe.Pointer(&rbuf)), " ")
}

// isFull checks if the buffer is fully read
func (s *scanner) isFull() bool {
	return s.cur == len(s.buf)
}

// resetCur resets the current index to zero
func (s *scanner) resetCur() {
	s.cur = 0
}

// next returns the next string from the buffer
func (s *scanner) next() string {
	if s.cur == 0 {
		s.readln() // read a new line if current index is zero
	}
	res := s.buf[s.cur]
	s.cur++
	if s.isFull() {
		s.resetCur() // reset if buffer is full
	}
	return res
}

// nexts returns all strings from the current line
func (s *scanner) nexts() []string {
	s.readln() // read a new line
	s.resetCur() // reset current index
	return s.buf // return the buffer
}

// nextInt returns the next integer from the buffer
func (s *scanner) nextInt() int {
	if s.cur == 0 {
		s.readln() // read a new line if current index is zero
	}
	res, _ := strconv.Atoi(s.buf[s.cur]) // convert string to int
	s.cur++
	if s.isFull() {
		s.resetCur() // reset if buffer is full
	}
	return res
}

// nextInts returns all integers from the current line
func (s *scanner) nextInts() []int {
	s.readln() // read a new line
	res := make([]int, len(s.buf)) // create a slice for integers
	for i := range s.buf {
		res[i], _ = strconv.Atoi(s.buf[i]) // convert each string to int
	}
	s.resetCur() // reset current index
	return res // return the slice of integers
}

// nextFloat returns the next float from the buffer
func (s *scanner) nextFloat() float64 {
	if s.cur == 0 {
		s.readln() // read a new line if current index is zero
	}
	res, _ := strconv.ParseFloat(s.buf[s.cur], 64) // convert string to float
	s.cur++
	if s.isFull() {
		s.resetCur() // reset if buffer is full
	}
	return res
}

// nextFloats returns all floats from the current line
func (s *scanner) nextFloats() []float64 {
	s.readln() // read a new line
	res := make([]float64, len(s.buf)) // create a slice for floats
	for i := range s.buf {
		res[i], _ = strconv.ParseFloat(s.buf[i], 64) // convert each string to float
	}
	s.resetCur() // reset current index
	return res // return the slice of floats
}

// digits returns the number of digits in an integer
func digits(x int) int {
	return len(strconv.Itoa(x)) // convert int to string and return length
}

// powInt calculates x raised to the power of p
func powInt(x, p int) (result int) {
	result = 1
	for i := 0; i < p; i++ {
		result *= x // multiply result by x, p times
	}
	return
}

// max returns the maximum of two integers
func max(x, y int) int {
	return int(math.Max(float64(x), float64(y))) // use math.Max for comparison
}

// min returns the minimum of two integers
func min(x, y int) int {
	return int(math.Min(float64(x), float64(y))) // use math.Min for comparison
}

// abs returns the absolute value of an integer
func abs(x int) int {
	return int(math.Abs(float64(x))) // use math.Abs for absolute value
}

// varDump prints the values of variables for debugging
func varDump(value ...interface{}) {
	for _, v := range value {
		fmt.Fprintf(os.Stderr, "%#v\n", v) // print each value to stderr
	}
}

// yes prints "Yes" to the output
func yes() {
	fmt.Println("Yes")
}

// no prints "No" to the output
func no() {
	fmt.Println("No")
}

// Pair struct to hold a pair of integers
type Pair struct {
	first  int // first element of the pair
	second int // second element of the pair
}

// Queue struct to implement a queue of pairs
type Queue struct {
	v []Pair // slice to hold pairs
}

// Push adds a new pair to the queue
func (q *Queue) Push(v Pair) {
	q.v = append(q.v, v) // append the pair to the slice
}

// Pop removes and returns the front pair from the queue
func (q *Queue) Pop() Pair {
	r := q.v[0] // get the front pair
	q.v = q.v[1:] // remove the front pair from the slice
	return r // return the removed pair
}

// Front returns the front pair without removing it
func (q Queue) Front() Pair {
	return q.v[0] // return the front pair
}

// Empty checks if the queue is empty
func (q Queue) Empty() bool {
	return len(q.v) == 0 // return true if the slice is empty
}
