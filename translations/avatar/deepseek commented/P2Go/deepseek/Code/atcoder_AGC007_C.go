package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Reading the values of N, d, and x from standard input
	var N, d, x int
	fmt.Fscan(reader, &N, &d, &x)
	
	// Defining the main function to calculate a result based on N, d, and x
	main := func(N, d, x int) int {
		ret := 0 // Initializing the result variable to accumulate the result
		for N > 0 { // Running the loop while N is greater than 0
			// Incrementing ret by the sum of d and (N - 0.5) * x
			ret += d + (float64(N) - 0.5) * float64(x)
			
			// Updating the value of d using a complex formula
			d = d + d / N + (5 * x) / (2 * N)
			
			// Updating the value of x using another formula
			x += 2 * x / N
			
			// Decrementing N by 1
			N--
		}
		
		// Returning the accumulated result
		return ret
	}
	
	// Printing the result of the main function
	fmt.Println(main(N, d, x))
}
