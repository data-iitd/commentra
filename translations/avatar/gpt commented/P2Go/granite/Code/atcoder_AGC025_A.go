
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from the user
	reader := bufio.NewReader(os.Stdin)
	n, _ := reader.ReadString('\n')

	// Define a list of string representations of powers of ten
	a := []string{"10", "100", "1000", "10000", "100000"}

	// Convert the input string into a list of integers and calculate the sum
	new := 0
	for _, v := range strings.Split(n, "") {
		i, _ := strconv.Atoi(v)
		new += i
	}

	// Check if the input is one of the predefined values in the list 'a'
	if contains(a, n) {
		// If the input matches one of the predefined values, print 10
		fmt.Println(10)
	} else {
		// If the input does not match, print the calculated sum
		fmt.Println(new)
	}
}

func contains(s []string, e string) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

