/*
URL:
https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_b
*/


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

//fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

//str := ReadString()
//i := ReadInt()
//X := ReadIntSlice(n)
//S := ReadRuneSlice()
//a := ReadFloat64()
//A := ReadFloat64Slice(n)

//str := ZeroPaddingRuneSlice(num, 32)
//str := PrintIntsLine(X...)

/*******************************************************************/

// Main function
func main() {
	var a, b, c, k int
	var r, g, c int
	a, b, c = ReadInt3() // Read three integers a, b, and c.
	k = ReadInt()        // Read the integer k.

	// Generate all possible patterns of length k where each element is one of 0, 1, 2, or 3.
	patterns := DuplicatePatterns(new int[]{0, 1, 2, 3}, k)

	// Iterate through each pattern to check the condition.
	for _, P := range patterns {
		r, g, c = a, b, c // Initialize r, g, and b with a, b, and c respectively.
		for i := 0; i < len(P); i++ {
			if P[i] == 0 {
				continue // If the operation is 0, do nothing.
			} else if P[i] == 1 {
				r *= 2 // Double the value of r.
			} else if P[i] == 2 {
				g *= 2 // Double the value of g.
			} else if P[i] == 3 {
				c *= 2 // Double the value of c.
			}
		}

		// Check if the condition b > a and c > b is met.
		if g > r && c > g {
			fmt.Println("Yes") // Print "Yes" if the condition is met.
			return
		}
	}
	fmt.Println("No") // Print "No" if no pattern meets the condition.
}

// DuplicatePatterns generates all patterns of n^k of elems([]int).
func DuplicatePatterns(elems []int, k int) [][]int {
	return dupliRec(new int[]{}, elems, k)
}

// DFS function for DuplicatePatterns.
func dupliRec(pattern, elems []int, k int) [][]int {
	if len(pattern) == k {
		return new int[][]{pattern} // Return the pattern if its length equals k.
	}

	res := new int[][]{}
	for _, e := range elems {
		newPattern := make([]int, len(pattern))
		copy(newPattern, pattern)
		newPattern = append(newPattern, e) // Add the current element to the pattern.

		res = append(res, dupliRec(newPattern, elems, k)...) // Recursively generate patterns.
	}

	return res
}

/*******************************************************************/

/*********** I/O ***********/

var (
	// ReadString returns a WORD string.
	ReadString func() string
	stdout     *bufio.Writer
)

// newReadString initializes a new scanner and returns a function that reads a string.
func newReadString(ior io.Reader, sf bufio.SplitFunc) func() string {
	r := bufio.NewScanner(ior)
	r.Buffer(make([]byte, 1024), int(1e+9)) // for Codeforces
	r.Split(sf)

	return func() string {
		if!r.Scan() {
			panic("Scan failed")
		}
		return r.Text()
	}
}

// ReadInt returns an integer.
func ReadInt() int {
	return int(readInt64())
}
func ReadInt2() (int, int) {
	return int(readInt64()), int(readInt64())
}
func ReadInt3() (int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64())
}
func ReadInt4() (int, int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64()), int(readInt64())
}

// ReadInt64 returns as integer as int64.
func ReadInt64() int64 {
	return readInt64()
}
func ReadInt64_2() (int64, int64) {
	return readInt64(), readInt64()
}
func ReadInt64_3() (int64, int64, int64) {
	return readInt64(), readInt64(), readInt64()
}
func ReadInt64_4() (int64, int64, int64, int64) {
	return readInt64(), readInt64(), readInt64(), readInt64()
}

func readInt64() int64 {
	i, err := strconv.ParseInt(ReadString(), 0, 64)
	if err!= nil {
		panic(err.Error())
	}
	return i
}

// ReadIntSlice returns an integer slice that has n integers.
func ReadIntSlice(n int) []int {
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[i] = ReadInt()
	}
	return b
}

// ReadInt64Slice returns as int64 slice that has n integers.
func ReadInt64Slice(n int) []int64 {
	b := make([]int64, n)
	for i := 0; i < n; i++ {
		b[i] = ReadInt64()
	}
	return b
}

// ReadFloat6 returns an float64.
func ReadFloat6() float64 {
	return float64(readFloat64())
}

func readFloat64() float64 {
	f, err := strconv.ParseFloat(ReadString(), 64)
	if err!= nil {
		panic(err.Error())
	}
	return f
}

// ReadFloatSlice returns an float64 slice that has n float64.
func ReadFloat6Slice(n int) []float64 {
	b := make([]float64, n)
	for i := 0; i < n; i++ {
		b[i] = ReadFloat6()
	}
	return b
}

// ReadRuneSlice returns a rune slice.
func ReadRuneSlice() []rune {
	return []rune(ReadString())
}

/*********** Debugging ***********/

// ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding.
// For debugging use.
func ZeroPaddingRuneSlice(n, digitsNum int) []rune {
	sn := fmt.Sprintf("%b", n)

	residualLength := digitsNum - len(sn)
	if residualLength <= 0 {
		return []rune(sn)
	}

	zeros := make([]rune, residualLength)
	for i := 0; i < len(zeros); i++ {
		zeros[i] = '0'
	}

	res := []rune{}
	res = append(res, zeros...)
	res = append(res, []rune(sn)...)

	return res
}

// Strtoi is a wrapper of strconv.Atoi().
// If strconv.Atoi() returns an error, Strtoi calls panic.
func Strtoi(s string) int {
	if i, err := strconv.Atoi(s); err!= nil {
		panic(errors.New("[argument error]: Strtoi only accepts integer string"))
	} else {
		return i
	}
}

// PrintIntsLine returns integers string delimited by a space.
func PrintIntsLine(A...int) string {
	res := []rune{}

	for i := 0; i < len(A); i++ {
		str := strconv.Itoa(A[i])
		res = append(res, []rune(str)...)

		if i!= len(A)-1 {
			res = append(res,'')
		}
	}

	return string(res)
}

// PrintIntsLine returns integers string delimited by a space.
func PrintInts64Line(A...int64) string {
	res := []rune{}

	for i := 0; i < len(A); i++ {
		str := strconv.FormatInt(A[i], 10) // 64bit int version
		res = append(res, []rune(str)...)

		if i!= len(A)-1 {
			res = append(res,'')
		}
	}

	return string(res)
}

// PrintfDebug is wrapper of fmt.Fprintf(os.Stderr, format, a...)
func PrintfDebug(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

// PrintfBufStdout is function for output strings to buffered os.Stdout.
// You may have to call stdout.Flush() finally.
func PrintfBufStdout(format string, a...interface{}) {
	fmt.Fprintf(stdout, format, a...)
}

