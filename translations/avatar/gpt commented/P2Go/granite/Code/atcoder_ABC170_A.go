
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read a line of input, split it into components, and convert each component to an integer
	a := make([]int, 0)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	for _, s := range strings.Split(scanner.Text(), " ") {
		i, _ := strconv.Atoi(s)
		a = append(a, i)
	}

	// Iterate over the list 'a' using a for loop
	for e, i := range a {
		// Check if the current value is zero
		if i == 0 {
			// Print the index (1-based) of the first occurrence of zero
			fmt.Println(e + 1)
			// Exit the loop after finding the first zero
			break
		}
	}
}
