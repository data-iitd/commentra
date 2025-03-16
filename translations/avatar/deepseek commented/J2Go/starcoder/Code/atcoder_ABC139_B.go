
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Create a Scanner object to read input from the standard input stream.
	sc := bufio.NewScanner(os.Stdin)

	// Step 2: Read the first integer A from the input.
	var A int
	sc.Scan()
	A, _ = strconv.Atoi(sc.Text())

	// Step 3: Read the second integer B from the input.
	var B int
	sc.Scan()
	B, _ = strconv.Atoi(sc.Text())

	// Step 4: Initialize variables to store the quotient and remainder.
	var amari int
	var result int

	// Step 5: Calculate the quotient (result) by dividing (B-1) by (A-1).
	result = (B - 1) / (A - 1)

	// Step 6: Calculate the remainder (amari) by taking the modulus of (B-1) by (A-1).
	amari = (B - 1) % (A - 1)

	// Step 7: If the remainder is not zero, increment the result by 1.
	if amari!= 0 {
		result += 1
	}

	// Step 8: Create a PrintWriter object to write output to the standard output stream.
	out := bufio.NewWriter(os.Stdout)

	// Step 9: Print the result to the standard output.
	fmt.Fprintln(out, result)

	// Step 10: Close the Scanner object to free up resources.
	sc.Close()

	// Step 11: Flush the PrintWriter to ensure all output is written to the output stream.
	out.Flush()
}

