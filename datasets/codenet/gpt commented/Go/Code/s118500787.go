package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read two strings S and T from standard input
	S, T := ReadString(), ReadString()
	
	// Initialize a variable to keep track of the maximum number of matching characters
	max := 0
	
	// Iterate over each possible starting index in S where T can fit
	for i := 0; i <= len(S)-len(T); i++ {
		// Initialize a counter for matching characters
		c := 0
		
		// Compare characters of T with the corresponding characters in S
		for j := 0; j < len(T); j++ {
			if S[i+j] == T[j] {
				c++ // Increment the counter for each matching character
			}
		}
		
		// Update the maximum count of matching characters if the current count is greater
		if max < c {
			max = c
		}
	}
	
	// Output the number of characters in T that do not match with S
	fmt.Println(len(T) - max)
}

// Create a buffered reader for standard input
var reader = bufio.NewReader(os.Stdin)

// Scan reads input from the buffered reader and handles errors
func Scan(a ...interface{}) {
	if _, err := fmt.Fscan(reader, a...); err != nil {
		panic(err) // Panic if there is an error while scanning
	}
}

// ReadInt reads an integer from input and returns it
func ReadInt() (i int) {
	Scan(&i) // Scan the integer
	return   // Return the scanned integer
}

// ReadString reads a string from input and returns it
func ReadString() (s string) {
	Scan(&s) // Scan the string
	return   // Return the scanned string
}

// ReadInts reads n integers from input and returns them as a slice
func ReadInts(n int) []int {
	v := make([]int, n) // Create a slice to hold n integers
	for i := 0; i < n; i++ {
		Scan(&v[i]) // Scan each integer into the slice
	}
	return v // Return the slice of integers
}
