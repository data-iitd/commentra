
# Go:
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// bufReader is a struct to efficiently read input.
type bufReader struct {
	r   *bufio.Reader
	buf []byte
	i   int
}

// Initialize global reader and writer for input and output operations.
var reader = &bufReader{
	bufio.NewReader(os.Stdin),
	make([]byte, 0),
	0,
}

// readLine reads the next line from the input and stores it in the buffer.
func (r *bufReader) readLine() {
	if r.i < len(r.buf) {
		return
	}
	r.buf = make([]byte, 0)
	r.i = 0
	for {
		line, isPrefix, err := r.r.ReadLine()
		if err != nil {
			panic(err)
		}
		r.buf = append(r.buf, line...)
		if !isPrefix {
			break
		}
	}
}

// next returns the next token (word) from the input.
func (r *bufReader) next() string {
	r.readLine()
	from := r.i
	for ; r.i < len(r.buf); r.i++ {
		if r.buf[r.i] == ' ' {
			break
		}
	}
	s := string(r.buf[from:r.i])
	r.i++
	return s
}

// nextLine is a wrapper for reader.nextLine().
func (r *bufReader) nextLine() string {
	r.readLine()
	s := string(r.buf[r.i:])
	r.i = len(r.buf)
	return s
}

// next is a wrapper for reader.next().
func next() string {
	return reader.next()
}

// nextInt64 reads the next token as an int64.
func nextInt64() int64 {
	i, err := strconv.ParseInt(reader.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

// nextInt reads the next token as an int.
func nextInt() int {
	return int(nextInt64())
}

// nextLine is a wrapper for reader.nextLine().
func nextLine() string {
	return reader.nextLine()
}

// out prints the arguments to the output.
func out(a ...interface{}) {
	fmt.Fprintln(writer, a...)
}

// max64 returns the maximum of two int64 values.
func max64(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

// max returns the maximum of two int values.
func max(x, y int) int {
	return int(max64(int64(x), int64(y)))
}

// min64 returns the minimum of two int64 values.
func min64(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}

// min returns the minimum of two int values.
func min(x, y int) int {
	return int(min64(int64(x), int64(y)))
}

// abs64 returns the absolute value of an int64.
func abs64(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

// abs returns the absolute value of an int.
func abs(x int) int {
	return int(abs64(int64(x)))
}

// joinInt64s joins an array of int64 values into a string with a separator.
func joinInt64s(a []int64, sep string) string {
	b := make([]string, len(a))
	for i, v := range a {
		b[i] = strconv.FormatInt(v, 10)
	}
	return strings.Join(b, sep)
}

// joinInts joins an array of int values into a string with a separator.
func joinInts(a []int, sep string) string {
	b := make([]string, len(a))
	for i, v := range a {
		b[i] = strconv.Itoa(v)
	}
	return strings.Join(b, sep)
}

// divUp64 returns the ceiling of the division of x by y.
func divUp64(x, y int64) int64 {
	return (x + y - 1) / y
}

// divUp returns the ceiling of the division of x by y.
func divUp(x, y int) int {
	return int(divUp64(int64(x), int64(y)))
}

// gcd64 returns the greatest common divisor of two int64 values.
func gcd64(x, y int64) int64 {
	if x < y {
		x, y = y, x
	}
	for y != 0 {
		x, y = y, x%y
	}
	return x
}

// gcd returns the greatest common divisor of two int values.
func gcd(x, y int) int {
	return int(gcd64(int64(x), int64(y)))
}

// lcm64 returns the least common multiple of two int64 values.
func lcm64(x, y int64) int64 {
	return x * y / gcd64(x, y)
}

// lcm returns the least common multiple of two int values.
func lcm(x, y int) int {
	return int(lcm64(int64(x), int64(y)))
}

// pow64 returns the result of raising x to the power of y.
func pow64(x, y int64) int64 {
	return int64(math.Pow(float64(x), float64(y)))
}

// pow returns the result of raising x to the power of y.
func pow(x, y int) int {
	return int(pow64(int64(x), int64(y)))
}

// main function calls solve and flushes the writer at the end.
func main() {
	solve()
	writer.Flush()
}

// solve function implements the main logic of the program.
func solve() {
	N, _ := nextInt(), nextInt()
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = nextInt()
	}
	maxProfit := 0
	maxCnt := 0
	maxA := A[N-1]
	for i := N - 2; i >= 0; i-- {
		profit := max(0, maxA-A[i])
		if maxProfit < profit:
			maxProfit = profit
			maxCnt = 1
		elif maxProfit == profit:
			maxCnt++
		maxA = max(maxA, A[i])
	out(maxCnt)
}

