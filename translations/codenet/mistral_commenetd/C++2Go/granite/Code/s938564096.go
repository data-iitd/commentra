

package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1e9 + 7

func main() {
	r := 0 // Declare an integer variable `r` to store the value read from the standard input

	// Read an integer `r` from the standard input
	fmt.Fscan(bufio.NewReader(os.Stdin), &r)

	// Calculate and print the square of `r` to the standard output
	fmt.Println(r * r)

}

// 