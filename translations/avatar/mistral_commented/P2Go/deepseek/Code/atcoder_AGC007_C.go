package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to read input from standard input in buffer
func readInput() []int {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	values := make([]int, 3)
	for i, v := range strings.Split(strings.TrimSpace(input), " ") {
		values[i], _ = strconv.Atoi(v)
	}
	return values
}

// Function definition: main function takes three arguments N, d, and x
func main(N, d, x int) int {
	// Initializing the result variable to 0
	ret := 0

	// Loop continues as long as N is greater than 0
	for N > 0 {
		// Adding the current term to the result
		ret += d + (float64(N)-0.5)*float64(x)

		// Updating the value of d for the next iteration
		d += float64(d)/float64(N) + (5*float64(x))/(2*float64(N))

		// Updating the value of x for the next iteration
		x += 2 * float64(x) / float64(N)

		// Decrementing the value of N for the next iteration
		N--
	}

	// Returning the final result
	return ret
}

func main() {
	// Reading input as three integers: N, d, and x
	values := readInput()
	N, d, x := values[0], values[1], values[2]

	// Calling the main function and printing the result
	result := main(N, d, x)
	fmt.Println(result)
}
