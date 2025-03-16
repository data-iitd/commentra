
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize bufio.Scanner for input and bufio.Writer for output
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read the number of integers to process
	n, _ := strconv.Atoi(reader.Text())

	// Array to count occurrences of integers based on their bit count
	a := make([]int, 33)

	// Process each integer and count how many have the same number of set bits
	for i := 0; i < n; i++ {
		s := strings.Split(reader.Text(), " ")
		x, _ := strconv.ParseInt(s[0], 10, 64)
		a[rec(x)]++
	}

	// Variable to accumulate the final answer
	var answer float64

	// Calculate the contribution to the answer from each bit count
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]) - 1) / 2.0 * (float64(a[i]) - 1)
		answer += summ
	}

	// Print the final answer as a long integer
	fmt.Fprintln(writer, int64(answer))
	writer.Flush()
}

// Method to count the number of set bits (1s) in the binary representation of x
func rec(x int64) int {
	answer := 0
	// Iterate through each bit position from 31 to 0
	for k := 31; k >= 0; k-- {
		// Check if the k-th bit is set
		if x&(1<<uint(k))!= 0 {
			answer++
		}
	}
	return answer
}

//bufio.Scanner for efficient input reading
type Scanner struct {
	*bufio.Scanner
}

//bufio.Writer for efficient output writing
type Writer struct {
	*bufio.Writer
}

// Constructor to initialize bufio.Scanner
func NewScanner(r io.Reader) *Scanner {
	return &Scanner{bufio.NewScanner(r)}
}

// Constructor to initialize bufio.Writer
func NewWriter(w io.Writer) *Writer {
	return &Writer{bufio.NewWriter(w)}
}

// Method to read the next token as a String
func (s *Scanner) Text() string {
	s.Scan()
	return s.Text()
}

// Method to read the next token as an integer
func (s *Scanner) Int() int {
	v, _ := strconv.Atoi(s.Text())
	return v
}

// Method to read the next token as a long
func (s *Scanner) Long() int64 {
	v, _ := strconv.ParseInt(s.Text(), 10, 64)
	return v
}

// Method to read the next token as a double
func (s *Scanner) Double() float64 {
	v, _ := strconv.ParseFloat(s.Text(), 64)
	return v
}

// Method to read the next line as a String
func (s *Scanner) Line() string {
	line, _ := s.Scanner.ReadString('\n')
	return strings.TrimRight(line, "\r\n")
}

// Method to flush the output buffer
func (w *Writer) Flush() {
	w.Writer.Flush()
}

//bufio.Scanner for efficient input reading
type Scanner struct {
	*bufio.Scanner
}

//bufio.Writer for efficient output writing
type Writer struct {
	*bufio.Writer
}

// Constructor to initialize bufio.Scanner
func NewScanner(r io.Reader) *Scanner {
	return &Scanner{bufio.NewScanner(r)}
}

// Constructor to initialize bufio.Writer
func NewWriter(w io.Writer) *Writer {
	return &Writer{bufio.NewWriter(w)}
}

// Method to read the next token as a String
func (s *Scanner) Text() string {
	s.Scan()
	return s.Text()
}

// Method to read the next token as an integer
func (s *Scanner) Int() int {
	v, _ := strconv.Atoi(s.Text())
	return v
}

// Method to read the next token as a long
func (s *Scanner) Long() int64 {
	v, _ := strconv.ParseInt(s.Text(), 10, 64)
	return v
}

// Method to read the next token as a double
func (s *Scanner) Double() float64 {
	v, _ := strconv.ParseFloat(s.Text(), 64)
	return v
}

// Method to read the next line as a String
func (s *Scanner) Line() string {
	line, _ := s.Scanner.ReadString('\n')
	return strings.TrimRight(line, "\r\n")
}

// Method to flush the output buffer
func (w *Writer) Flush() {
	w.Writer.Flush()
}

//bufio.Scanner for efficient input reading
type Scanner struct {
	*bufio.Scanner
}

//bufio.Writer for efficient output writing
type Writer struct {
	*bufio.Writer
}

// Constructor to initialize bufio.Scanner
func NewScanner(r io.Reader) *Scanner {
	return &Scanner{bufio.NewScanner(r)}
}

// Constructor to initialize bufio.Writer
func NewWriter(w io.Writer) *Writer {
	return &Writer{bufio.NewWriter(w)}
}

// Method to read the next token as a String
func (s *Scanner) Text() string {
	s.Scan()
	return s.Text()
}

// Method to read the next token as an integer
func (s *Scanner) Int() int {
	v, _ := strconv.Atoi(s.Text())
	return v
}

// Method to read the next token as a long
func (s *Scanner) Long() int64 {
	v, _ := strconv.ParseInt(s.Text(), 10, 64)
	return v
}

// Method to read the next token as a double
func (s *Scanner) Double() float64 {
	v, _ := strconv.ParseFloat(s.Text(), 64)
	return v
}

// Method to read the next line as a String
func (s *Scanner) Line() string {
	line, _ := s.Scanner.ReadString('\n')
	return strings.TrimRight(line, "\r\n")
}

// Method to flush the output buffer
func (w *Writer) Flush() {
	w.Writer.Flush()
}

//bufio.Scanner for efficient input reading
type Scanner struct {
	*bufio.Scanner
}

//bufio.Writer for efficient output writing
type Writer struct {
	*bufio.Writer
}

// Constructor to initialize bufio.Scanner
func NewScanner(r io.Reader) *Scanner {
	return &Scanner{bufio.NewScanner(r)}
}

// Constructor to initialize bufio.Writer
func NewWriter(w io.Writer) *Writer {
	return &Writer{bufio.NewWriter(w)}
}

// Method to read the next token as a String
func (s *Scanner) Text() string {
	s.Scan()
	return s.Text()
}

// Method to read the next token as an integer
func (s *Scanner) Int() int {
	v, _ := strconv.Atoi(s.Text())
	return v
}

// Method to read the next token as a long
func (s *Scanner) Long() int64 {
	v, _ := strconv.ParseInt(s.Text(), 10, 64)
	return v
}

// Method to read the next token as a double
func (s *Scanner) Double() float64 {
	v, _ := strconv.ParseFloat(s.Text(), 64)
	return v
}

// Method to read the next line as a String
func (s *Scanner) Line() string {
	line, _ := s.Scanner.ReadString('\n')
	return strings.TrimRight(line, "\r\n")
}

// Method to flush the output buffer
func (w *Writer) Flush() {
	w.Writer.Flush()
}

//bufio.Scanner for efficient input reading
type Scanner struct {
	*bufio.Scanner
}

//bufio.Writer for efficient output writing
type Writer struct {
	*bufio.Writer
}

// Constructor to initialize bufio.Scanner
func NewScanner(r io.Reader) *Scanner {
	return &Scanner{bufio.NewScanner(r)}
}

// Constructor to initialize bufio.Writer
func NewWriter(w io.Writer) *Writer {
	return &Writer{bufio.NewWriter(w)}
}

// Method to read the next token as a String
func (s *Scanner) Text() string {
	s.Scan()
	return s.Text()
}

// Method to read the next token as an integer
func (s *Scanner) Int() int {
	v, _ := strconv.Atoi(s.Text())
	return v
}

// Method to read the next token as a long
func (s *Scanner) Long() int64 {
	v, _ := strconv.ParseInt(s.Text(), 10, 64)
	return v
}

// Method to read the next token as a double
func (s *Scanner) Double() float64 {
	v, _ := strconv.ParseFloat(s.Text(), 64)
	return v
}

// Method to read the next line as a String
func (s *Scanner) Line() string {
	line, _ := s.Scanner.ReadString('\n')
	return strings.TrimRight(line, "\r\n")
}

// Method to flush the output buffer
func (w *Writer) Flush() {
	w.Writer.Flush()
}

//bufio.Scanner for efficient input reading
type Scanner struct {
	*bufio.Scanner
}

//bufio.Writer for efficient output writing
type Writer struct {
	*bufio.Writer
}

// Constructor to initialize bufio.Scanner
func NewScanner(r io.Reader) *Scanner {
	return &Scanner{bufio.NewScanner(r)}
}

// Constructor to initialize bufio.Writer
func NewWriter(w io.Writer) *Writer {
	return &Writer{bufio.NewWriter(w)}
}

// Method to read the next token as a String
func (s *Scanner) Text() string {
	s.Scan()
	return s.Text()
}

// Method to read the next token as an integer
func (s *Scanner) Int() int {
	v, _ := strconv.Atoi(s.Text())
	return v
}

// Method to read the next token as a long
func (s *Scanner) Long() int64 {
	v, _ := strconv.ParseInt(s.Text(), 10, 64)
	return v
}

// Method to read the next token as a double
func (s *Scanner) Double() float64 {
	v, _ := strconv.ParseFloat(s.Text(), 64)
	return v
}

// Method to read the next line as a String
func (s *Scanner) Line() string {
	line, _ := s.Scanner.ReadString('\n')
	return strings.TrimRight(line, "\r\n")
}

// Method to flush the output buffer
func (w *Writer) Flush() {
	w.Writer.Flush()
}

//bufio.Scanner for efficient input reading
type Scanner struct {
	*bufio.Scanner
}

//bufio.Writer for efficient output writing
type Writer struct {
	*bufio.Writer
}

// Constructor to initialize bufio.Scanner
func NewScanner(r io.Reader) *Scanner {
	return &Scanner{bufio.NewScanner(r)}
}

// Constructor to initialize bufio.Writer
func NewWriter(w io.Writer) *Writer {
	return &Writer{bufio.NewWriter(w)}
}

// Method to read the next token as a String
func (s *Scanner) Text() string {
	s.Scan()
	return s.Text()
}

// Method to read the next token as an integer
func (s *Scanner) Int() int {
	v, _ := strconv.Atoi(s.Text())
	return v
}

// Method to read the next token as a long
func (s *Scanner) Long() int64 {
	v, _ := strconv.ParseInt(s.Text(), 10, 64)
	return v
}

// Method to read the next token as a double
func (s *Scanner) Double() float64 {
	v, _ := strconv.ParseFloat(s.Text(), 64)
	return v
}

// Method to read the next line as a String
func (s *Scanner) Line() string {
	line, _ := s.Scanner.ReadString('\n')
	return strings.TrimRight(line, "\r\n")
}

// Method to flush the output buffer
func (w *Writer) Flush() {
	w.Writer.Flush()
}

//bufio.Scanner for efficient input reading
type Scanner struct {
	*bufio.Scanner
}

//bufio.Writer for efficient output writing
type Writer struct {
	*bufio.Writer
}

// Constructor to initialize bufio.Scanner
func NewScanner(r io.Reader) *Scanner {
	return &Scanner{bufio.NewScanner(r)}
}

// Constructor to initialize bufio.Writer
func NewWriter(w io.Writer) *Writer {
	return &Writer{bufio.NewWriter(w)}
}

// Method to read the next token as a String
func (s *Scanner) Text() string {
	s.Scan()
	return s.Text()
}

// Method to read the next token as an integer
func (s *Scanner) Int() int {
	v, _ := strconv.Atoi(s.Text())
	return v
}

// Method to read 