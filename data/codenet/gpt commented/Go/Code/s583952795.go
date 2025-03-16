package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	// "regexp"
)

// Pair struct to hold two values of any type
type Pair struct {
	p1, p2 interface{}
}

// Constants for buffer sizes
const (
	initialBufSize = 1e4 // Initial buffer size for scanner
	maxBufSize     = 1e8 // Maximum buffer size for scanner
)

// Global variables for input and output
var (
	scanner = bufio.NewScanner(os.Stdin) // Scanner for reading input
	writer  = bufio.NewWriter(os.Stdout)  // Writer for output
)

func main() {
	// Allocate buffer for scanner and set its maximum size
	buf := make([]byte, initialBufSize)
	scanner.Buffer(buf, maxBufSize)
	scanner.Split(bufio.ScanWords) // Set scanner to split input by words

	// Read two integers N and K from input
	N, K := readInt(), readInt()
	// Convert the number N from base 10 to base K
	s := TenToN(N, K)
	// Print the length of the resulting string
	fmt.Println(len(s))
}

// Function to convert a number from base 10 to base N
func TenToN(number int, n int) string {
	var s string // String to hold the result
	tmp := number // Temporary variable to hold the current number
	for {
		// Prepend the remainder of the division to the result string
		s = i2s(tmp%n) + s
		if tmp < n { // If the temporary number is less than the base, exit the loop
			break
		}
		tmp /= n // Divide the temporary number by the base
	}
	return s // Return the converted string
}

/*==========================================
 *             Library
 *==========================================*/

// Function to write a string to the output
func write(s string) {
	writer.WriteString(s)
}

// Function to flush the writer buffer to output
func print() {
	writer.Flush()
}

// Function to read a line of input
func readLine() (s string) {
	if scanner.Scan() {
		s = scanner.Text() // Get the text from the scanner
	}
	return s // Return the read line
}

// Function to read an integer from input
func readInt() (read int) {
	scanner.Scan() // Read the next input
	read, err := strconv.Atoi(scanner.Text()) // Convert the input to an integer
	if err != nil {
		panic(err) // Panic if there is an error in conversion
	}
	return // Return the read integer
}

// Function to read a float from input
func readFloat() (read float64) {
	scanner.Scan() // Read the next input
	read, err := strconv.ParseFloat(scanner.Text(), 64) // Convert the input to a float
	if err != nil {
		panic(err) // Panic if there is an error in conversion
	}
	return // Return the read float
}

// Function to read runes from input
func readRunes() (read []rune) {
	scanner.Scan() // Read the next input
	for _, v := range scanner.Text() {
		read = append(read, v) // Append each rune to the slice
	}
	return // Return the slice of runes
}

// Function to read a string from input
func readString() (read string) {
	scanner.Scan() // Read the next input
	read = scanner.Text() // Get the text from the scanner
	return // Return the read string
}

// Function to read a slice of strings from input
func readStrings() (read []string) {
	scanner.Scan() // Read the next input
	for _, v := range scanner.Text() {
		read = append(read, string(v)) // Append each character as a string to the slice
	}
	return // Return the slice of strings
}

// Function to convert a string to an integer
func s2i(s string) int {
	var intVal, e = strconv.Atoi(s) // Convert string to integer
	if e != nil {
		panic(e) // Panic if there is an error in conversion
	}
	return intVal // Return the integer value
}

// Function to convert an integer to a string
func i2s(i int) string {
	var strVal = strconv.Itoa(i) // Convert integer to string
	return strVal // Return the string value
}

// Function to convert a string to a float
func s2f(s string) float64 {
	var floatVal, e = strconv.ParseFloat(s, 64) // Convert string to float
	if e != nil {
		panic(e) // Panic if there is an error in conversion
	}
	return floatVal // Return the float value
}

// Function to calculate the sum of a slice of integers
func sum(i []int) int {
	sum := 0 // Initialize sum
	for _, val := range i {
		sum += val // Add each value to the sum
	}
	return sum // Return the total sum
}

// Function to split a string into a slice of strings
func split(s string) []string {
	return strings.Fields(s) // Split the string by whitespace and return the slice
}

// Function to convert a slice of strings to a slice of integers
func strAry2intAry(strs []string) []int {
	var ret = make([]int, 0, len(strs)) // Initialize the result slice
	for _, str := range strs {
		var intVal, e = strconv.Atoi(string(str)) // Convert each string to an integer
		if e != nil {
			panic(e) // Panic if there is an error in conversion
		}
		ret = append(ret, intVal) // Append the integer to the result slice
	}
	return ret // Return the slice of integers
}

// Function to convert a slice of integers to a slice of strings
func intAry2strAry(nums []int) []string {
	var ret = make([]string, 0, len(nums)) // Initialize the result slice
	for _, num := range nums {
		var strVal = strconv.Itoa(num) // Convert each integer to a string
		ret = append(ret, strVal) // Append the string to the result slice
	}
	return ret // Return the slice of strings
}

// Function to join a slice of strings into a single string
func ary2str(strs []string) string {
	return strings.Join(strs, " ") // Join the strings with a space and return
}

// Function to reverse a slice of integers
func reverse(res []int) []int {
	for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
		res[i], res[j] = res[j], res[i] // Swap elements to reverse the slice
	}
	return res // Return the reversed slice
}

// Function to initialize a slice with a given value
func initalize(res []int, init int) {
	if len(res) == 0 {
		return // Do nothing if the slice is empty
	}
	res[0] = init // Set the first element to the initial value
	for i := 0; i < len(res); i++ {
		copy(res[i:], res[:i]) // Copy elements to shift them
	}
}

// Example function for regular expressions (commented out)
// func regexpExample() {
//     // Your code here!
//     var str = "13:20"
//     r := regexp.MustCompile(`(\d+):(\d+)`)
//     fmt.Println(r.FindStringSubmatch(str))
// }

// Struct to hold medal counts for a country (commented out)
// type Country struct {
//     gold int
//     silver int
//     blonze int
// }

// // Example function for stable sorting (commented out)
// func stableSortExample() []Country{
//     var country = []Country {
//         {gold:1, silver:2, blonze:3},
//         {gold:1, silver:2, blonze:3},
//         {gold:1, silver:3, blonze:2},
//         {gold:1, silver:3, blonze:3},
//     }
//     sort.SliceStable(country, func(i, j int) bool { return country[i].blonze > country[j].blonze })
//     sort.SliceStable(country, func(i, j int) bool { return country[i].silver > country[j].silver })
//     sort.SliceStable(country, func(i, j int) bool { return country[i].gold > country[j].gold })
//     return country
// }
