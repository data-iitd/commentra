
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read a line of text from the standard input stream and convert it into a list of integers
	vamshi, z := map(strconv.Atoi, strings.Split(input(), " "))

	// Calculate the number of complete divisions of z into vamshi
	// Add 1 to account for the remainder
	// Multiply the result by z
	fmt.Println((vamshi / z + 1) * z)
}

