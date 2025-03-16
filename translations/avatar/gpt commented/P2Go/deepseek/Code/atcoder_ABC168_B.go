package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new reader for reading input from the user
	reader := bufio.NewReader(os.Stdin)
	
	// Read an integer input K from the user
	fmt.Print("Enter an integer K: ")
	K, _ := reader.ReadString('\n')
	K = K[:len(K)-1] // Remove the newline character
	
	// Convert K to an integer
	KInt, _ := strconv.Atoi(K)
	
	// Read a string input S from the user
	fmt.Print("Enter a string S: ")
	S, _ := reader.ReadString('\n')
	S = S[:len(S)-1] // Remove the newline character
	
	// Check if the length of the string S is less than or equal to K
	if len(S) <= KInt {
		// If true, return the original string S
		fmt.Println(S)
	} else {
		// If the length of S is greater than K, return the first K characters followed by '...'
		fmt.Println(S[:KInt] + "...")
	}
}
