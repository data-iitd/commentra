// Importing necessary Go libraries
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Main function starts here
func main() {

	// Creating FastReader object to read input
	sc := newFastReader()

	// Creating PrintWriter object to write output
	pw := newPrintWriter()

	// Reading the first integer input
	x, _ := strconv.Atoi(sc.next())

	// Initializing count variable to 0
	count := 0

	// Initializing temporary variable tmp with the value of x
	tmp := x

	// Setting x to 0
	x = 0

	// Starting a while loop that runs until x is equal to 360
	for x != 360 {

		// Adding the value of tmp to x
		x = x + tmp

		// If x is greater than 360, then subtract 360 from it
		if x > 360 {
			x = x - 360
		}

		// Incrementing the count variable
		count++
	}

	// Printing the value of count to the console using PrintWriter
	pw.println(count)

	// Closing the PrintWriter and FastReader objects
	pw.close()
	sc.close()
}

// FastReader class starts here
type fastReader struct {
	br   *bufio.Reader
	st   *strings.Reader
	temp string
}

// Constructor method initializes BufferedReader object
func newFastReader() *fastReader {
	return &fastReader{br: bufio.NewReader(os.Stdin), st: &strings.Reader{}, temp: ""}
}

// Method to read a string token
func (f *fastReader) next() string {
	for f.st == nil || !f.st.Scan() {
		f.st = &strings.Reader{}
		line, _, err := f.br.ReadLine()
		if err != nil {
			panic(err)
		}
		f.st = strings.NewReader(string(line))
	}
	return f.st.Text()
}

// Method to read an integer input
func (f *fastReader) nextInt() int {
	return int(f.nextInt64())
}

// Method to read a long integer input
func (f *fastReader) nextInt64() int64 {
	return int64(f.nextInt32())
}

// Method to read a long integer input
func (f *fastReader) nextInt32() int32 {
	return int32(f.nextInt16())
}

// Method to read a long integer input
func (f *fastReader) nextInt16() int16 {
	return int16(f.nextInt8())
}

// Method to read a long integer input
func (f *fastReader) nextInt8() int8 {
	return int8(f.nextInt64())
}

// Method to read a double input
func (f *fastReader) nextDouble() float64 {
	return float64(f.nextFloat64())
}

// Method to read a float input
func (f *fastReader) nextFloat64() float64 {
	return float64(f.nextFloat32())
}

// Method to read a float input
func (f *fastReader) nextFloat32() float32 {
	return float32(f.nextFloat16())
}

// Method to read a float input
func (f *fastReader) nextFloat16() float16.Float16 {
	return float16.Parse(f.next())
}

// Method to read a full line of input
func (f *fastReader) nextLine() string {
	str := ""
	for f.st == nil || !f.st.Scan() {
		f.st = &strings.Reader{}
		line, _, err := f.br.ReadLine()
		if err != nil {
			panic(err)
		}
		f.st = strings.NewReader(string(line))
	}
	return str
}

// PrintWriter class starts here
type printWriter struct {
	pw *bufio.Writer
}

// Constructor method initializes BufferedReader object
func newPrintWriter() *printWriter {
	return &printWriter{pw: bufio.NewWriter(os.Stdout)}
}

// Method to print a string to the console
func (p *printWriter) println(s string) {
	fmt.Fprintln(p.pw, s)
}

// Method to print an integer to the console
func (p *printWriter) println(i int) {
	fmt.Fprintln(p.pw, i)
}

// Method to print a long integer to the console
func (p *printWriter) println(i int64) {
	fmt.Fprintln(p.pw, i)
}

// Method to print a float to the console
func (p *printWriter) println(f float64) {
	fmt.Fprintln(p.pw, f)
}

// Method to print a double to the console
func (p *printWriter) println(d float32) {
	fmt.Fprintln(p.pw, d)
}

// Method to close the PrintWriter object
func (p *printWriter) close() {
	p.pw.Flush()
}

