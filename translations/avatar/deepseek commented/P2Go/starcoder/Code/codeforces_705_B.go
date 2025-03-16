
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements in the list `w`
	n, _ := strconv.Atoi(readLine())

	// Read the list of integers `w`
	w := strings.Split(readLine(), " ")

	// Initialize the variable `c` to 2
	c := 2

	// Loop through each element `i` in the list `w`
	for _, i := range w {
		// Convert `i` to an integer
		i, _ := strconv.Atoi(i)

		// Check if `i` is equal to 1
		if i == 1 {
			// Print the current value of `c`
			fmt.Println(c)
		} else if i%2 == 0 {
			// Toggle the value of `c` between 2 and 3-c (i.e., 1 or 3)
			c = 3 - c
			// Print the new value of `c`
			fmt.Println(c)
		} else {
			// Print the current value of `c`
			fmt.Println(c)
	}
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	line, _, _ := buf.ReadLine()
	return strings.TrimRight(string(line), "\r\n")
}

