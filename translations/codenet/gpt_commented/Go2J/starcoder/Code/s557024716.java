/*
URL:
https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_b
*/

package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)

/********** FAU standard libraries **********/

// Example of binary expression formatting
// System.out.printf("%64s\n", Integer.toBinaryString(n));

/********** I/O usage **********/

// To use the input and output streams, you must initialize them first.
// import java.io.*;

// To create a buffered reader and writer use:
// import java.io.BufferedWriter;
// import java.io.BufferedReader;
// import java.io.InputStreamReader;
// import java.io.OutputStreamWriter;

// To use the standard input and output streams for input and output,
// use System.in and System.out, respectively.
// import java.lang.*;

/********** Input **********/

// To read data from the input stream, use the following code:
// InputStream in = new FileInputStream("file.in"); // FileInputStream
// Reader in = new InputStreamReader(in); // InputStreamReader
// BufferedReader reader = new BufferedReader(in);

// To read the entire line, use the following code:
// String line = reader.readLine();

// To read input until the end of the line, use the following code:
// String line;
// while ((line = reader.readLine())!= null) {
//     // Do something with the line
// }

// To read a single word, use the following code:
// String word = reader.readLine();

// To read all the words until the end of the line, use the following code:
// String[] words = reader.readLine().split(" ");

// To read integer values, use the following code:
// Integer integer = Integer.parseInt(reader.readLine());
// int i = integer;

// To read float values, use the following code:
// Double d = Double.parseDouble(reader.readLine());
// float f = d.floatValue();

// To read long values, use the following code:
// Long l = Long.parseLong(reader.readLine());
// long lng = l.longValue();

/********** Output **********/

// To write data to the output stream, use the following code:
// OutputStream out = new FileOutputStream("file.out"); // FileOutputStream
// Writer out = new OutputStreamWriter(out); // OutputStreamWriter
// BufferedWriter writer = new BufferedWriter(out);

// To write the entire line, use the following code:
// writer.write(line);
// writer.newLine(); // Also appends a new line character

// To write a single word, use the following code:
// writer.write(word);
// writer.newLine(); // Also appends a new line character

// To write integer values, use the following code:
// writer.write(String.valueOf(i));
// writer.newLine(); // Also appends a new line character

// To write float values, use the following code:
// writer.write(String.valueOf(f));
// writer.newLine(); // Also appends a new line character

// To write long values, use the following code:
// writer.write(String.valueOf(lng));
// writer.newLine(); // Also appends a new line character

/********** Other usage **********/

// To convert an integer to a string, use the following code:
// String str = String.valueOf(i);

// To iterate over the characters of a string, use the following code:
// for (int i = 0; i < str.length(); i++) {
//     char c = str.charAt(i);
// }

/*******************************************************************/

// Constants for general use
const (
	MOD          = 1000000000 + 7 // Modulus value for calculations
	ALPHABET_NUM = 26              // Number of letters in the alphabet
	INF_INT64    = math.MaxInt64   // Maximum value for int64
	INF_BIT60    = 1 << 60         // 60-bit integer limit
	INF_INT32    = math.MaxInt32   // Maximum value for int32
	INF_BIT30    = 1 << 30         // 30-bit integer limit
	NIL          = -1              // Nil value for error handling

	// Constants for graph algorithms (Dijkstra, Prim, etc.)
	WHITE = 0 // Unvisited node
	GRAY  = 1 // Visited but not fully explored
	BLACK = 2 // Fully explored node
)

func init() {
	// Initialize input reading and output writing
	ReadString = newReadString(os.Stdin, bufio.ScanWords) // Set up reading words
	stdout = bufio.NewWriter(os.Stdout)                   // Initialize buffered output
}

var (
	a, b, c int // Variables to hold input values
	k       int // Variable to hold the number of patterns
)

func main() {
	// Read three integers and the number of patterns
	a, b, c = ReadInt3()
	k = ReadInt()

	// Generate all possible patterns of length k from the set {0, 1, 2, 3}
	patterns := DuplicatePatterns(new int[]{0, 1, 2, 3}, k)

	// Iterate through each generated pattern
	for _, P := range patterns {
		r, g, b := a, b, c // Initialize color values for each pattern
		// Apply the pattern to modify the color values
		for i := 0; i < len(P); i++ {
			if P[i] == 0 {
				continue // Skip if the pattern element is 0
			} else if P[i] == 1 {
				r *= 2 // Double the red value
			} else if P[i] == 2 {
				g *= 2 // Double the green value
			} else if P[i] == 3 {
				b *= 2 // Double the blue value
			}
		}

		// Check if the modified values satisfy the condition
		if g > r && b > g {
			fmt.Println("Yes") // Print "Yes" if the condition is met
			return
		}
	}
	fmt.Println("No") // Print "No" if no pattern satisfies the condition
}

// DuplicatePatterns returns all patterns of length k from the given elements.
func DuplicatePatterns(elems []int, k int) [][]int {
	return dupliRec(new int[]{}, elems, k) // Start the recursive pattern generation
}

// Recursive function to generate patterns
func dupliRec(pattern, elems []int, k int) [][]int {
	if len(pattern) == k {
		return [][]int{pattern} // Return the completed pattern
	}

	res := [][]int{} // Slice to hold the results
	// Iterate through each element to build patterns
	for _, e := range elems {
		newPattern := make([]int, len(pattern))
		copy(newPattern, pattern) // Copy the existing pattern
		newPattern = append(newPattern, e) // Append the new element

		// Recursively generate patterns with the new element added
		res = append(res, dupliRec(newPattern, elems, k)...)
	}

	return res // Return all generated patterns
}

/*******************************************************************/

/*********** I/O ***********/

var (
	// ReadString function to read a word string
	ReadString func() string
	stdout     *bufio.Writer // Buffered writer for output
)

// Function to create a new ReadString function with specified input reader and split function
func newReadString(ior io.Reader, sf bufio.SplitFunc) func() string {
	r := bufio.NewScanner(ior)
	r.Buffer(make([]byte, 1024), int(1e+9)) // Set buffer size for large inputs
	r.Split(sf) // Set the split function

	return func() string {
		if!r.Scan() {
			panic("Scan failed") // Panic if scanning fails
		}
		return r.Text() // Return the scanned text
	}
}

// ReadInt returns an integer from input.
func ReadInt() int {
	return int(readInt64()) // Read and convert to int
}

// ReadInt2 returns two integers from input.
func ReadInt2() (int, int) {
	return int(readInt64()), int(readInt64()) // Read two integers
}

// ReadInt3 returns three integers from input.
func ReadInt3() (int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64()) // Read three integers
}

// ReadInt4 returns four integers from input.
func ReadInt4() (int, int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64()), int(readInt64()) // Read four integers
}

// ReadInt64 returns an int64 from input.
func ReadInt64() int64 {
	return readInt64() // Read and return int64
}

// ReadInt64_2 returns two int64 values from input.
func ReadInt64_2() (int64, int64) {
	return readInt64(), readInt64() // Read two int64 values
}

// ReadInt64_3 returns three int64 values from input.
func ReadInt64_3() (int64, int64, int64) {
	return readInt64(), readInt64(), readInt64() // Read three int64 values
}

// ReadInt64_4 returns four int64 values from input.
func ReadInt64_4() (int64, int64, int64, int64) {
	return readInt64(), readInt64(), readInt64(), readInt64() // Read four int64 values
}

// Function to read an int64 from input and handle errors
func readInt64() int64 {
	i, err := strconv.ParseInt(ReadString(), 0, 64) // Parse input as int64
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i // Return the parsed int64
}

// ReadIntSlice returns a slice of integers of size n.
func ReadIntSlice(n int) []int {
	b := make([]int, n) // Create a slice of size n
	for i := 0; i < n; i++ {
		b[i] = ReadInt() // Read each integer into the slice
	}
	return b // Return the slice of integers
}

// ReadInt64Slice returns a slice of int64 values of size n.
func ReadInt64Slice(n int) []int64 {
	b := make([]int64, n) // Create a slice of size n
	for i := 0; i < n; i++ {
		b[i] = ReadInt64() // Read each int64 into the slice
	}
	return b // Return the slice of int64 values
}

// ReadFloat64 returns a float64 from input.
func ReadFloat64() float64 {
	return float64(readFloat64()) // Read and convert to float64
}

// Function to read a float64 from input and handle errors
func readFloat64() float64 {
	f, err := strconv.ParseFloat(ReadString(), 64) // Parse input as float64
	if err!= nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return f // Return the parsed float64
}

// ReadFloat64Slice returns a slice of float64 values of size n.
func ReadFloat64Slice(n int) []float64 {
	b := make([]float64, n) // Create a slice of size n
	for i := 0; i < n; i++ {
		b[i] = ReadFloat64() // Read each float64 into the slice
	}
	return b // Return the slice of float64 values
}

// ReadRuneSlice returns a slice of runes from input.
func ReadRuneSlice() []rune {
	return []rune(ReadString()) // Convert the input string to a slice of runes
}

/*********** Debugging ***********/

// ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding.
// For debugging use.
func ZeroPaddingRuneSlice(n, digitsNum int) []rune {
	sn := fmt.Sprintf("%b", n) // Convert integer to binary string

	residualLength := digitsNum - len(sn) // Calculate how many zeros to 