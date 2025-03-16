

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read a list of space-separated integers from the standard input
	// and convert each integer to its corresponding Go integer type using the strconv.Atoi() function
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	a := strings.Split(input, " ")
	var b []int
	for _, value := range a {
		b = append(b, strconv.Atoi(value))
	}

	// Iterate over the elements of the list b using a for loop
	for index, value := range b {
		// Check if the current value is equal to zero
		if value == 0 {
			// Print the index of the first zero to the standard output
			fmt.Println(index + 1)
			// Terminate the loop using the break statement
			break
		}
	}
}

