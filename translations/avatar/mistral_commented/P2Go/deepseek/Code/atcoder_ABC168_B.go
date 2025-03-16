package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read the integer K from the standard input
	reader := bufio.NewReader(os.Stdin)
	K, _ := reader.ReadString('\n')
	K = K[:len(K)-1] // Remove the newline character
	Kint, _ := strconv.Atoi(K)

	// Read a string S from the standard input
	S, _ := reader.ReadString('\n')
	S = S[:len(S)-1] // Remove the newline character

	// Check if the length of the string S is less than or equal to K
	if len(S) <= Kint {
		// If the condition is true, return the string S
		fmt.Println(S)
	} else {
		// If the condition is false, return a slice of the string S
		// from the beginning to the index K, followed by three dots '...'
		fmt.Println(S[:Kint] + "...")
	}
}

