
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements to be processed
	n, _ := strconv.Atoi(read(reader))

	// Initialize variables to hold the sums of three different sets of integers
	a, b, c := 0, 0, 0

	// Read n integers and calculate their sum (a)
	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(read(reader))
		a += num
	}

	// Read n-1 integers and calculate their sum (b)
	for i := 0; i < n-1; i++ {
		num, _ := strconv.Atoi(read(reader))
		b += num
	}

	// Read n-2 integers and calculate their sum (c)
	for i := 0; i < n-2; i++ {
		num, _ := strconv.Atoi(read(reader))
		c += num
	}

	// Calculate the difference between the sums: x = sum of first set - sum of second set
	x := a - b

	// Calculate the difference between the sums: y = sum of second set - sum of third set
	y := b - c

	// Print the results of the differences
	fmt.Println(x)
	fmt.Println(y)
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

