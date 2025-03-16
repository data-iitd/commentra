package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	const N = 1000
	reader := bufio.NewReader(os.Stdin)
	
	for {
		// 1. Define the array and variables
		su := make([]byte, N) // Array to store the sequence of digits
		var susum int // Variable to store the sum of the digits
		
		// 2. Read input and calculate sum
		for j := 0; j < N; j++ {
			ch, _ := reader.ReadByte()
			if ch == '\n' {
				break // Break if newline character is encountered
			}
			su[j] = ch
			susum += int(ch - '0') // Convert character to integer and add to sum
		}
		
		if su[0] == '0' {
			break // Break if the sequence starts with '0'
		}
		
		// 3. Print the sum
		fmt.Println(susum) // Print the sum of the digits
		susum = 0 // Reset the sum for the next sequence
	}
	// 4. Check for termination condition
}
