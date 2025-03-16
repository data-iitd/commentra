
package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
)

const BUFFER_SIZE = 1024

func main() {
    // Creating a SimpleScanner object for reading input and a PrintWriter object for writing output
    scanner := NewSimpleScanner(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    // Reading input variables from the user
    r := scanner.NextInt() // Reading the first integer 'r' from the user
    d := scanner.NextInt() // Reading the second integer 'd' from the user
    x := scanner.NextLong() // Reading the long integer 'x' from the user

    // Running the loop for 10 iterations
    for i := 0; i < 10; i++ {
        // Multiplying 'r' with 'x' and subtracting 'd' from it
        x = r*x - d

        // Writing the result to the output stream
        fmt.Fprintln(writer, x)
    }

    // Closing the output stream
    writer.Flush()
}

// A private nested class SimpleScanner for reading input
type SimpleScanner struct {
    // Declaring the input stream and character buffer
    in  io.Reader
    buf *bufio.Reader
    eof bool
}

// Constructor for initializing the SimpleScanner object
func NewSimpleScanner(in io.Reader) *SimpleScanner {
    return &SimpleScanner{in, bufio.NewReader(in), false}
}

// A method for reading a single character from the input stream
func (scanner *SimpleScanner) read() byte {
    // If the character buffer is empty, refill it
    if !scanner.buf.Buffered() {
        scanner.buf.Reset(scanner.in)
        if scanner.buf.Buffered() == 0 {
            scanner.eof = true
            return 0
        }
    }
    // Return the current character from the character buffer
    return scanner.buf.ReadByte()
}

// A method for checking the end-of-file condition
func (scanner *SimpleScanner) checkEof() {
    if scanner.eof {
        panic("NoSuchElementException")
    }
}

// A method for reading a single character
func (scanner *SimpleScanner) NextChar() byte {
    scanner.checkEof()
    b := scanner.read()
    scanner.checkEof()
    return b
}

// A method for reading a string
func (scanner *SimpleScanner) Next() string {
    sb := &strings.Builder{}
    b := scanner.NextChar()
    for !scanner.eof {
        sb.WriteByte(b)
        b = scanner.NextChar()
    }
    return sb.String()
}

// A method for reading an integer
func (scanner *SimpleScanner) NextInt() int {
    return strconv.Atoi(scanner.Next())
}

// A method for reading a long integer
func (scanner *SimpleScanner) NextLong() int64 {
    return strconv.ParseInt(scanner.Next(), 10, 64)
}

// A method for reading a double
func (scanner *SimpleScanner) NextDouble() float64 {
    return strconv.ParseFloat(scanner.Next(), 64)
}

