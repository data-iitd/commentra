// Importing the fmt module for printing output
import "fmt"

// Function to read input from standard input in buffer
func read() []byte {
	return []byte(fmt.Sprint(input()))
}

// Function to read a single line from standard input in buffer
func readline() []byte {
	return []byte(fmt.Sprint(input()))
}

// Function to read multiple lines from standard input in buffer
func readlines() [][]byte {
	return [][]byte(fmt.Sprint(input()))
}

// Function definition: main function takes three arguments N, d, and x
func main(N, d, x int) int {
	// Initializing the result variable to 0
	ret := 0

	// Loop continues as long as N is greater than 0
	for N > 0 {
		// Adding the current term to the result
		ret += d + (N - 0.5) * x

		// Updating the value of d for the next iteration
		d += d / N + (5 * x) / (2 * N)

		// Updating the value of x for the next iteration
		x += 2 * x / N

		// Decrementing the value of N for the next iteration
		N -= 1
	}

	// Returning the final result
	return ret
}

// Calling the main function and printing the result
fmt.Println(main(N, d, x))

// End of code
