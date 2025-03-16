
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Define input variables
	N, X := read2Int()
	// Comment: Read input values N and X from the standard input

	calc := func(x int) int {
		// Define a function calc that takes an integer x as an argument

		sub := func(y []int, debug bool) []int {
			// Define a nested function sub that takes a slice of integers y and a boolean debug as arguments

			if debug {
				fmt.Printf("D %v\n", y)
			}
			// If debug is true, print the intermediate values of y

			for len(y) > 1 {
				y = sortedMiddle(y)
				if debug {
					fmt.Printf("D %v\n", y)
				}
			}
			// Sort and select the middle element from sublists of length 3 in y

			return y
		}
		// Return the result of the sub function

		y := sub([]int{x}, false)
		// Calculate the result y of the sub function for the given input x

		if y[0] == 2 {
			sub([]int{x}, true)
			fmt.Printf("= %d\n", x)
		}
		// If the first element of y is 2, call the sub function recursively with x-1 and print x

		return y[0]
	}
	// Return the first element of the y list

	if X == 1 || X == N*2-1 {
		// Check if X is equal to 1 or N*2-1

		fmt.Println("No")
		// If it is, print "No"

		return
	}
	// Else, X is neither 1 nor N*2-1

	fmt.Println("Yes")
	// Print "Yes"

	if X == N*2-2 {
		xs := make([]int, N-1)
		for i := N - 2; i >= 0; i-- {
			xs[i] = X - i
		}
		// Calculate the list xs based on the value of X

		for _, x := range xs {
			fmt.Println(x)
		}
		// Print each element of the list xs

		return
	}
	// If X is neither 1 nor N*2-1, X is neither 1 nor N*2-2

	ys := make([]int, N-1)
	for i := N - 2; i >= 0; i-- {
		ys[i] = X - i
	}
	// Calculate the list ys based on the value of X

	xs := make([]int, N-1)
	for i := N - 2; i >= 0; i-- {
		xs[i] = ys[i] + 1
	}
	// Calculate the list xs based on the value of ys

	xs[N-3] = X + 2
	xs[N-2] = X - 1
	xs[N-1] = X
	// Set the elements of xs at specific indices to specific values

	for _, x := range xs {
		fmt.Println(x)
	}
	// Print each element of the list xs
}

func read2Int() (int, int) {
	// Define a function read2Int that reads two integers from the standard input and returns them as a tuple

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	fields := strings.Split(line, " ")
	if len(fields)!= 2 {
		panic("2 integers expected")
	}
	// Check if the input consists of exactly two integers

	n, err := strconv.Atoi(fields[0])
	if err!= nil {
		panic("n must be an integer")
	}
	// Convert the first field to an integer

	x, err := strconv.Atoi(fields[1])
	if err!= nil {
		panic("x must be an integer")
	}
	// Convert the second field to an integer

	return n, x
}

func sortedMiddle(y []int) []int {
	// Define a function sortedMiddle that takes a slice of integers y and returns a new slice with the middle element sorted

	if len(y)!= 3 {
		panic("3 integers expected")
	}
	// Check if the input slice has exactly three elements

	m := y[1]
	if y[0] > m {
		m = y[0]
	}
	if y[2] > m {
		m = y[2]
	}
	// Find the maximum element in y

	return []int{m, y[0], y[2]}
}

// Comment: Define a function read2Int that reads two integers from the standard input and returns them as a tuple
// Comment: Define a function sortedMiddle that takes a slice of integers y and returns a new slice with the middle element sorted
// Comment: End of Go code