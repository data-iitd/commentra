
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(S, T, U string, A, B int) {
	// Check if the first string S matches the string U
	if S == U {
		A-- // Decrement A if S matches U
	}
	// Check if the second string T matches the string U
	if T == U {
		B-- // Decrement B if T matches U
	}
	// Print the final values of A and B
	fmt.Println(A, B)
}

func main() {
	// Define a function to iterate over tokens from standard input
	iterateTokens := func() <-chan string {
		ch := make(chan string)
		go func() {
			for _, line := range strings.Split(os.Getenv("INPUT_VALUES"), "\n") {
				for _, word := range strings.Split(line, " ") {
					ch <- word
				}
			}
			close(ch)
		}()
		return ch
	}

	// Create a channel for tokens
	tokens := iterateTokens()
	// Read the first string S from input
	S := <-tokens
	// Read the second string T from input
	T := <-tokens
	// Read the integer A from input and convert it to an integer
	A, _ := strconv.Atoi(<-tokens)
	// Read the integer B from input and convert it to an integer
	B, _ := strconv.Atoi(<-tokens)
	// Read the string U from input
	U := <-tokens

	// Call the solve function with the read values
	solve(S, T, U, A, B)
}

// Entry point of the program
func init() {
	// Set the environment variable INPUT_VALUES to the input values
	os.Setenv("INPUT_VALUES", "S T A B U")
}

// 