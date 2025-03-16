
# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// bufReader struct definition
// This struct is designed to efficiently read lines from standard input.
// It uses a buffer to minimize the number of system calls.
type bufReader struct {
	r   *bufio.Reader
	buf []byte
	i   int
}

// bufReader initialization
var reader = &bufReader{
	bufio.NewReader(os.Stdin),
	make([]byte, 0),
	0,
}

// readLine reads a line from the input and stores it in the buffer.
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

// next returns the next space-separated word from the buffer.
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

// nextLine returns the entire next line from the buffer.
func (r *bufReader) nextLine() string {
	r.readLine()
	s := string(r.buf[r.i:])
	r.i = len(r.buf)
	return s
}

// bufio Writer initialization
var writer = bufio.NewWriter(os.Stdout)

// next wraps the reader.next() function.
func next() string {
	return reader.next()
}

// nextInt reads the next token as an integer.
func nextInt() int64 {
	i, err := strconv.ParseInt(reader.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

// nextLine wraps the reader.nextLine() function.
func nextLine() string {
	return reader.nextLine()
}

// out prints the arguments to the output with a newline.
func out(a ...interface{}) {
	fmt.Fprintln(writer, a...)
}

// max returns the maximum of two integers.
func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

// min returns the minimum of two integers.
func min(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}

// joinInts joins an array of integers into a string with a separator.
func joinInts(a []int64, sep string) string {
	b := make([]string, len(a))
	for i, v := range a {
		b[i] = strconv.FormatInt(v, 10)
	}
	return strings.Join(b, sep)
}

// divUp returns the ceiling of the division of x by y.
func divUp(x, y int64) int64 {
	return (x + y - 1) / y
}

// Main function
func main() {
	solve()
	writer.Flush()
}

// Solve function
// Reads the number of elements N.
// Reads N pairs of integers T and A.
// Iteratively adjusts t and a to ensure the ratios are maintained.
// Outputs the sum of t and a after all adjustments.
func solve() {
	N := nextInt()
	T, A := make([]int64, N), make([]int64, N)
	for i := 0; i < int(N); i++ {
		T[i], A[i] = nextInt(), nextInt()
	}
	t, a := T[0], A[0]
	for i := 1; i < int(N); i++ {
		r := max(divUp(t, T[i]), divUp(a, A[i]))
		t, a = T[i]*r, A[i]*r
	}
	out(t + a)
}

# Python:

# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// bufReader struct definition
// This struct is designed to efficiently read lines from standard input.
// It uses a buffer to minimize the number of system calls.
type bufReader struct {
	r   *bufio.Reader
	buf []byte
	i   int
}

// bufReader initialization
var reader = &bufReader{
	bufio.NewReader(os.Stdin),
	make([]byte, 0),
	0,
}

// readLine reads a line from the input and stores it in the buffer.
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

// next returns the next space-separated word from the buffer.
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

// nextLine returns the entire next line from the buffer.
func (r *bufReader) nextLine() string {
	r.readLine()
	s := string(r.buf[r.i:])
	r.i = len(r.buf)
	return s
}

// bufio Writer initialization
var writer = bufio.NewWriter(os.Stdout)

// next wraps the reader.next() function.
func next() string {
	return reader.next()
}

// nextInt reads the next token as an integer.
func nextInt() int64 {
	i, err := strconv.ParseInt(reader.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

// nextLine wraps the reader.nextLine() function.
func nextLine() string {
	return reader.nextLine()
}

// out prints the arguments to the output with a newline.
func out(a ...interface{}) {
	fmt.Fprintln(writer, a...)
}

// max returns the maximum of two integers.
func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

// min returns the minimum of two integers.
func min(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}

// joinInts joins an array of integers into a string with a separator.
func joinInts(a []int64, sep string) string {
	b := make([]string, len(a))
	for i, v := range a {
		b[i] = strconv.FormatInt(v, 10)
	}
	return strings.Join(b, sep)
}

// divUp returns the ceiling of the division of x by y.
func divUp(x, y int64) int64 {
	return (x + y - 1) / y
}

// Main function
func main() {
	solve()
	writer.Flush()
}

// Solve function
// Reads the number of elements N.
// Reads N pairs of integers T and A.
// Iteratively adjusts t and a to ensure the ratios are maintained.
// Outputs the sum of t and a after all adjustments.
func solve() {
	N := nextInt()
	T, A := make([]int64, N), make([]int64, N)
	for i := 0; i < int(N); i++ {
		T[i], A[i] = nextInt(), nextInt()
	}
	t, a := T[0], A[0]
	for i := 1; i < int(N); i++ {
		r := max(divUp(t, T[i]), divUp(a, A[i]))
		t, a = T[i]*r, A[i]*r
	}
	out(t + a)
}

# Python:

# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// bufReader struct definition
// This struct is designed to efficiently read lines from standard input.
// It uses a buffer to minimize the number of system calls.
type bufReader struct {
	r   *bufio.Reader
	buf []byte
	i   int
}

// bufReader initialization
var reader = &bufReader{
	bufio.NewReader(os.Stdin),
	make([]byte, 0),
	0,
}

// readLine reads a line from the input and stores it in the buffer.
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

// next returns the next space-separated word from the buffer.
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

// nextLine returns the entire next line from the buffer.
func (r *bufReader) nextLine() string {
	r.readLine()
	s := string(r.buf[r.i:])
	r.i = len(r.buf)
	return s
}

// bufio Writer initialization
var writer = bufio.NewWriter(os.Stdout)

// next wraps the reader.next() function.
func next() string {
	return reader.next()
}

// nextInt reads the next token as an integer.
func nextInt() int64 {
	i, err := strconv.ParseInt(reader.next(), 10, 64)
	if err != nil {
		panic(err)
	}
	return i
}

// nextLine wraps the reader.nextLine() function.
func nextLine() string {
	return reader.nextLine()
}

// out prints the arguments to the output with a newline.
func out(a ...interface{}) {
	fmt.Fprintln(writer, a...)
}

// max returns the maximum of two integers.
func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

// min returns the minimum of two integers.
func min(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}

// joinInts joins an array of integers into a string with a separator.
func joinInts(a []int64, sep string) string {
	b := make([]string, len(a))
	for i, v := range a {
		b[i] = strconv.FormatInt(v, 10)
	}
	return strings.Join(b, sep)
}

// divUp returns the ceiling of the division of x by y.
func divUp(x, y int64) int64 {
	return (x + y - 1) / y
}

// Main function
func main() {
	solve()
	writer.Flush()
}

// Solve function
// Reads the number of elements N.
// Reads N pairs of integers T and A.
// Iteratively adjusts t and a to ensure the ratios are maintained.
// Outputs the sum of t and a after all adjustments.
func solve() {
	N := nextInt()
	T, A := make([]int64, N), make([]int64, N)
	for i := 0; i < int(N); i++ {
		T[i], A[i] = nextInt(), nextInt()
	}
	t, a := T[0], A[0]
	for i := 1; i < int(N); i++ {
		r := max(divUp(t, T[i]), divUp(a, A[i]))
		t, a = T[i]*r, A[i]*r
	}
	out(t + a)
}

# Python:

# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// bufReader struct definition
// This struct is designed to efficiently read lines from standard input.
// It uses a buffer to minimize the number of system calls.
type bufReader struct {
	r   *bufio.Reader
	buf []byte
	i   int
}

// bufReader initialization
var reader = &bufReader{
	bufio.NewReader(os.Stdin),
	make([]byte, 0),
	0,
}

// readLine reads a line from the input and stores it in the buffer.
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

// next returns the next space-separated word from the buffer.
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

// nextLine returns the entire next line from the buffer.
func (r *bufReader) nextLine() string {
	r.readLine()
	s := string(r.buf[r.i:])
	r.i = len(r.buf)
	return s
}

// bufio Writer initialization
var writer = bufio.NewWriter(os.Stdout)

// next wraps the reader.next() function.
func next() string {
	return reader.next()
}

// nextInt reads the next token as an integer.
func nextInt() int64 {
	i, err := strconv.ParseInt(reader.next(), 10, 64)
	if err != nil {
		panic(err)
