
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create an instance of FastScanner to read input efficiently
	input := FastScanner{}

	// Read the number of integers
	n := input.nextInt()

	// Create a HashMap to store the frequency of each integer
	map := make(map[int]int)

	// Read n integers and update their counts in the hash map
	for i := 0; i < n; i++ {
		val := input.nextInt()
		map[val] = map[val] + 1
	}

	// Initialize max to the smallest possible integer value
	max := int(^uint(0) >> 1)

	// Iterate through the hash map to find the maximum count
	for _, value := range map {
		max = maxInt(max, value)
	}

	// Print the maximum count and the size of the hash map
	fmt.Println(max, len(map))
}

// Utility class to read input efficiently
type FastScanner struct {
	br *bufio.Reader
	st *strings.Reader
}

// Method to read the next token
func (f *FastScanner) next() string {
	for !f.st.Scan() {
		f.st = bufio.NewReader(f.br)
	}
	return f.st.Text()
}

// Method to read the next integer
func (f *FastScanner) nextInt() int {
	return int(f.nextInt64())
}

// Method to read the next long
func (f *FastScanner) nextInt64() int64 {
	return int64(f.nextInt64())
}

// Method to read the next double
func (f *FastScanner) nextDouble() float64 {
	return float64(f.nextDouble())
}

// Method to read the next line
func (f *FastScanner) nextLine() string {
	return f.next()
}

// Method to find the maximum of two integers
func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Method to find the maximum of two longs
func maxInt64(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// Method to find the maximum of two doubles
func maxDouble(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}

// Method to find the maximum of two strings
func maxString(a, b string) string {
	if a > b {
		return a
	}
	return b
}

// Method to find the minimum of two integers
func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Method to find the minimum of two longs
func minInt64(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// Method to find the minimum of two doubles
func minDouble(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

// Method to find the minimum of two strings
func minString(a, b string) string {
	if a < b {
		return a
	}
	return b
}

// Method to find the absolute value of an integer
func absInt(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// Method to find the absolute value of a long
func absInt64(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

// Method to find the absolute value of a double
func absDouble(a float64) float64 {
	if a < 0 {
		return -a
	}
	return a
}

// Method to find the absolute value of a string
func absString(a string) string {
	if a < 0 {
		return -a
	}
	return a
}

// Method to find the sum of two integers
func sumInt(a, b int) int {
	return a + b
}

// Method to find the sum of two longs
func sumInt64(a, b int64) int64 {
	return a + b
}

// Method to find the sum of two doubles
func sumDouble(a, b float64) float64 {
	return a + b
}

// Method to find the sum of two strings
func sumString(a, b string) string {
	return a + b
}

// Method to find the difference of two integers
func diffInt(a, b int) int {
	return a - b
}

// Method to find the difference of two longs
func diffInt64(a, b int64) int64 {
	return a - b
}

// Method to find the difference of two doubles
func diffDouble(a, b float64) float64 {
	return a - b
}

// Method to find the difference of two strings
func diffString(a, b string) string {
	return a - b
}

// Method to find the product of two integers
func prodInt(a, b int) int {
	return a * b
}

// Method to find the product of two longs
func prodInt64(a, b int64) int64 {
	return a * b
}

// Method to find the product of two doubles
func prodDouble(a, b float64) float64 {
	return a * b
}

// Method to find the product of two strings
func prodString(a, b string) string {
	return a * b
}

// Method to find the quotient of two integers
func quotInt(a, b int) int {
	return a / b
}

// Method to find the quotient of two longs
func quotInt64(a, b int64) int64 {
	return a / b
}

// Method to find the quotient of two doubles
func quotDouble(a, b float64) float64 {
	return a / b
}

// Method to find the quotient of two strings
func quotString(a, b string) string {
	return a / b
}

// Method to find the remainder of two integers
func remInt(a, b int) int {
	return a % b
}

// Method to find the remainder of two longs
func remInt64(a, b int64) int64 {
	return a % b
}

// Method to find the remainder of two doubles
func remDouble(a, b float64) float64 {
	return a % b
}

// Method to find the remainder of two strings
func remString(a, b string) string {
	return a % b
}

// Method to find the power of two integers
func powInt(a, b int) int {
	return int(math.Pow(float64(a), float64(b)))
}

// Method to find the power of two longs
func powInt64(a, b int64) int64 {
	return int64(math.Pow(float64(a), float64(b)))
}

// Method to find the power of two doubles
func powDouble(a, b float64) float64 {
	return math.Pow(a, b)
}

// Method to find the power of two strings
func powString(a, b string) string {
	return strconv.FormatFloat(math.Pow(a, b), 'f', -1, 64)
}

// Method to find the square root of an integer
func sqrtInt(a int) int {
	return int(math.Sqrt(float64(a)))
}

// Method to find the square root of a long
func sqrtInt64(a int64) int64 {
	return int64(math.Sqrt(float64(a)))
}

// Method to find the square root of a double
func sqrtDouble(a float64) float64 {
	return math.Sqrt(a)
}

// Method to find the square root of a string
func sqrtString(a string) string {
	return strconv.FormatFloat(math.Sqrt(a), 'f', -1, 64)
}

// Method to find the logarithm of an integer
func logInt(a int) int {
	return int(math.Log(float64(a)))
}

// Method to find the logarithm of a long
func logInt64(a int64) int64 {
	return int64(math.Log(float64(a)))
}

// Method to find the logarithm of a double
func logDouble(a float64) float64 {
	return math.Log(a)
}

// Method to find the logarithm of a string
func logString(a string) string {
	return strconv.FormatFloat(math.Log(a), 'f', -1, 64)
}

// Method to find the exponential of an integer
func expInt(a int) int {
	return int(math.Exp(float64(a)))
}

// Method to find the exponential of a long
func expInt64(a int64) int64 {
	return int64(math.Exp(float64(a)))
}

// Method to find the exponential of a double
func expDouble(a float64) float64 {
	return math.Exp(a)
}

// Method to find the exponential of a string
func expString(a string) string {
	return strconv.FormatFloat(math.Exp(a), 'f', -1, 64)
}

// Method to find the sine of an integer
func sinInt(a int) int {
	return int(math.Sin(float64(a)))
}

// Method to find the sine of a long
func sinInt64(a int64) int64 {
	return int64(math.Sin(float64(a)))
}

// Method to find the sine of a double
func sinDouble(a float64) float64 {
	return math.Sin(a)
}

// Method to find the sine of a string
func sinString(a string) string {
	return strconv.FormatFloat(math.Sin(a), 'f', -1, 64)
}

// Method to find the cosine of an integer
func cosInt(a int) int {
	return int(math.Cos(float64(a)))
}

// Method to find the cosine of a long
func cosInt64(a int64) int64 {
	return int64(math.Cos(float64(a)))
}

// Method to find the cosine of a double
func cosDouble(a float64) float64 {
	return math.Cos(a)
}

// Method to find the cosine of a string
func cosString(a string) string {
	return strconv.FormatFloat(math.Cos(a), 'f', -1, 64)
}

// Method to find the tangent of an integer
func tanInt(a int) int {
	return int(math.Tan(float64(a)))
}

// Method to find the tangent of a long
func tanInt64(a int64) int64 {
	return int64(math.Tan(float64(a)))
}

// Method to find the tangent of a double
func tanDouble(a float64) float64 {
	return math.Tan(a)
}

// Method to find the tangent of a string
func tanString(a string) string {
	return strconv.FormatFloat(math.Tan(a), 'f', -1, 64)
}

// Method to find the arcsine of an integer
func asinInt(a int) int {
	return int(math.Asin(float64(a)))
}

// Method to find the arcsine of a long
func asinInt64(a int64) int64 {
	return int64(math.Asin(float64(a)))
}

// Method to find the arcsine of a double
func asinDouble(a float64) float64 {
	return math.Asin(a)
}

// Method to find the arcsine of a string
func asinString(a string) string {
	return strconv.FormatFloat(math.Asin(a), 'f', -1, 64)
}

// Method to find the arccosine of an integer
func acosInt(a int) int {
	return int(math.Acos(float64(a)))
}

// Method to find the arccosine of a long
func acosInt64(a int64) int64 {
	return int64(math.Acos(float64(a)))
}

// Method to find the arccosine of a double
func acosDouble(a float64) float64 {
	return math.Acos(a)
}

// Method to find the arccosine of a string
func acosString(a string) string {
	return strconv.FormatFloat(math.Acos(a), 'f', -1, 64)
}

// Method to find the arctangent of an integer
func atanInt(a int) int {
	return int(math.Atan(float64(a)))
}

// Method to find the arctangent of a long
func atanInt64(a int64) int64 {
	return int64(math.Atan(float64(a)))
}

// Method to find the arctangent of a double
func atanDouble(a float64) float64 {
	return math.Atan(a)
}

// Method to find the arctangent of a string
func atanString(a string) string {
	return strconv.FormatFloat(math.Atan(a), 'f', -1, 64)
}

// Method to find the hyperbolic sine of an integer
func sinhInt(a int) int {
	return int(math.Sinh(float64(a)))
}

// Method to find the hyperbolic sine of a long
func sinhInt64(a int64) int64 {
	return int64(math.Sinh(float64(a)))
}

// Method to find the hyperbolic sine of a double
func sinhDouble(a float64) float64 {
	return math.Sinh(a)
}

// Method to find the hyperbolic sine of a string
func sinhString(a string) string {
	return strconv.FormatFloat(math.Sinh(a), 'f', -1, 64)
}

// Method to find the hyperbolic cosine of an integer
func coshInt(a int) int {
	return int