package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Constants for buffer sizes
const (
	initialBufSize = 10000
	maxBufSize     = 1000000
)

// Global variables for scanner and modulus
var (
	// Initialize a buffered scanner for reading input
	sc *bufio.Scanner = func() *bufio.Scanner {
		sc := bufio.NewScanner(os.Stdin)
		buf := make([]byte, initialBufSize)
		sc.Buffer(buf, maxBufSize)
		sc.Split(bufio.ScanWords) // Split input by words
		return sc
	}()
	mod int = 1e9 + 7 // Modulus value for calculations
)

func main() {
	// Array representing the days of the week
	week := []string{"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"}
	
	// Get the input day as a string
	s := getString()
	index := -1 // Initialize index to -1 to indicate not found

	// Search for the input day in the week array
	for i, day := range week {
		if s == day {
			index = i // Update index if the day is found
			break
		}
	}

	// Calculate and print the number of days until the next Sunday
	fmt.Println(7 - index)
}

// Function to read an integer from input
func getInt() int {
	sc.Scan() // Scan the next token
	i, e := strconv.Atoi(sc.Text()) // Convert the scanned text to an integer
	if e != nil {
		panic(e) // Panic if there is an error in conversion
	}
	return i // Return the integer value
}

// Function to read a string from input
func getString() string {
	sc.Scan() // Scan the next token
	return sc.Text() // Return the scanned text as a string
}

// Function to compute the absolute value of an integer
func abs(a int) int {
	return int(math.Abs(float64(a))) // Use math.Abs to get the absolute value
}

// Function to compute p raised to the power of q
func pow(p, q int) int {
	return int(math.Pow(float64(p), float64(q))) // Use math.Pow for exponentiation
}

// Function to find the minimum value among given integers
func min(nums ...int) int {
	if len(nums) == 0 {
		panic("function min() requires at least one argument.") // Panic if no arguments are provided
	}
	res := nums[0] // Initialize result with the first number
	for i := 0; i < len(nums); i++ {
		res = int(math.Min(float64(res), float64(nums[i]))) // Update result with the minimum value
	}
	return res // Return the minimum value
}

// Function to find the maximum value among given integers
func max(nums ...int) int {
	if len(nums) == 0 {
		panic("function max() requires at least one argument.") // Panic if no arguments are provided
	}
	res := nums[0] // Initialize result with the first number
	for i := 0; i < len(nums); i++ {
		res = int(math.Max(float64(res), float64(nums[i]))) // Update result with the maximum value
	}
	return res // Return the maximum value
}

// Function to check if a string exists in a slice of strings
func strSearch(a []string, b string) bool {
	for i := 0; i < len(a); i++ {
		if a[i] == b {
			return true // Return true if the string is found
		}
	}
	return false // Return false if the string is not found
}

// Function to print an array of integers
func printIntArray(array []int) {
	strArray := fmt.Sprint(array) // Convert the array to a string
	fmt.Println(strArray[1 : len(strArray)-1]) // Print the string representation without brackets
}

// Function to calculate the modulus of x with respect to the defined mod
func calcMod(x int) int {
	return x % mod // Return the result of x modulo mod
}
