// Package main is the entry point of the program
package main

import (
	// Importing necessary packages
	"bufio"
	"fmt"
	"math"
	"os"
	"reflect"
	"sort"
	"strconv"
	"strings"
	// "regexp" // Uncomment this line if you want to use regexp package
)

// Define a custom type 'pair' for sorting
type pair struct {
	index  int64 // Index for sorting
	p1, p2 interface{} // Two elements to be compared
}

// Define a slice type 'pairs' for sorting 'pair' type
type pairs []pair

// Implement sort.Interface methods for 'pairs' type
func (slice pairs) Len() int {
	return len(slice)
}

func (slice pairs) Less(i, j int) bool {
	return slice[i].index < slice[j].index
}

func (slice pairs) Swap(i, j int) {
	slice[i], slice[j] = slice[j], slice[i]
}

// Define a custom type 'Int64Slice' for sorting int64 slices
type Int64Slice []int64

// Implement sort.Interface methods for 'Int64Slice' type
func (slice Int64Slice) Len() int {
	return len(slice)
}

func (slice Int64Slice) Less(i, j int) bool {
	return slice[i] < slice[j]
}

func (slice Int64Slice) Swap(i, j int) {
	slice[i], slice[j] = slice[j], slice[i]
}

// Define some constants
const (
	initialBufSize = 1e4 // Initial buffer size for bufio.NewScanner
	maxBufSize     = 1e8 // Maximum buffer size for bufio.NewScanner
	INF            = 1e8 // Infinite value for some calculations
)

// Initialize some global variables
var (
	scanner = bufio.NewScanner(os.Stdin) // Input scanner
	writer  = bufio.NewWriter(os.Stdout) // Output writer
	di      = []int64{-1, 0, 1, 0}       // Direction vectors for 2D grid traversal
	dj      = []int64{0, -1, 0, 1}       // Direction vectors for 2D grid traversal
)

// Main function
func main() {
	// Initialize the buffer with the given size
	buf := make([]byte, initialBufSize)
	scanner.Buffer(buf, maxBufSize)
	scanner.Split(bufio.ScanWords) // Split input by words

	// Read input A, B, and C
	A, B, C := readInt(), readInt(), readInt()

	// Check if C is within the range of A and B
	if C >= A && C <= B {
		fmt.Println("Yes") // Print "Yes" if condition is true
	} else {
		fmt.Println("No")  // Print "No" if condition is false
	}
}

// Helper functions for reading input
func NextPermutation(x sort.Interface) bool {
	// Implementation of next permutation algorithm for sorting
}

func doubleAry(h int64, w int64, init int64) (res [][]int64) {
	// Function to initialize a 2D int64 array with given dimensions and initial value
}

func aryEq(a []int64, b []int64) bool {
	// Function to check if two arrays are equal
}

func clone(n []int64) (r []int64) {
	// Function to clone a slice
}

func write(s string) {
	// Function to write a string to the output writer
}

func print() {
	// Function to flush the output writer
}

func readLine() (s string) {
	// Function to read a line from the input scanner
}

func readInt() (read int64) {
	// Function to read an integer from the input scanner
}

func readFloat() (read float64) {
	// Function to read a float from the input scanner
}

func readRunes() (read []rune) {
	// Function to read a rune slice from the input scanner
}

func readString() (read string) {
	// Function to read a string from the input scanner
}

func readStrings() (read []string) {
	// Function to read a string slice from the input scanner
}

func s2i(s string) int64 {
	// Function to convert a string to an integer
}

func i2s(i int64) string {
	// Function to convert an integer to a string
}

func abs(i int64) int64 {
	// Function to get the absolute value of an integer
}

func max(a ...int64) int64 {
	// Function to get the maximum value from a slice of integers
}

func min(a ...int64) int64 {
	// Function to get the minimum value from a slice of integers
}

func sum(i []int64) int64 {
	// Function to get the sum of elements in a slice of integers
}

func split(s string) []string {
	// Function to split a string into a slice of strings using space as delimiter
}

func strAry2intAry(strs []string) []int64 {
	// Function to convert a slice of strings to a slice of integers
}

func intAry2strAry(nums []int64) []string {
	// Function to convert a slice of integers to a slice of strings
}

func ary2str(strs []string) string {
	// Function to join a slice of strings into a single string using space as delimiter
}

func reverse(res []int64) []int64 {
	// Function to reverse the order of elements in a slice
}

func reverseStr(res []string) []string {
	// Function to reverse the order of elements in a slice of strings
}

func ini(res []int, init int) {
	// Function to initialize the first element of a slice with a given value
}

// Uncomment the following code if you want to use regexp package
// func regexpExample() {
//     // Your code here!
//     var str = "13:20"
//     r := regexp.MustCompile(`(\d+):(\d+)`)
//     fmt.Println(r.FindStringSubmatch(str))
// }

// Define a custom type 'Country' with gold, silver, and bronze fields
// type Country struct {
//     gold int
//     silver int
//     blonze int
// }

// Function to sort a slice of 'Country' based on bronze, silver, and gold fields in that order
// func stableSortExample() []Country {
//     // Your code here!
// }
