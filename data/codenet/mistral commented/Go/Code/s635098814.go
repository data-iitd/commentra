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

/*********** I/O ***********/

// Declare global variables for reading input and writing output.
var (
	// ReadString returns a WORD string.
	ReadString func() string
	stdout     *bufio.Writer
)

// Initialize the ReadString function and the stdout writer.
func init() {
	ReadString = newReadString(os.Stdin)
	stdout = bufio.NewWriter(os.Stdout)
}

// newReadString initializes a new scanner for reading words from the input.
func newReadString(ior io.Reader) func() string {
	r := bufio.NewScanner(ior)
	// Set the buffer size for the scanner.
	r.Buffer(make([]byte, 1024), int(1e+9)) // for Codeforces
	// Set the split function to scan words.
	r.Split(bufio.ScanWords)

	// Return a function that reads the next word from the scanner.
	return func() string {
		if !r.Scan() {
			panic("Scan failed")
		}
		return r.Text()
	}
}

// ReadInt returns an integer.
func ReadInt() int {
	return int(readInt64())
}

// ReadInt2 returns two integers.
func ReadInt2() (int, int) {
	return int(readInt64()), int(readInt64())
}

// ReadInt3 returns three integers.
func ReadInt3() (int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64())
}

// ReadInt4 returns four integers.
func ReadInt4() (int, int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64()), int(readInt64())
}

// ReadInt64 returns an integer as int64.
func ReadInt64() int64 {
	return readInt64()
}

// ReadInt64_2 returns two int64 integers.
func ReadInt64_2() (int64, int64) {
	return readInt64(), readInt64()
}

// ReadInt64_3 returns three int64 integers.
func ReadInt64_3() (int64, int64, int64) {
	return readInt64(), readInt64(), readInt64()
}

// ReadInt64_4 returns four int64 integers.
func ReadInt64_4() (int64, int64, int64, int64) {
	return readInt64(), readInt64(), readInt64(), readInt64()
}

// readInt64 reads a string and converts it to int64.
func readInt64() int64 {
	i, err := strconv.ParseInt(ReadString(), 0, 64)
	if err != nil {
		panic(err.Error())
	}
	return i
}

// ReadIntSlice returns a slice of integers of size n.
func ReadIntSlice(n int) []int {
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[i] = ReadInt()
	}
	return b
}

// ReadInt64Slice returns a slice of int64 integers of size n.
func ReadInt64Slice(n int) []int64 {
	b := make([]int64, n)
	for i := 0; i < n; i++ {
		b[i] = ReadInt64()
	}
	return b
}

// ReadFloat64 returns a float64.
func ReadFloat64() float64 {
	return float64(readFloat64())
}

// readFloat64 reads a string and converts it to float64.
func readFloat64() float64 {
	f, err := strconv.ParseFloat(ReadString(), 64)
	if err != nil {
		panic(err.Error())
	}
	return f
}

// ReadFloat64Slice returns a slice of float64 of size n.
func ReadFloat64Slice(n int) []float64 {
	b := make([]float64, n)
	for i := 0; i < n; i++ {
		b[i] = ReadFloat64()
	}
	return b
}

// ReadRuneSlice returns a slice of runes from the input string.
func ReadRuneSlice() []rune {
	return []rune(ReadString())
}

/*********** Debugging ***********/

// ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding for debugging.
func ZeroPaddingRuneSlice(n, digitsNum int) []rune {
	sn := fmt.Sprintf("%b", n)

	residualLength := digitsNum - len(sn)
	if residualLength <= 0 {
		return []rune(sn)
	}

	// Create a slice of runes for the zero padding.
	zeros := make([]rune, residualLength)
	for i := 0; i < len(zeros); i++ {
		zeros[i] = '0'
	}

	// Combine the zeros and the binary representation.
	res := []rune{}
	res = append(res, zeros...)
	res = append(res, []rune(sn)...)

	return res
}

/*********** DP sub-functions ***********/

// ChMin updates the value pointed to by updatedValue if the target is smaller.
func ChMin(updatedValue *int, target int) bool {
	if *updatedValue > target {
		*updatedValue = target
		return true
	}
	return false
}

// ChMax updates the value pointed to by updatedValue if the target is larger.
func ChMax(updatedValue *int, target int) bool {
	if *updatedValue < target {
		*updatedValue = target
		return true
	}
	return false
}

// NthBit returns the nth bit value of an integer.
func NthBit(num, nth int) int {
	return num >> uint(nth) & 1
}

// OnBit returns the integer with the nth bit set to ON.
func OnBit(num, nth int) int {
	return num | (1 << uint(nth))
}

// OffBit returns the integer with the nth bit set to OFF.
func OffBit(num, nth int) int {
	return num & ^(1 << uint(nth))
}

// PopCount returns the number of ON bits in an integer.
func PopCount(num int) int {
	res := 0

	for i := 0; i < 70; i++ {
		if ((num >> uint(i)) & 1) == 1 {
			res++
		}
	}

	return res
}

/*********** Arithmetic ***********/

// Max returns the maximum integer from a set of integers.
func Max(integers ...int) int {
	m := integers[0]
	for i, integer := range integers {
		if i == 0 {
			continue
		}
		if m < integer {
			m = integer
		}
	}
	return m
}

// Min returns the minimum integer from a set of integers.
func Min(integers ...int) int {
	m := integers[0]
	for i, integer := range integers {
		if i == 0 {
			continue
		}
		if m > integer {
			m = integer
		}
	}
	return m
}

// DigitSum returns the sum of the digits of a positive integer.
func DigitSum(n int) int {
	if n < 0 {
		return -1
	}

	res := 0

	for n > 0 {
		res += n % 10
		n /= 10
	}

	return res
}

// DigitNumOfDecimal returns the number of digits in a non-negative integer.
func DigitNumOfDecimal(n int) int {
	res := 0

	for n > 0 {
		n /= 10
		res++
	}

	return res
}

// Sum returns the sum of multiple integers.
func Sum(integers ...int) int {
	s := 0

	for _, i := range integers {
		s += i
	}

	return s
}

// Kiriage returns the ceiling of a/b for non-negative a and positive b.
func Kiriage(a, b int) int {
	return (a + (b - 1)) / b
}

// PowInt calculates a power using binary exponentiation.
func PowInt(a, e int) int {
	if a < 0 || e < 0 {
		panic(errors.New("[argument error]: PowInt does not accept negative integers"))
	}

	if e == 0 {
		return 1
	}

	if e%2 == 0 {
		halfE := e / 2
		half := PowInt(a, halfE)
		return half * half
	}

	return a * PowInt(a, e-1)
}

// AbsInt returns the absolute value of an integer.
func AbsInt(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// Gcd returns the Greatest Common Divisor of two natural numbers using the Euclidean Algorithm.
func Gcd(a, b int) int {
	if a <= 0 || b <= 0 {
		panic(errors.New("[argument error]: Gcd only accepts two NATURAL numbers"))
	}
	if a < b {
		a, b = b, a
	}

	// Euclidean Algorithm
	for b > 0 {
		div := a % b
		a, b = b, div
	}

	return a
}

// Lcm returns the Least Common Multiple of two natural numbers.
func Lcm(a, b int) int {
	if a <= 0 || b <= 0 {
		panic(errors.New("[argument error]: Gcd only accepts two NATURAL numbers"))
	}

	// Calculate LCM using GCD
	gcd := Gcd(a, b)

	// Return the LCM while avoiding overflow.
	return (a / gcd) * b
}

// Strtoi converts a string to an integer and panics on error.
func Strtoi(s string) int {
	if i, err := strconv.Atoi(s); err != nil {
		panic(errors.New("[argument error]: Strtoi only accepts integer string"))
	} else {
		return i
	}
}

// PrintIntsLine returns a string of integers delimited by a space.
func PrintIntsLine(A ...int) string {
	res := []rune{}

	for i := 0; i < len(A); i++ {
		str := strconv.Itoa(A[i])
		res = append(res, []rune(str)...)

		if i != len(A)-1 {
			res = append(res, ' ')
		}
	}

	return string(res)
}

/********** FAU standard libraries **********/

//fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

// Example usage of the I/O functions:
// str := ReadString()
// i := ReadInt()
// X := ReadIntSlice(n)
// S := ReadRuneSlice()
// a := ReadFloat64()
// A := ReadFloat64Slice(n)

// Example usage of debugging functions:
// str := ZeroPaddingRuneSlice(num, 32)
// str := PrintIntsLine(X...)

/*******************************************************************/

// Define constants for the program.
const MOD = 1000000000 + 7
const ALPHABET_NUM = 26
const INF_INT64 = math.MaxInt64
const INF_BIT60 = 1 << 60

// Declare memoization array and string variable.
var memo [ALPHABET_NUM]int
var str string

func main() {
	var sc = bufio.NewScanner(os.Stdin)

	// Read input until EOF.
	for {
		if sc.Scan() {
			str = sc.Text()
			S := []rune(str)
			if len(S) == 0 {
				break
			}
			// Count occurrences of each letter.
			for i := 0; i < len(S); i++ {
				c := S[i]

				if 'a' <= c && c <= 'z' {
					// Increment count for lowercase letters.
					memo[c-'a']++
				} else if 'A' <= c && c <= 'Z' {
					// Increment count for uppercase letters.
					memo[c-'A']++
				} else {
					// Ignore non-alphabet characters.
					continue
				}
			}
		} else {
			break
		}
	}

	// Print the count of each letter.
	for i := 0; i < ALPHABET_NUM; i++ {
		fmt.Printf("%c : %d\n", rune(i)+'a', memo[i])
	}
}

// MODはとったか？
// 遷移だけじゃなくて最後の最後でちゃんと取れよ？

/*******************************************************************/
