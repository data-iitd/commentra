package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	// "regexp" // Unused import, remove it
)

type Pair struct {
	p1, p2 interface{}
}

const (
	initialBufSize = 1e4
	maxBufSize     = 1e8
)

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

// Main function entry point
func main() {
	buf := make([]byte, initialBufSize) // Initialize input buffer
	scanner.Buffer(buf, maxBufSize)      // Set buffer for scanner
	scanner.Split(bufio.ScanWords)       // Split input by words

	// Read input numbers N and K
	N, K := readInt(), readInt()

	// Calculate the base-10 representation of N up to digit count K
	s := TenToN(N, K)

	// Print the length of the calculated string
	fmt.Println(len(s))
}

// Function to convert a number to its base-10 string representation
// with digit count K
func TenToN(number int, n int) string {
	var s string
	tmp := number // Initialize temporary variable

	// Repeat the following process until the number becomes less than N
	for {
		// Append the remainder of the division by N to the result string
		s = i2s(tmp%n) + s

		// If the number is less than N, break the loop
		if tmp < n {
			break
		}

		// Divide the number by N
		tmp /= n
	}

	// Return the result string
	return s
}

// Helper functions

// Write a string to the output writer
func write(s string) {
	writer.WriteString(s)
}

// Print the content of the output writer
func print() {
	writer.Flush()
}

// Read a line from the input scanner
func readLine() (s string) {
	if scanner.Scan() {
		s = scanner.Text()
	}
	return s
}

// Read an integer from the input scanner
func readInt() (read int) {
	scanner.Scan()
	read, err := strconv.Atoi(scanner.Text())
	if err != nil {
		panic(err)
	}
	return
}

// Read a float from the input scanner
func readFloat() (read float64) {
	scanner.Scan()
	read, err := strconv.ParseFloat(scanner.Text(), 64)
	if err != nil {
		panic(err)
	}
	return
}

// Read runes from the input scanner
func readRunes() (read []rune) {
	scanner.Scan()
	for _, v := range scanner.Text() {
		read = append(read, v)
	}
	return
}

// Read a string from the input scanner
func readString() (read string) {
	scanner.Scan()
	read = scanner.Text()
	return
}

// Read multiple strings from the input scanner
func readStrings() (read []string) {
	scanner.Scan()
	for _, v := range scanner.Text() {
		read = append(read, string(v))
	}
	return
}

// Convert an integer to its string representation
func s2i(s string) int {
	var intVal, e = strconv.Atoi(s)
	if e != nil {
		panic(e)
	}
	return intVal
}

// Convert a string to an integer
func i2s(i int) string {
	var strVal = strconv.Itoa(i)
	return strVal
}

// Sum all integers in an integer slice
func sum(i []int) int {
	sum := 0
	for _, val := range i {
		sum += val
	}
	return sum
}

// Split a string by a delimiter
func split(s string) []string {
	return strings.Fields(s)
}

// Convert a string array to an integer array
func strAry2intAry(strs []string) []int {
	var ret = make([]int, 0, len(strs))
	for _, str := range strs {
		var intVal, e = strconv.Atoi(string(str))
		if e != nil {
			panic(e)
		}
		ret = append(ret, intVal)
	}
	return ret
}

// Convert an integer array to a string array
func intAry2strAry(nums []int) []string {
	var ret = make([]string, 0, len(nums))
	for _, num := range nums {
		var strVal = strconv.Itoa(num)
		ret = append(ret, strVal)
	}
	return ret
}

// Join multiple strings into a single string with a delimiter
func ary2str(strs []string) string {
	return strings.Join(strs, " ")
}

// Reverse the order of elements in an integer slice
func reverse(res []int) []int {
	for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
		res[i], res[j] = res[j], res[i]
	}
	return res
}

// Initialize an integer slice with a given value
func initalize(res []int, init int) {
	if len(res) == 0 {
		return
	}
	res[0] = init
	for i := 0; i < len(res); i++ {
		copy(res[i:], res[:i])
	}
}

// Unused function, remove it
// func regexpExample() {
// 	// Your code here!
// 	var str = "13:20"
// 	r := regexp.MustCompile(`(\d+):(\d+)`)
// 	fmt.Println(r.FindStringSubmatch(str))
// }
