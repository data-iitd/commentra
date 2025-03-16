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

// Initialize scanner and read the first line
func init() {
	sc = scanner{
		buf: make([]string, 0, 0),
		cur: 0,
		r:   bufio.NewReader(os.Stdin),
	}
	sc.readln() // Read the first line
}

// Main function
func main() {
	// Read the first two integers from the input
	AB := sc.nextInts()
	A := AB[0]
	B := AB[1]

	// Check if the sum of A and B is even
	if (A+B)%2 == 0 {
		// If it is, print the result (the average)
		fmt.Println((A + B) / 2)
		return
	}
	// If the sum is odd, print "IMPOSSIBLE"
	fmt.Println("IMPOSSIBLE")
}

// scanner type definition
type scanner struct {
	buf []string
	cur int
	r   *bufio.Reader
}

// Function to read a line
func (s *scanner) readln() {
	rbuf := make([]byte, 0, 0)
	for {
		line, prefix, err := s.r.ReadLine()
		if err != nil {
			panic(err)
		}
		rbuf = append(rbuf, line...)
		if prefix == false {
			break
		}
	}
	s.cur = 0
	s.buf = strings.Split(*(*string)(unsafe.Pointer(&rbuf)), " ")
}

// Function to check if the scanner is full
func (s *scanner) isFull() bool {
	if s.cur == len(s.buf) {
		return true
	}
	return false
}

// Function to reset the current index
func (s *scanner) resetCur() {
	s.cur = 0
}

// Function to read next string
func (s *scanner) next() string {
	if s.cur == 0 {
		s.readln()
	}
	res := s.buf[s.cur]
	s.cur++
	if s.isFull() {
		s.resetCur()
	}
	return res
}

// Function to read next integers
func (s *scanner) nextInts() []int {
	s.readln()
	res := make([]int, len(s.buf))
	for i := range s.buf {
		res[i], _ = strconv.Atoi(s.buf[i])
	}
	s.resetCur()
	return res
}

// Function to calculate the number of digits in an integer
func digits(x int) int {
	return len(strconv.Itoa(x))
}

// Function to calculate the power of a number
func powInt(x, p int) int {
	result := 1
	for i := 0; i < p; i++ {
		result *= x
	}
	return result
}

// Function to find the maximum of two integers
func max(x, y int) int {
	return int(math.Max(float64(x), float64(y)))
}

// Function to find the minimum of two integers
func min(x, y int) int {
	return int(math.Min(float64(x), float64(y)))
}

// Function to calculate the absolute value of an integer
func abs(x int) int {
	return int(math.Abs(float64(x)))
}

// Function to print the values of variables
func varDump(value ...interface{}) {
	for _, v := range value {
		fmt.Fprintf(os.Stderr, "%#v\n", v)
	}
}

// Function to print "Yes"
func yes() {
	fmt.Println("Yes")
}

// Function to print "No"
func no() {
	fmt.Println("No")
}

// Pair type definition
type Pair struct {
	first  int
	second int
}

// Queue type definition
type Queue struct {
	v []Pair
}

// Function to push a pair into the queue
func (q *Queue) Push(v Pair) {
	q.v = append(q.v, v)
}

// Function to pop a pair from the queue
func (q *Queue) Pop() Pair {
	r := q.v[0]
	q.v = q.v[1:]
	return r
}

// Function to get the front pair from the queue
func (q Queue) Front() Pair {
	return q.v[0]
}

// Function to check if the queue is empty
func (q Queue) Empty() bool {
	return len(q.v) == 0
}