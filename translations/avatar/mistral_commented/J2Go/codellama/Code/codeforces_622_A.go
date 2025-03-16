
package main

import (
 "bufio"
 "fmt"
 "io"
 "os"
 "strconv"
 "strings"
)

// Initialize constants
const BUFFER_SIZE = 512000

// Initialize scanner and print writer
var sc = bufio.NewScanner(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

// Main method
func main() {
 init() // Initialize input and output streams
 solve() // Solve the problem
 closeIO() // Close input and output streams
}

// Initialize input and output streams
func init() {
 sc.Buffer(make([]byte, BUFFER_SIZE), BUFFER_SIZE)
}

// Close input and output streams
func closeIO() {
 sc.Buffer(make([]byte, 0), 0)
 out.Flush()
}

// Solve the problem
func solve() {
 position := nextInt() // Read the position from input
 solveHelper(position) // Solve the problem using helper method
}

// Helper method to solve the problem
func solveHelper(position int64) {
 var nrstSeqStartIndx int64 = 1 // Initialize index for the start of the next sequence

 // Binary search for the start index of the sequence containing the position
 for getValueAtIndex(nrstSeqStartIndx*2) < position {
 nrstSeqStartIndx *= 2 // Multiply index by 2
 }

 // Linear search for the end index of the sequence containing the position
 for getValueAtIndex(nrstSeqStartIndx+1) <= position {
 nrstSeqStartIndx++ // Increment index
 }

 // Print the answer
 startIndex := getValueAtIndex(nrstSeqStartIndx) // Get the start index of the sequence
 fmt.Println(position-startIndex+1) // Print the length of the sequence
}

// Get the value at a given index
func getValueAtIndex(index int64) int64 {
 return 1 + (index-1)*index/2 // Calculate the value at the given index
}

// Inner class for input handling
type in struct {
 reader *bufio.Reader
 tokenizer *strings.Reader
}

// Initialize input stream
func (in *in) init(input io.Reader) {
 in.reader = bufio.NewReader(input)
 in.tokenizer = strings.NewReader("")
}

// Read a string token from input
func (in *in) next() string {
 for !in.tokenizer.Scan() {
 in.tokenizer = strings.NewReader(in.reader.ReadString('\n'))
 }
 return in.tokenizer.Text()
}

// Read an integer from input
func (in *in) nextInt() int64 {
 return int64(in.nextInt64())
}

// Read an integer from input
func (in *in) nextInt64() int64 {
 i, _ := strconv.ParseInt(in.next(), 10, 64)
 return i
}

// Read a double from input
func (in *in) nextDouble() float64 {
 f, _ := strconv.ParseFloat(in.next(), 64)
 return f
}

// Read a long from input
func (in *in) nextLong() int64 {
 return in.nextInt64()
}

// Read a string from input
func (in *in) nextString() string {
 return in.next()
}

// Read a line from input
func (in *in) nextLine() string {
 return in.reader.ReadString('\n')
}

// Read a boolean from input
func (in *in) nextBool() bool {
 return in.next() == "true"
}

// Read a byte from input
func (in *in) nextByte() byte {
 b, _ := strconv.ParseInt(in.next(), 10, 8)
 return byte(b)
}

// Read a rune from input
func (in *in) nextRune() rune {
 r, _, _ := in.reader.ReadRune()
 return r
}

// Read a char from input
func (in *in) nextChar() byte {
 return in.nextByte()
}

// Read a complex from input
func (in *in) nextComplex() complex128 {
 r, _ := strconv.ParseComplex(in.next(), 128)
 return r
}

// Read a float from input
func (in *in) nextFloat() float64 {
 f, _ := strconv.ParseFloat(in.next(), 64)
 return f
}

// Read a big integer from input
func (in *in) nextBigInt() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt64() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat64() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal64() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt32() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat32() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal32() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt16() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat16() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal16() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt8() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat8() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal8() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt64() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat64() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal64() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt32() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat32() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal32() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt16() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat16() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal16() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt8() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat8() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal8() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt64() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat64() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal64() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt32() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat32() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal32() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt16() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat16() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal16() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt8() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat8() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal8() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt64() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat64() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal64() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt32() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat32() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal32() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt16() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat16() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal16() *big.Rat {
 r, _ := new(big.Rat).SetString(in.next())
 return r
}

// Read a big integer from input
func (in *in) nextBigInt8() *big.Int {
 i, _ := new(big.Int).SetString(in.next(), 10)
 return i
}

// Read a big float from input
func (in *in) nextBigFloat8() *big.Float {
 f, _ := new(big.Float).SetString(in.next())
 return f
}

// Read a big decimal from input
func (in *in) nextBigDecimal8() *big