
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initializing a variable c to 0
	c := 0

	// Creating a new scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Reading the first line of input and storing the number of test cases and the target sum in variables n and s
	scanner.Scan()
	n, s := readTwoInt64s(scanner)

	// Iterating through the test cases using a for loop
	for i := 0; i < int(n); i++ {
		// Reading the start and end time of each activity from the input
		scanner.Scan()
		f, t := readTwoInt64s(scanner)

		// Calculating the difference between the end time and the difference between the target sum and start time
		x := t - (s - f)

		// Updating the variable c with the maximum value of x calculated in the current iteration
		if x > c {
			c = int(x)
		}
	}

	// Printing the final answer which is the sum of the target sum and the maximum overlap calculated
	fmt.Println(s + int64(c))
}

func readTwoInt64s(scanner *bufio.Scanner) (int64, int64) {
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	return mustParseInt64(parts[0]), mustParseInt64(parts[1])
}

func mustParseInt64(s string) int64 {
	n, err := strconv.ParseInt(s, 10, 64)
	if err!= nil {
		panic(err)
	}
	return n
}

