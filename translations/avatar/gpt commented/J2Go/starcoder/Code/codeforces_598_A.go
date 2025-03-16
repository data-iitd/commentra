package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a new scanner to read input from stdin
	sc := bufio.NewScanner(os.Stdin)

	// Taking input from stdin
	sc.Scan()

	// Converting the input to an integer
	q, _ := strconv.Atoi(sc.Text())

	// Looping through each test case
	for q > 0 {
		// Taking input from stdin
		sc.Scan()

		// Converting the input to an integer
		n, _ := strconv.Atoi(sc.Text())

		// Initializing a variable to store the result
		s := 0

		// Calculating the highest power of 2 less than or equal to n
		x := int(math.Log(float64(n)) / math.Log(2))
		x++

		// Calculating the final result using the derived formula
		s = -1 * int(math.Pow(2, float64(x))) + 2 + (n * (n + 1)) / 2 - int(math.Pow(2, float64(x)))

		// Printing the result for the current test case
		fmt.Println(s)

		// Decrementing the number of test cases
		q--
	}
}

