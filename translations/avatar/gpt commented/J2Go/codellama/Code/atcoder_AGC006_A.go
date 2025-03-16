package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a constant for the maximum size of the arrays
const N = 200 + 10

// Array to store the failure function values
var f [N]int

// Array to store the concatenated strings
var b [N]byte

// Function to compute the failure function for the KMP algorithm
func getFail(b []byte, m int) {
	j := 0 // Initialize j to track the length of the previous longest prefix suffix
	f[0] = f[1] = 0 // Base cases for the failure function

	// Loop through the string to fill the failure function
	for i := 2; i <= m; i++ {
		// Adjust j until we find a match or j becomes 0
		for j > 0 && b[j+1] != b[i] {
			j = f[j]
		}
		// If there is a match, increment j
		if b[j+1] == b[i] {
			j++
		}
		// Set the failure function value for the current position
		f[i] = j
	}
}

func main() {
	// Create an input reader and output writer
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	// Read the length of the strings
	n, _ := strconv.Atoi(readLine(in))
	// Read the two strings
	s1 := readLine(in)
	str := readLine(in)
	cnt := 0

	// Concatenate the second string into the character array
	for i := 0; i < n; i++ {
		b[cnt] = str[i]
		cnt++
	}
	// Concatenate the first string into the character array
	for i := 0; i < n; i++ {
		b[cnt] = s1[i]
		cnt++
	}

	// Compute the failure function for the concatenated strings
	getFail(b[:cnt], cnt)

	// Calculate the length of the longest prefix which is also a suffix
	len := int(math.Min(float64(f[cnt]), math.Min(float64(n), float64(n))))
	// Output the result based on the calculated length
	fmt.Fprintln(out, 2*n-len)
	out.Flush() // Ensure all output is written
}

// Function to read a line of input from the input reader
func readLine(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Function to read an integer from the input reader
func readInt(in *bufio.Reader) int {
	var n int
	_, err := fmt.Fscanln(in, &n)
	if err != nil {
		panic(err)
	}
	return n
}

// Function to read a string from the input reader
func readString(in *bufio.Reader) string {
	var s string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Function to read a byte from the input reader
func readByte(in *bufio.Reader) byte {
	var b byte
	_, err := fmt.Fscanln(in, &b)
	if err != nil {
		panic(err)
	}
	return b
}

// Function to read a rune from the input reader
func readRune(in *bufio.Reader) rune {
	var r rune
	_, err := fmt.Fscanln(in, &r)
	if err != nil {
		panic(err)
	}
	return r
}

// Function to read a float from the input reader
func readFloat(in *bufio.Reader) float64 {
	var f float64
	_, err := fmt.Fscanln(in, &f)
	if err != nil {
		panic(err)
	}
	return f
}

// Function to read a boolean from the input reader
func readBool(in *bufio.Reader) bool {
	var b bool
	_, err := fmt.Fscanln(in, &b)
	if err != nil {
		panic(err)
	}
	return b
}

// Function to read a string array from the input reader
func readStringArray(in *bufio.Reader) []string {
	var s []string
	_, err := fmt.Fscanln(in, &s)
	if err != nil {
		panic(err)
	}
	return s
}

// Function to read an integer array from the input reader
func readIntArray(in *bufio.Reader) []int {
	var a []int
	_, err := fmt.Fscanln(in, &a)
	if err != nil {
		panic(err)
	}
	return a
}

// Function to read a byte array from the input reader
func readByteArray(in *bufio.Reader) []byte {
	var a []byte
	_, err := fmt.Fscanln(in, &a)
	if err != nil {
		panic(err)
	}
	return a
}

// Function to read a rune array from the input reader
func readRuneArray(in *bufio.Reader) []rune {
	var a []rune
	_, err := fmt.Fscanln(in, &a)
	if err != nil {
		panic(err)
	}
	return a
}

// Function to read a float array from the input reader
func readFloatArray(in *bufio.Reader) []float64 {
	var a []float64
	_, err := fmt.Fscanln(in, &a)
	if err != nil {
		panic(err)
	}
	return a
}

// Function to read a boolean array from the input reader
func readBoolArray(in *bufio.Reader) []bool {
	var a []bool
	_, err := fmt.Fscanln(in, &a)
	if err != nil {
		panic(err)
	}
	return a
}

// Function to read a 2D string array from the input reader
func read2DStringArray(in *bufio.Reader, n int) [][]string {
	var a [][]string
	for i := 0; i < n; i++ {
		a = append(a, readStringArray(in))
	}
	return a
}

// Function to read a 2D integer array from the input reader
func read2DIntArray(in *bufio.Reader, n int) [][]int {
	var a [][]int
	for i := 0; i < n; i++ {
		a = append(a, readIntArray(in))
	}
	return a
}

// Function to read a 2D byte array from the input reader
func read2DByteArray(in *bufio.Reader, n int) [][]byte {
	var a [][]byte
	for i := 0; i < n; i++ {
		a = append(a, readByteArray(in))
	}
	return a
}

// Function to read a 2D rune array from the input reader
func read2DRuneArray(in *bufio.Reader, n int) [][]rune {
	var a [][]rune
	for i := 0; i < n; i++ {
		a = append(a, readRuneArray(in))
	}
	return a
}

// Function to read a 2D float array from the input reader
func read2DFloatArray(in *bufio.Reader, n int) [][]float64 {
	var a [][]float64
	for i := 0; i < n; i++ {
		a = append(a, readFloatArray(in))
	}
	return a
}

// Function to read a 2D boolean array from the input reader
func read2DBoolArray(in *bufio.Reader, n int) [][]bool {
	var a [][]bool
	for i := 0; i < n; i++ {
		a = append(a, readBoolArray(in))
	}
	return a
}

// Function to read a 3D string array from the input reader
func read3DStringArray(in *bufio.Reader, n, m int) [][][]string {
	var a [][][]string
	for i := 0; i < n; i++ {
		a = append(a, read2DStringArray(in, m))
	}
	return a
}

// Function to read a 3D integer array from the input reader
func read3DIntArray(in *bufio.Reader, n, m int) [][][]int {
	var a [][][]int
	for i := 0; i < n; i++ {
		a = append(a, read2DIntArray(in, m))
	}
	return a
}

// Function to read a 3D byte array from the input reader
func read3DByteArray(in *bufio.Reader, n, m int) [][][]byte {
	var a [][][]byte
	for i := 0; i < n; i++ {
		a = append(a, read2DByteArray(in, m))
	}
	return a
}

// Function to read a 3D rune array from the input reader
func read3DRuneArray(in *bufio.Reader, n, m int) [][][]rune {
	var a [][][]rune
	for i := 0; i < n; i++ {
		a = append(a, read2DRuneArray(in, m))
	}
	return a
}

// Function to read a 3D float array from the input reader
func read3DFloatArray(in *bufio.Reader, n, m int) [][][]float64 {
	var a [][][]float64
	for i := 0; i < n; i++ {
		a = append(a, read2DFloatArray(in, m))
	}
	return a
}

// Function to read a 3D boolean array from the input reader
func read3DBoolArray(in *bufio.Reader, n, m int) [][][]bool {
	var a [][][]bool
	for i := 0; i < n; i++ {
		a = append(a, read2DBoolArray(in, m))
	}
	return a
}

// Function to read a 4D string array from the input reader
func read4DStringArray(in *bufio.Reader, n, m, o int) [][][][]string {
	var a [][][][]string
	for i := 0; i < n; i++ {
		a = append(a, read3DStringArray(in, m, o))
	}
	return a
}

// Function to read a 4D integer array from the input reader
func read4DIntArray(in *bufio.Reader, n, m, o int) [][][][]int {
	var a [][][][]int
	for i := 0; i < n; i++ {
		a = append(a, read3DIntArray(in, m, o))
	}
	return a
}

// Function to read a 4D byte array from the input reader
func read4DByteArray(in *bufio.Reader, n, m, o int) [][][][]byte {
	var a [][][][]byte
	for i := 0; i < n; i++ {
		a = append(a, read3DByteArray(in, m, o))
	}
	return a
}

// Function to read a 4D rune array from the input reader
func read4DRuneArray(in *bufio.Reader, n, m, o int) [][][][]rune {
	var a [][][][]rune
	for i := 0; i < n; i++ {
		a = append(a, read3DRuneArray(in, m, o))
	}
	return a
}

// Function to read a 4D float array from the input reader
func read4DFloatArray(in *bufio.Reader, n, m, o int) [][][][]float64 {
	var a [][][][]float64
	for i := 0; i < n; i++ {
		a = append(a, read3DFloatArray(in, m, o))
	}
	return a
}

// Function to read a 4D boolean array from the input reader
func read4DBoolArray(in *bufio.Reader, n, m, o int) [][][][]bool {
	var a [][][][]bool
	for i := 0; i < n; i++ {
		a = append(a, read3DBoolArray(in, m, o))
	}
	return a
}

// Function to read a 5D string array from the input reader
func read5DStringArray(in *bufio.Reader, n, m, o, p int) [][][][][]string {
	var a [][][][][]string
	for i := 0; i < n; i++ {
		a = append(a, read4DStringArray(in, m, o, p))
	}
	return a
}

// Function to read a 5D integer array from the input reader
func read5DIntArray(in *bufio.Reader, n, m, o, p int) [][][][][]int {
	var a [][][][][]int
	for i := 0; i < n; i++ {
		a = append(a, read4DIntArray(in, m, o, p))
	}
	return a
}

// Function to read a 5D byte array from the input reader
func read5DByteArray(in *bufio.Reader, n, m, o, p int) [][][][][]byte {
	var a [][][][][]byte
	for i := 0; i < n; i++ {
		a = append(a, read4DByteArray(in, m, o, p))
	}
	return a
}

// Function to read a 5D rune array from the input reader
func read5DRuneArray(in *bufio.Reader, n, m, o, p int) [][][][][]rune {
	var a [][][][][]rune
	for i := 0; i < n; i++ {
		a = append(a, read4DRuneArray(in, m, o, p))
	}
	return a
}

// Function to read a 5D float array from the input reader
func read5DFloatArray(in *bufio.Reader, n, m, o, p int) [][][][][]float64 {
	var a [][][][][]float64
	for i := 0; i < n; i++ {
		a = append(a, read4DFloatArray(in, m, o, p))
	}
	return a
}

// Function to read a 5D boolean array from the input reader
func read5DBoolArray(in *bufio.Reader, n, m, o, p int) [][][][][]bool {
	var a [][][][][]bool
	for i := 0; i < n; i++ {
		a = append(a, read4DBoolArray(in, m, o, p))
	}
	return a
}

// Function to read a 6D string array from the input reader
func read6DStringArray(in *bufio.Reader, n, m, o, p, q int) [][][][][][]string {
	var a [][][][][][]string
	for i := 0; i < n; i++ {
		a = append(a, read5DStringArray(in, m, o, p, q))
	}
	return a
}

// Function to read a 6D integer array from the input reader
func read6DIntArray(in *bufio.Reader, n, m, o, p, q int) [][][][][][]