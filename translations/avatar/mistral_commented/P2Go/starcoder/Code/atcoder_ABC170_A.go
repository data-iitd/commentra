
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read a list of space-separated integers as input from the standard input
	// and convert each integer to its corresponding Go integer type using the strconv.Atoi() function
	a := strings.Split(bufio.NewReader(os.Stdin).ReadString(), " ")
	b := make([]int, len(a))
	for i := range a {
		b[i], _ = strconv.Atoi(a[i])
	}

	// Iterate over the elements of the list b using the range keyword
	for i, v := range b {
		// Check if the current value is equal to zero
		if v == 0 {
			// Print the index of the first zero to the standard output
			fmt.Println(i + 1)
			// Terminate the loop using the break statement
			break
		}
	}
}

