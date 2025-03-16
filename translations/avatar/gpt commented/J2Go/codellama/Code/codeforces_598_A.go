package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Reading the number of test cases
	var q int
	sc.Scan()
	q, _ = strconv.Atoi(sc.Text())

	// Looping through each test case
	for q > 0 {
		// Reading the integer n for the current test case
		sc.Scan()
		n, _ := strconv.Atoi(sc.Text())

		// Initializing a variable to store the result
		var s int64

		// Calculating the highest power of 2 less than or equal to n
		x := int(math.Log2(float64(n))) + 1

		// Calculating the final result using the derived formula
		s = -1 * int64(math.Pow(2, float64(x))) + 2 + (int64(n)*int64(n+1))/2 - int64(math.Pow(2, float64(x)))

		// Printing the result for the current test case
		fmt.Println(s)

		q--
	}

	// Closing the scanner to prevent resource leaks
	sc.Close()
}

