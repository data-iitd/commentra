
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize input and output streams
	inputStream := os.Stdin
	outputStream := os.Stdout

	// Create InputReader and PrintWriter objects
	in := NewInputReader(inputStream)
	out := NewPrintWriter(outputStream)

	// Read input integers a, b, c, and d
	a := in.NextInt()
	b := in.NextInt()
	c := in.NextInt()
	d := in.NextInt()

	// Check if c is greater than b
	if c > b {
		// If yes, print 0 and exit
		out.Println(0)
		return
	}

	// Check if a is greater than d
	if a > d {
		// If yes, print 0 and exit
		out.Println(0)
		return
	}

	// Check if a is less than c
	if a < c {
		// If yes, calculate the difference between the smaller and larger of b and d
		difference := Min(b, d) - c
		// Print the difference
		out.Println(difference)
		return
	}

	// If none of the above conditions are true, then a, b, c, and d are in sorted order
	else {
		// Create a List of integers a, b, c, and d
		l := make([]int, 4)
		l[0] = a
		l[1] = b
		l[2] = c
		l[3] = d

		// Sort the List in ascending order
		Sort(l)

		// Calculate the difference between the second and third elements of the List
		difference := l[2] - l[1]

		// Print the difference
		out.Println(difference)
	}
}

// InputReader class for reading input from standard input
type InputReader struct {
	reader       *bufio.Reader
	tokenizer    *strings.Reader
	tokenizerPos int
}

// Constructor for InputReader
func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{
		reader: bufio.NewReader(stream),
	}
}

// Method for reading a string
func (in *InputReader) Next() string {
	if in.tokenizer == nil || in.tokenizerPos >= len(in.tokenizer.String()) {
		in.tokenizer = strings.NewReader(in.reader.ReadString('\n'))
		in.tokenizerPos = 0
	}
	token, _ := in.tokenizer.ReadString(' ')
	in.tokenizerPos++
	return token
}

// Method for reading an integer
func (in *InputReader) NextInt() int {
	return int(in.NextInt64())
}

// Method for reading a long integer
func (in *InputReader) NextInt64() int64 {
	return int64(strconv.ParseInt(in.Next(), 10, 64))
}

// PrintWriter class for writing output to standard output
type PrintWriter struct {
	writer *bufio.Writer
}

// Constructor for PrintWriter
func NewPrintWriter(stream io.Writer) *PrintWriter {
	return &PrintWriter{
		writer: bufio.NewWriter(stream),
	}
}

// Method for writing a string
func (out *PrintWriter) Println(a ...interface{}) {
	fmt.Fprintln(out.writer, a...)
}

// Method for writing an integer
func (out *PrintWriter) PrintInt(a int) {
	out.writer.WriteString(strconv.Itoa(a))
}

// Method for writing a long integer
func (out *PrintWriter) PrintInt64(a int64) {
	out.writer.WriteString(strconv.FormatInt(a, 10))
}

// Method for writing a string
func (out *PrintWriter) Print(a ...interface{}) {
	fmt.Fprint(out.writer, a...)
}

// Method for flushing the output stream
func (out *PrintWriter) Flush() {
	out.writer.Flush()
}

// Method for sorting a List of integers in ascending order
func Sort(l []int) {
	for i := 0; i < len(l); i++ {
		for j := i + 1; j < len(l); j++ {
			if l[i] > l[j] {
				l[i], l[j] = l[j], l[i]
			}
		}
	}
}

// Method for finding the minimum of two integers
func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Method for finding the maximum of two integers
func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Method for finding the minimum of two long integers
func Min64(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// Method for finding the maximum of two long integers
func Max64(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// Method for finding the absolute value of an integer
func Abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// Method for finding the absolute value of a long integer
func Abs64(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

// Method for finding the absolute value of a float
func AbsFloat(a float64) float64 {
	if a < 0 {
		return -a
	}
	return a
}

// Method for finding the absolute value of a double
func AbsDouble(a float64) float64 {
	if a < 0 {
		return -a
	}
	return a
}

// Method for finding the absolute value of a long double
func AbsLongDouble(a float64) float64 {
	if a < 0 {
		return -a
	}
	return a
}

// Method for finding the absolute value of a complex number
func AbsComplex(a complex128) complex128 {
	return cmplx.Abs(a)
}

// Method for finding the absolute value of a complex long double
func AbsComplexLongDouble(a complex128) complex128 {
	return cmplx.Abs(a)
}

// Method for finding the square root of an integer
func Sqrt(a int) int {
	return int(math.Sqrt(float64(a)))
}

// Method for finding the square root of a long integer
func Sqrt64(a int64) int64 {
	return int64(math.Sqrt(float64(a)))
}

// Method for finding the square root of a float
func SqrtFloat(a float32) float32 {
	return float32(math.Sqrt(float64(a)))
}

// Method for finding the square root of a double
func SqrtDouble(a float64) float64 {
	return math.Sqrt(a)
}

// Method for finding the square root of a long double
func SqrtLongDouble(a float64) float64 {
	return math.Sqrt(a)
}

// Method for finding the square root of a complex number
func SqrtComplex(a complex128) complex128 {
	return cmplx.Sqrt(a)
}

// Method for finding the square root of a complex long double
func SqrtComplexLongDouble(a complex128) complex128 {
	return cmplx.Sqrt(a)
}

// Method for finding the cube root of an integer
func Cbrt(a int) int {
	return int(math.Cbrt(float64(a)))
}

// Method for finding the cube root of a long integer
func Cbrt64(a int64) int64 {
	return int64(math.Cbrt(float64(a)))
}

// Method for finding the cube root of a float
func CbrtFloat(a float32) float32 {
	return float32(math.Cbrt(float64(a)))
}

// Method for finding the cube root of a double
func CbrtDouble(a float64) float64 {
	return math.Cbrt(a)
}

// Method for finding the cube root of a long double
func CbrtLongDouble(a float64) float64 {
	return math.Cbrt(a)
}

// Method for finding the cube root of a complex number
func CbrtComplex(a complex128) complex128 {
	return cmplx.Cbrt(a)
}

// Method for finding the cube root of a complex long double
func CbrtComplexLongDouble(a complex128) complex128 {
	return cmplx.Cbrt(a)
}

// Method for finding the power of an integer
func Pow(a, b int) int {
	return int(math.Pow(float64(a), float64(b)))
}

// Method for finding the power of a long integer
func Pow64(a, b int64) int64 {
	return int64(math.Pow(float64(a), float64(b)))
}

// Method for finding the power of a float
func PowFloat(a, b float32) float32 {
	return float32(math.Pow(float64(a), float64(b)))
}

// Method for finding the power of a double
func PowDouble(a, b float64) float64 {
	return math.Pow(a, b)
}

// Method for finding the power of a long double
func PowLongDouble(a, b float64) float64 {
	return math.Pow(a, b)
}

// Method for finding the power of a complex number
func PowComplex(a, b complex128) complex128 {
	return cmplx.Pow(a, b)
}

// Method for finding the power of a complex long double
func PowComplexLongDouble(a, b complex128) complex128 {
	return cmplx.Pow(a, b)
}

// Method for finding the logarithm of an integer
func Log(a int) int {
	return int(math.Log(float64(a)))
}

// Method for finding the logarithm of a long integer
func Log64(a int64) int64 {
	return int64(math.Log(float64(a)))
}

// Method for finding the logarithm of a float
func LogFloat(a float32) float32 {
	return float32(math.Log(float64(a)))
}

// Method for finding the logarithm of a double
func LogDouble(a float64) float64 {
	return math.Log(a)
}

// Method for finding the logarithm of a long double
func LogLongDouble(a float64) float64 {
	return math.Log(a)
}

// Method for finding the logarithm of a complex number
func LogComplex(a complex128) complex128 {
	return cmplx.Log(a)
}

// Method for finding the logarithm of a complex long double
func LogComplexLongDouble(a complex128) complex128 {
	return cmplx.Log(a)
}

// Method for finding the exponential of an integer
func Exp(a int) int {
	return int(math.Exp(float64(a)))
}

// Method for finding the exponential of a long integer
func Exp64(a int64) int64 {
	return int64(math.Exp(float64(a)))
}

// Method for finding the exponential of a float
func ExpFloat(a float32) float32 {
	return float32(math.Exp(float64(a)))
}

// Method for finding the exponential of a double
func ExpDouble(a float64) float64 {
	return math.Exp(a)
}

// Method for finding the exponential of a long double
func ExpLongDouble(a float64) float64 {
	return math.Exp(a)
}

// Method for finding the exponential of a complex number
func ExpComplex(a complex128) complex128 {
	return cmplx.Exp(a)
}

// Method for finding the exponential of a complex long double
func ExpComplexLongDouble(a complex128) complex128 {
	return cmplx.Exp(a)
}

// Method for finding the sine of an integer
func Sin(a int) int {
	return int(math.Sin(float64(a)))
}

// Method for finding the sine of a long integer
func Sin64(a int64) int64 {
	return int64(math.Sin(float64(a)))
}

// Method for finding the sine of a float
func SinFloat(a float32) float32 {
	return float32(math.Sin(float64(a)))
}

// Method for finding the sine of a double
func SinDouble(a float64) float64 {
	return math.Sin(a)
}

// Method for finding the sine of a long double
func SinLongDouble(a float64) float64 {
	return math.Sin(a)
}

// Method for finding the sine of a complex number
func SinComplex(a complex128) complex128 {
	return cmplx.Sin(a)
}

// Method for finding the sine of a complex long double
func SinComplexLongDouble(a complex128) complex128 {
	return cmplx.Sin(a)
}

// Method for finding the cosine of an integer
func Cos(a int) int {
	return int(math.Cos(float64(a)))
}

// Method for finding the cosine of a long integer
func Cos64(a int64) int64 {
	return int64(math.Cos(float64(a)))
}

// Method for finding the cosine of a float
func CosFloat(a float32) float32 {
	return float32(math.Cos(float64(a)))
}

// 