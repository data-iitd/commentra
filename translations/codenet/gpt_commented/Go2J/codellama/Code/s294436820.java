
// -----------------------------------------------------------------------------

// IO helper functions

// nextToken and nextLine are function variables that will be initialized 
// by SetInput() and SetUnbufferedInput() for reading input tokens and lines.
var nextToken func() ([]byte, error)
var nextLine func() ([]byte, error)

// OutputBuffer holds a buffered writer for output. It must be initialized by SetOutput().
var OutputBuffer *bufio.Writer

// OutputWriter holds an io.Writer for output. It must be initialized by SetOutput().
var OutputWriter io.Writer

// SetInteractive configures the IO functions for interactive input/output.
func SetInteractive(w io.Writer, r io.Reader) {
	SetUnbufferedInput(r) // Set unbuffered input for reading
	OutputBuffer = nil     // No output buffer for interactive mode
	OutputWriter = w       // Set the output writer
}

// Setup OutputBuffer and OutputWriter for buffered output.
func SetOutput(w io.Writer) {
	OutputBuffer = bufio.NewWriter(w) // Initialize the output buffer
	OutputWriter = OutputBuffer         // Set the output writer to the buffer
}

// Flushes OutputBuffer to ensure all buffered data is written out.
func Flush() {
	if OutputBuffer != nil {
		OutputBuffer.Flush() // Flush the buffer if it is initialized
	}
}

// IsSpace checks if a byte is a whitespace character.
func IsSpace(c byte) bool {
	switch c {
	case '\t', '\n', '\v', '\f', '\r', ' ':
		return true
	}
	return false
}

// IsNewLine checks if a byte is a newline character.
func IsNewLine(c byte) bool {
	switch c {
	case '\n', '\r':
		return true
	}
	return false
}

// SetInput initializes the nextToken function with an input buffer.
func SetInput(r io.Reader) {
	buf := new(bytes.Buffer) // Create a new bytes buffer
	var b []byte             // Buffer to hold input bytes

	var i int                // Index for reading from buffer
	// Function to read the next token from the input
	rest := func() ([]byte, error) {
		for i < len(b) && IsSpace(b[i]) {
			i++ // Skip whitespace
		}
		if i == len(b) {
			return nil, io.ErrUnexpectedEOF // Return error if end of buffer is reached
		}
		j := i
		for i < len(b) && !IsSpace(b[i]) {
			i++ // Read until whitespace is found
		}
		return b[j:i], nil // Return the token
	}
	// Function to initialize reading from the input
	initial := func() ([]byte, error) {
		io.Copy(buf, r) // Copy input to buffer
		b = buf.Bytes() // Get bytes from the buffer
		nextToken = rest // Set nextToken to the rest function
		return rest()    // Read the first token
	}
	nextToken = initial // Initialize nextToken

	// Function to read the next line from the input
	restLn := func() ([]byte, error) {
		for i < len(b) && IsNewLine(b[i]) {
			i++ // Skip new line characters
		}
		if i == len(b) {
			return nil, io.ErrUnexpectedEOF // Return error if end of buffer is reached
		}
		j := i
		for i < len(b) && !IsNewLine(b[i]) {
			i++ // Read until new line is found
		}
		return b[j:i], nil // Return the line
	}

	// Function to initialize reading lines from the input
	initialLn := func() ([]byte, error) {
		io.Copy(buf, r) // Copy input to buffer
		b = buf.Bytes() // Get bytes from the buffer
		nextLine = restLn // Set nextLine to the restLn function
		return restLn() // Read the first line
	}
	nextLine = initialLn // Initialize nextLine
}

// SetUnbufferedInput configures the nextToken function for unbuffered input.
func SetUnbufferedInput(r io.Reader) {
	buf := bufio.NewReader(r) // Create a new buffered reader
	var b []byte               // Buffer to hold input bytes

	var i int                  // Index for reading from buffer
	// Function to read the next token from the input
	nextToken = func() ([]byte, error) {
		var err error
		if i == len(b) { // If the buffer is empty
			b, err = buf.ReadBytes('\n') // Read until newline
			if err != nil {
				return nil, err // Return error if reading fails
			}
			i = 0 // Reset index
			j := len(b) - 1
			for 0 <= j && IsSpace(b[j]) {
				j-- // Trim trailing whitespace
			}
			b = b[0 : j+1] // Resize buffer to remove whitespace
		}
		for i < len(b) && IsSpace(b[i]) {
			i++ // Skip whitespace
		}
		j := i
		for i < len(b) && !IsSpace(b[i]) {
			i++ // Read until whitespace is found
		}
		if i == j {
			return nil, io.ErrUnexpectedEOF // Return error if no token found
		}
		return b[j:i], nil // Return the token
	}
}

// -----------------------------------------------------------------------------

// IO functions

// readb reads the next token and returns it as a byte slice.
func readb() []byte {
	b, err := nextToken() // Read the next token
	if err != nil {
		panic(err) // Panic if an error occurs
	}
	return b[:len(b):len(b)] // Return the token
}

// reads reads the next token and returns it as a string.
func reads() string {
	return string(readb()) // Convert byte slice to string
}

// readbln reads the next line as a byte slice, excluding the trailing newline.
func readbln() []byte {
	b, err := nextLine() // Read the next line
	if err != nil {
		panic(err) // Panic if an error occurs
	}
	return b[:len(b):len(b)] // Return the line
}

// readsln reads the next line and returns it as a string.
func readsln() string {
	return string(readbln()) // Convert byte slice to string
}

// readll reads the next token and returns it as an int64.
func readll() int64 {
	i, err := strconv.ParseInt(reads(), 10, 64) // Parse the next token as int64
	if err != nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i // Return the parsed int64
}

// readi reads the next token and returns it as an int.
func readi() int {
	return int(readll()) // Convert int64 to int
}

// readf reads the next token and returns it as a float64.
func readf() float64 {
	f, err := strconv.ParseFloat(reads(), 64) // Parse the next token as float64
	if err != nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return f // Return the parsed float64
}

// printf writes formatted output to OutputWriter.
func printf(f string, args ...interface{}) (int, error) {
	return fmt.Fprintf(OutputWriter, f, args...) // Write formatted output
}

// println writes output to OutputWriter without formatting.
func println(args ...interface{}) (int, error) {
	return fmt.Fprintln(OutputWriter, args...) // Write output without formatting
}

// eprintf writes formatted output to stderr.
func eprintf(f string, args ...interface{}) (int, error) {
	return fmt.Fprintf(os.Stderr, f, args...) // Write formatted output to stderr
}

// eprintln writes output to stderr without formatting.
func eprintln(args ...interface{}) (int, error) {
	return fmt.Fprintln(os.Stderr, args...) // Write output without formatting to stderr
}

// debugf writes formatted debug output to stderr if DEBUG is enabled.
func debugf(f string, args ...interface{}) {
	if !DEBUG {
		return // Do nothing if DEBUG is not enabled
	}
	fmt.Fprintf(os.Stderr, f, args...) // Write formatted debug output
}

// debug writes debug output to stderr if DEBUG is enabled.
func debug(args ...interface{}) {
	if !DEBUG {
		return // Do nothing if DEBUG is not enabled
	}
	fmt.Fprintln(os.Stderr, args...) // Write debug output
}

// -----------------------------------------------------------------------------

// Utilities

// sumSlice calculates the sum of a slice of integers.
func sumSlice(a []int) int {
	var res int
	for _, v := range a {
		res += v // Accumulate the sum
	}
	return res // Return the total sum
}

// sumSlicell calculates the sum of a slice of int64.
func sumSlicell(a []int64) int64 {
	var res int64
	for _, v := range a {
		res += v // Accumulate the sum
	}
	return res // Return the total sum
}

// readInts reads N integers from input and returns the count and the slice.
func readInts(N int) (int, []int) {
	if N == 0 {
		N = readi() // Read N if it is zero
	}
	a := make([]int, N) // Create a slice of integers
	for i := range a {
		a[i] = readi() // Read each integer
	}
	return N, a // Return the count and the slice
}

// readIntsll reads N int64 values from input and returns the count and the slice.
func readIntsll(N int) (int, []int64) {
	if N == 0 {
		N = readi() // Read N if it is zero
	}
	a := make([]int64, N) // Create a slice of int64
	for i := range a {
		a[i] = readll() // Read each int64 value
	}
	return N, a // Return the count and the slice
}

// -----------------------------------------------------------------------------

// Simple math functions

const (
	// Define large prime constants for calculations
	INF  = 1000000007
	INF2 = 1000000009
	INF3 = 998244353
)

// min returns the smaller of two integers.
func min(a, b int) int {
	if a < b {
		return a // Return a if it is smaller
	}
	return b // Otherwise return b
}

// minll returns the smaller of two int64 values.
func minll(a, b int64) int64 {
	if a < b {
		return a // Return a if it is smaller
	}
	return b // Otherwise return b
}

// minf returns the smaller of two float64 values.
func minf(a, b float64) float64 {
	if a < b {
		return a // Return a if it is smaller
	}
	return b // Otherwise return b
}

// max returns the larger of two integers.
func max(a, b int) int {
	if a < b {
		return b // Return b if it is larger
	}
	return a // Otherwise return a
}

// maxll returns the larger of two int64 values.
func maxll(a, b int64) int64 {
	if a < b {
		return b // Return b if it is larger
	}
	return a // Otherwise return a
}

// maxf returns the larger of two float64 values.
func maxf(a, b float64) float64 {
	if a < b {
		return b // Return b if it is larger
	}
	return a // Otherwise return a
}

// abs returns the absolute value of an integer.
func abs(a int) int {
	