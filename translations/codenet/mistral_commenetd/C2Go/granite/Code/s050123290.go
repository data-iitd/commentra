
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	const N = 1000 // Define a constant N with the value 1000
	reader := bufio.NewReader(os.Stdin) // Create a new buffered reader for the standard input
	su := make([]byte, N) // Create a byte slice'su' of size N
	var susum int // Declare an integer variable'susum'
	var j int // Declare an integer variable 'j'

	for { // Start an infinite loop
		for j = 0; j < N; j++ { // Iterate through each index of the byte slice'su'
			su[j], _, _ = reader.ReadByte() // Read a byte from the standard input and store it in the byte slice'su' at the current index
			if su[j] == '\n' { // If the byte read is a newline character, break out of the loop
				break
			}
			susum += int(su[j] - '0') // Add the ASCII value of the byte (after subtracting '0') to the variable'susum'
		}
		if su[0] == '0' { // If the first byte of the byte slice'su' is '0', break out of the loop
			break
		}
		fmt.Println(susum) // Print the sum of the digits read from the standard input
		susum = 0 // Reset the variable'susum' to zero for the next iteration
	}
}

// 