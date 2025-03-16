

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read user inputs from standard input using fmt.Scanln
	var x, y int64
	fmt.Scanln(&x, &y)

	// Check if the absolute difference between x and y is less than or equal to 1
	if int(math.Abs(float64(x-y))) <= 1 {
		// If the condition is true, print "Brown" to the standard output
		fmt.Println("Brown")
	} else {
		// If the condition is false, print "Alice" to the standard output
		fmt.Println("Alice")
	}
}

