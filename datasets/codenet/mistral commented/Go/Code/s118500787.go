// Package main is the entry point of the program
package main

import (
	// Importing required packages
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize two empty strings S and T
	S, T := ReadString(), ReadString()

	// Initialize max as 0
	max := 0

	// Loop through all possible substrings of S with length equal to T
	for i := 0; i <= len(S)-len(T); i++ {
		// Initialize a counter c for the number of matching characters between S[i:i+len(T)] and T
		c := 0

		// Check character by character for matching characters
		for j := 0; j < len(T); j++ {
			// If current characters match, increment counter c
			if S[i+j] == T[j] {
				c++
			}
		}

		// If current substring has more matching characters than the current max, update max
		if max < c {
			max = c
		}
	}

	// Print the length of the shortest substring of S that matches T with all characters
	fmt.Println(len(T) - max)
}

// Helper functions to read input from stdin
var reader = bufio.NewReader(os.Stdin)

func Scan(a ...interface{}) {
	// Function to read input and store it in the provided interface
	if _, err := fmt.Fscan(reader, a...); err != nil {
		// Panic if there is an error while reading input
		panic(err)
	}
}

func ReadInt() (i int)       { Scan(&i); return }
func ReadString() (s string) { Scan(&s); return }
func ReadInts(n int) []int {
	// Function to read n integers and return a slice
	v := make([]int, n)
	for i := 0; i < n; i++ {
		Scan(&v[i])
	}
	return v
}

