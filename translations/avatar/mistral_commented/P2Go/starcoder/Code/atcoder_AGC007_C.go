package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Reading input as three integers: N, d, and x
	N, d, x := readThreeInts(reader)

	// Calling the main function and printing the result
	fmt.Println(main(N, d, x))
}

// Function to read three integers from standard input in buffer
func readThreeInts(reader *bufio.Reader) (int, int, int) {
	// Reading input as a single line
	line, _ := reader.ReadString('\n')

	// Splitting the input line by space
	line = strings.Split(line, " ")

	// Converting the first element to integer
	N, _ := strconv.Atoi(line[0])

	// Converting the second element to integer
	d, _ := strconv.Atoi(line[1])

	// Converting the third element to integer
	x, _ := strconv.Atoi(line[2])

	// Returning the three integers
	return N, d, x
}

// Function definition: main function takes three arguments N, d, and x
func main(N int, d int, x int) int {
	// Initializing the result variable to 0
	ret := 0

	// Loop continues as long as N is greater than 0
	for N > 0 {
		// Adding the current term to the result
		ret += d + (N-0.5)*x

		// Updating the value of d for the next iteration
		d += d / N + (5*x)/(2*N)

		// Updating the value of x for the next iteration
		x += 2*x/N

		// Decrementing the value of N for the next iteration
		N -= 1
	}

	// Returning the final result
	return ret
}

