package main

import (
	"fmt"
	"sort"
)

const N = 200010 // Define a constant for the maximum size of the array

var a [N]int64 // Declare an array for elements
var q [N]int64 // Declare an array for duplicates
var n, tot int64 // Declare variables

// Function to read a long long integer from input
func read() int64 {
	var x int64
	var f int64 = 1
	var ch byte

	for {
		ch = getchar()
		if ch >= '0' && ch <= '9' {
			break
		}
		if ch == '-' {
			f = -1
		}
	}
	for ch >= '0' && ch <= '9' {
		x = x*10 + int64(ch-'0')
		ch = getchar()
	}
	return x * f // Return the final value with sign
}

// Function to get a character from input
func getchar() byte {
	var b [1]byte
	_, _ = fmt.Scan(b[:]) // Read a single byte
	return b[0]
}

// Function to write a long long integer to output
func write(x int64) {
	if x < 0 {
		fmt.Print("-")
		x = -x
	}
	if x >= 10 {
		write(x / 10) // Recursively write the digits
	}
	fmt.Print(x % 10) // Print the last digit
}

// Function to write a long long integer followed by a newline
func writeln(x int64) {
	write(x)
	fmt.Println() // Print a newline
}

func main() {
	n = read() // Read the number of elements
	for i := int64(1); i <= n; i++ {
		a[i] = read() // Read the elements into the array a
	}
	sort.Slice(a[1:n+1], func(i, j int) bool {
		return a[i+1] < a[j+1] // Sort the array in non-decreasing order
	})

	// Identify duplicates and store them in array q
	for i := int64(1); i <= n; i++ {
		if a[i] == a[i+1] {
			q[tot+1] = a[i] // Store the duplicate
			tot++
			i++ // Skip the next element
		}
	}

	// Output the product of the last two duplicates found
	writeln(q[tot] * q[tot-1])
}

// <END-OF-CODE>
