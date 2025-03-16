// Package main is the entry point of the program
package main

import (
	// bufio package is used for reading and writing lines from/to I/O streams
	"bufio"
	// fmt package is used for formatted I/O
	"fmt"
	// math package is used for mathematical operations
	"math"
	// os package is used for interacting with the operating system
	"os"
	// strconv package is used for converting between string and numeric types
	"strconv"
	// strings package is used for string manipulation
	"strings"
)

// bufReader type is a custom reader that reads lines from os.Stdin
type bufReader struct {
	r   *bufio.Reader // bufio.Reader instance
	buf []byte        // buffer for storing read lines
	i   int           // index for the current position in the buffer
}

// reader variable is an instance of bufReader type
var reader = &bufReader{
	bufio.NewReader(os.Stdin), // initialize bufio.Reader
	make([]byte, 0),           // initialize empty buffer
	0,                        // initialize index to 0
}

// Function (r *bufReader) readLine reads a line from os.Stdin and stores it in the buffer
func (r *bufReader) readLine() {
	// If the index is less than the length of the buffer, it means that there is still some data left in the buffer
	if r.i < len(r.buf) {
		return
	}
	// Clear the buffer and set the index to 0
	r.buf = make([]byte, 0)
	r.i = 0
	// Read a line from os.Stdin and store it in the buffer
	for {
		line, isPrefix, err := r.r.ReadLine()
		// If an error occurs during reading, panic with the error message
		if err != nil {
			panic(err)
		}
		// If the line is not a prefix (i.e., it is a complete line), break the loop
		if !isPrefix {
			break
		}
		// Append the line to the buffer
		r.buf = append(r.buf, line...)
	}
}

// Function (r *bufReader) next returns the next token (i.e., a word or a number) from the buffer
func (r *bufReader) next() string {
	// Read a line from the buffer
	r.readLine()
	// Find the index of the first whitespace character in the line
	from := r.i
	// Iterate through the line until a whitespace character is found
	for ; r.i < len(r.buf); r.i++ {
		// If the current character is a whitespace character, break the loop
		if r.buf[r.i] == ' ' {
			break
		}
	}
	// Return the substring from the start index to the current index
	s := string(r.buf[from:r.i])
	// Increment the index
	r.i++
	// Return the token
	return s
}

// Function nextLine returns the next line from the buffer
func (r *bufReader) nextLine() string {
	// Read a line from the buffer
	r.readLine()
	// Return the substring from the current index to the end of the buffer
	s := string(r.buf[r.i:])
	// Set the index to the end of the buffer
	r.i = len(r.buf)
	// Return the line
	return s
}

// bufio.NewWriter is used for writing lines to os.Stdout
var writer = bufio.NewWriter(os.Stdout)

// Function next returns the next token (i.e., a word or a number) from the custom reader
func next() string {
	// Call the next function of the custom reader and return the result
	return reader.next()
}

// Function nextInt64 parses an integer from the custom reader and returns it as an int64 type
func nextInt64() int64 {
	// Parse an integer from the custom reader and return it as an int64 type
	i, err := strconv.ParseInt(reader.next(), 10, 64)
	// If an error occurs during parsing, panic with the error message
	if err != nil {
		panic(err)
	}
	// Return the integer
	return i
}

// Function nextInt parses an integer from the custom reader and returns it as an int type
func nextInt() int {
	// Parse an integer from the custom reader and return it as an int type
	return int(nextInt64())
}

// Function nextLine reads a line from the custom reader and returns it as a string
func nextLine() string {
	// Read a line from the custom reader and return it as a string
	return reader.nextLine()
}

// Function out is used for printing output to the console
func out(a ...interface{}) {
	// Write the formatted output to the bufio.Writer
	fmt.Fprintln(writer, a...)
}

// Function max64 returns the maximum of two int64 values
func max64(x, y int64) int64 {
	// If x is greater than y, return x; otherwise, return y
	if x > y {
		return x
	}
	return y
}

// Function max returns the maximum of two int values
func max(x, y int) int {
	// Return the maximum of x and y as an int value
	return int(max64(int64(x), int64(y)))
}

// Function min64 returns the minimum of two int64 values
func min64(x, y int64) int64 {
	// If x is less than y, return x; otherwise, return y
	if x < y {
		return x
	}
	return y
}

// Function min returns the minimum of two int values
func min(x, y int) int {
	// Return the minimum of x and y as an int value
	return int(min64(int64(x), int64(y)))
}

// Function abs64 returns the absolute value of an int64 value
func abs64(x int64) int64 {
	// If x is negative, return the negative of x; otherwise, return x
	if x < 0 {
		return -x
	}
	return x
}

// Function abs returns the absolute value of an int value
func abs(x int) int {
	// Return the absolute value of x as an int value
	return int(abs64(int64(x)))
}

// Function joinInt64s joins an array of int64 values with a given separator and returns the resulting string
func joinInt64s(a []int64, sep string) string {
	// Create a slice of strings by converting each int64 value to a string
	b := make([]string, len(a))
	// Iterate through the array and convert each int64 value to a string
	for i, v := range a {
		b[i] = strconv.FormatInt(v, 10)
	}
	// Join the strings in the slice with the given separator and return the resulting string
	return strings.Join(b, sep)
}

// Function joinInts joins an array of int values with a given separator and returns the resulting string
func joinInts(a []int, sep string) string {
	// Create a slice of strings by converting each int value to a string
	b := make([]string, len(a))
	// Iterate through the array and convert each int value to a string
	for i, v := range a {
		b[i] = strconv.Itoa(v)
	}
	// Join the strings in the slice with the given separator and return the resulting string
	return strings.Join(b, sep)
}

// Function divUp64 returns the smallest integer n such that n*divisor >= dividend
func divUp64(x, y int64) int64 {
	// Return the smallest integer n such that n*divisor >= dividend
	return (x + y - 1) / y
}

// Function divUp returns the smallest integer n such that n*divisor >= dividend
func divUp(x, y int) int {
	// Return the smallest integer n such that n*divisor >= dividend
	return int(divUp64(int64(x), int64(y)))
}

// Function gcd64 returns the greatest common divisor of two int64 values
func gcd64(x, y int64) int64 {
	// If x is greater than y, swap x and y
	if x < y {
		x, y = y, x
	}
	// Iterate through the range of possible divisors
	for y != 0 {
		// Calculate the remainder of x/y
		x, y = y, x%y
	}
	// Return x as the greatest common divisor
	return x
}

// Function gcd returns the greatest common divisor of two int values
func gcd(x, y int) int {
	// Return the greatest common divisor of x and y as an int value
	return int(gcd64(int64(x), int64(y)))
}

// Function lcm64 returns the least common multiple of two int64 values
func lcm64(x, y int64) int64 {
	// Calculate the greatest common divisor of x and y
	gcd := gcd64(x, y)
	// Return the product of x and y divided by their greatest common divisor
	return x*y / gcd
}

// Function lcm returns the least common multiple of two int values
func lcm(x, y int) int {
	// Return the least common multiple of x and y as an int value
	return int(lcm64(int64(x), int64(y)))
}

// Function pow64 returns x raised to the power of y as an int64 value
func pow64(x, y int64) int64 {
	// Return x raised to the power of y as an int64 value using the math.Pow function
	return int64(math.Pow(float64(x), float64(y)))
}

// Function pow returns x raised to the power of y as an int value
func pow(x, y int) int {
	// Return x raised to the power of y as an int value
	return int(pow64(int64(x), int64(y)))
}

// Function main is the entry point of the program
func main() {
	// Call the solve function to solve the problem
	solve()
	// Flush the bufio.Writer to write the output to the console
	writer.Flush()
}

// Function solve reads input from the custom reader, processes it, and writes the output to the bufio.Writer
func solve() {
	// Read two integers N and K from the custom reader
	N, _ := nextInt(), nextInt()
	// Initialize an array A of size N
	A := make([]int, N)
	// Read N integers from the custom reader and store them in the array A
	for i := 0; i < N; i++ {
		A[i] = nextInt()
	}
	// Initialize variables maxProfit, maxCnt, and maxA
	maxProfit := 0
	maxCnt := 0
	maxA := A[N-1]
	// Iterate through the array A from the last index to the first index
	for i := N - 2; i >= 0; i-- {
		// Calculate the profit of the current transaction
		profit := max(0, maxA-A[i])
		// If the current profit is greater than the maximum profit found so far, update maxProfit and maxCnt
		if maxProfit < profit {
			maxProfit = profit
			maxCnt = 1
		} else if maxProfit == profit {
			maxCnt++
		}
		// Update maxA with the maximum of the current element and maxA
		maxA = max(maxA, A[i])
	}
	// Write the output to the console
	out(maxCnt)
}