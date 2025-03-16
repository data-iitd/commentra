<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	h1, m1, h2, m2, k := readInput()

	// Calculate the difference in minutes between h2:m2 and h1:m1
	ans := (h2 * 60 + m2) - (h1 * 60 + m1)

	// Print the result of subtracting k from the calculated difference
	fmt.Println(ans - k)
}

func readInput() (int, int, int, int, int) {
	// Read input from stdin
	input, _ := os.Stdin.ReadString('\n')

	// Split the input into a slice of strings
	input = strings.Split(input, " ")

	// Convert the strings to integers
	h1, _ := strconv.Atoi(input[0])
	m1, _ := strconv.Atoi(input[1])
	h2, _ := strconv.Atoi(input[2])
	m2, _ := strconv.Atoi(input[3])
	k, _ := strconv.Atoi(input[4])

	return h1, m1, h2, m2, k
}

