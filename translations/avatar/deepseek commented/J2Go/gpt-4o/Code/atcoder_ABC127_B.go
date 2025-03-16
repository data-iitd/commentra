package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read three integers from the input
	scanner.Scan()
	r, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	d, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	x, _ := strconv.ParseInt(scanner.Text(), 10, 64)

	// Perform the calculation in a loop and print the result 10 times
	for i := 0; i < 10; i++ {
		x = int64(r)*x - int64(d)
		fmt.Println(x)
	}
}

// <END-OF-CODE>
