
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read the integer K from the standard input
	var K int
	fmt.Fscan(os.Stdin, &K)

	// Read a string S from the standard input
	var S string
	fmt.Fscan(os.Stdin, &S)

	// Check if the length of the string S is less than or equal to K
	if len(S) <= K {

		// If the condition is true, return the string S
		fmt.Println(S)
	} else {

		// If the condition is false, return a slice of the string S
		// from the beginning to the index K, followed by three dots '...'
		fmt.Println(S[:K] + "...")
	}
}

