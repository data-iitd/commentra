
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize variables
	a, b := readInt(), readInt()

	// Calculate the maximum value among a+b, a-b, and a*b
	result := max(a+b, max(a-b, a*b))

	// Output the result to standard output
	fmt.Println(result)
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func max(x, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}

// End of the program
