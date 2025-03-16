package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read three integers from the input
	var r, d int
	var x int64
	scanner.Scan()
	r, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	d, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	x, _ = strconv.ParseInt(scanner.Text(), 10, 64)

	// Perform the calculation in a loop and print the result 10 times
	for i := 0; i < 10; i++ {
		x = r*x - d
		fmt.Println(x)
	}
}

