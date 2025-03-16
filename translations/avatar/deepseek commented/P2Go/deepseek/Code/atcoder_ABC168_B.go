package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new reader for reading input from the user
	reader := bufio.NewReader(os.Stdin)
	
	// Read the value of K from the user
	fmt.Print("Enter the value of K: ")
	K, _ := reader.ReadString('\n')
	K = K[:len(K)-1] // Remove the newline character
	Kint, _ := strconv.Atoi(K) // Convert the string to an integer
	
	// Read the string S from the user
	fmt.Print("Enter the string S: ")
	S, _ := reader.ReadString('\n')
	S = S[:len(S)-1] // Remove the newline character
	
	// Check if the length of S is less than or equal to K
	if len(S) <= Kint {
		// If the length of S is less than or equal to K, return S as it is
		fmt.Println(S)
	} else {
		// If the length of S is greater than K, return the first K characters of S followed by '...'
		fmt.Println(S[:Kint] + "...")
	}
}
