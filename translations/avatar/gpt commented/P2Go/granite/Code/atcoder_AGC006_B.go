
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input values N and X from the user
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(readerReadLine(reader))
	X, _ := strconv.Atoi(readerReadLine(reader))

	// Define a function to perform calculations on the input list
	calc := func(x []int) int {
		// Define a helper function to process the list y
		sub := func(y []int, debug bool) []int {
			// If debug mode is on, print the current state of y
			if debug {
				fmt.Printf("D %v\n", y)
			}
			// Reduce the list y until it has only one element
			for len(y) > 1 {
				// Replace y with the second largest element of every three consecutive elements
				y = []int{sorted(y[i:i+3])[1] for i := 0; i < len(y)-2; i++}
				// If debug mode is on, print the current state of y
				if debug {
					fmt.Printf("D %v\n", y)
				}
			}
			return y
		}

		// Call the helper function to process x
		y := sub(x, false)

		// If the final result is 2, perform additional processing
		if y[0] == 2 {
			// Placeholder for potential future logic
			sub(x, true)
			fmt.Printf("= %v\n", x)
		}

		// Return the final processed value
		return y[0]
	}

	// Check specific conditions based on the value of X
	if X == 1 || X == N*2-1 {
		// If X is at the boundaries, print "No"
		fmt.Println("No")
	} else {
		// If X is within the valid range, print "Yes"
		fmt.Println("Yes")

		// Handle the case where X is N * 2 - 2
		if X == N*2-2 {
			// Create a list xs with specific ranges
			xs := make([]int, N-1)
			for i := N - 2; i < X+2; i++ {
				xs[i-(N-2)] = i + 1
			}
			for i := 0; i < N-3; i++ {
				xs[i+X-N+1] = i + 1
			}
		} else {
			// Create a list ys with specific ranges and then construct xs
			ys := make([]int, N-3)
			for i := 0; i < X-1; i++ {
				ys[i] = i + 1
			}
			for i := X + 3; i < N*2; i++ {
				ys[i-X-3] = i + 1
			}
			xs := make([]int, N-1)
			for i := 0; i < N-3; i++ {
				xs[i] = ys[i]
			}
			xs[N-3] = X + 2
			xs[N-2] = X - 1
			xs[N-1] = X
		}

		// Print each element in the final list xs
		for _, x := range xs {
			fmt.Println(x)
		}
	}
}

func readerReadLine(reader *bufio.Reader) string {
	line, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(line)
}

func sorted(s []int) []int {
	// Sort the input slice s
	//... (code for sorting the slice)
	return s
}

