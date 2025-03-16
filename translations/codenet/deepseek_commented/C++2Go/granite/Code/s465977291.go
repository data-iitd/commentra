
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Include necessary packages for input/output operations, mathematical calculations, and data structures.
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	var n, d int
	fmt.Fscanf(reader, "%d %d\n", &n, &d)

	// Read the values of n and d from the standard input.
	a := d*2 + 1
	// Calculate the value of 'a' which is used in the subsequent calculations.
	fmt.Fprintf(writer, "%d\n", int(n/a)+1)
	// Output the ceiling of the division of n by 'a' to the standard output.

	writer.Flush()
}

