// Package main
// Imports
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to solve the problem
func solve(N int, M int, Q int, a []int, b []int, c []int, d []int) {
	// Initialize result to 0
	res := 0

	// Helper function to calculate the answer recursively
	func rec(A []int) {
		// Nonlocal variable to update the result from the recursive calls
		nonlocal res

		// Base case: if all elements of A are placed, calculate the answer
		if len(A) == N {
			ans := 0
			for i := 0; i < Q; i++ {
				// Check if the condition is satisfied
				if A[b[i]-1]-A[a[i]-1] == c[i] {
					ans += d[i]
				}
			}
			// Update the result with the maximum answer
			res = max(res, ans)
			return
		}

		// Recursive call: try placing elements from last_max to M
		last_max := 1
		if len(A) > 0 {
			last_max = A[len(A)-1]
		}
		for i := last_max; i <= M; i++ {
			rec(append(A, i))
		}
	}(make([]int, 0))

	// Call the helper function with an empty list
	rec([]int{})

	// Print the result
	fmt.Println(res)
}

// Main function to read input and call the solve function
func main() {
	// Function to generate tokens from standard input
	func iterate_tokens() chan string {
		ch := make(chan string)
		go func() {
			scanner := bufio.NewScanner(os.Stdin)
			for scanner.Scan() {
				ch <- scanner.Text()
			}
			close(ch)
		}()
		return ch
	}

	// Read input tokens
	tokens := iterate_tokens()

	// Read number of test cases
	N, _ := strconv.Atoi(<-tokens)

	// Read number of elements in the array and number of queries
	M, _ := strconv.Atoi(<-tokens)
	Q, _ := strconv.Atoi(<-tokens)

	// Read the arrays a, b, c, and d
	a := make([]int, Q)
	b := make([]int, Q)
	c := make([]int, Q)
	d := make([]int, Q)
	for i := 0; i < Q; i++ {
		a[i], _ = strconv.Atoi(<-tokens)
		b[i], _ = strconv.Atoi(<-tokens)
		c[i], _ = strconv.Atoi(<-tokens)
		d[i], _ = strconv.Atoi(<-tokens)
	}

	// Call the solve function with the given input
	solve(N, M, Q, a, b, c, d)
}

// Run the main function if the script is executed directly
func init() {
	if len(os.Args) > 1 && os.Args[1] == "test" {
		// Read input from stdin
		input, err := ioutil.ReadAll(os.Stdin)
		if err!= nil {
			panic(err)
		}
		// Split input by newline
		lines := strings.Split(string(input), "\n")
		// Split each line by space
		var tokens []string
		for _, line := range lines {
			tokens = append(tokens, strings.Split(line, " ")...)
		}
		// Convert each token to integer
		var N, M, Q int
		N, _ = strconv.Atoi(tokens[0])
		M, _ = strconv.Atoi(tokens[1])
		Q, _ = strconv.Atoi(tokens[2])
		a := make([]int, Q)
		b := make([]int, Q)
		c := make([]int, Q)
		d := make([]int, Q)
		for i := 0; i < Q; i++ {
			a[i], _ = strconv.Atoi(tokens[3+i*4])
			b[i], _ = strconv.Atoi(tokens[3+i*4+1])
			c[i], _ = strconv.Atoi(tokens[3+i*4+2])
			d[i], _ = strconv.Atoi(tokens[3+i*4+3])
		}
		// Call the solve function with the given input
		solve(N, M, Q, a, b, c, d)
	}
}

// END-OF-CODE

# Python:
# Importing sys module for reading input from standard input.
import sys

# Function to solve the problem
def solve(N: int, M: int, Q: int, a: List[int], b: List[int], c: List[int], d: List[int]):
    # Initialize result to 0
    res = 0

    # Helper function to calculate the answer recursively
    def rec(A):
        # Nonlocal variable to update the result from the recursive calls
        nonlocal res

        # Base case: if all elements of A are placed, calculate the answer
        if len(A) == N:
            ans = 0
            for i in range(Q):
                # Check if the condition is satisfied
                if A[b[i] - 1] - A[a[i] - 1] == c[i]:
                    ans += d[i]
            # Update the result with the maximum answer
            res = max(res, ans)
            return

        # Recursive call: try placing elements from last_max to M
        last_max = 1 if len(A) == 0 else A[-1]
        for i in range(last_max, M + 1):
            rec(A + [i])

    # Call the helper function with an empty list
    rec([])

    # Print the result
    print(res)

# Main function to read input and call the solve function
def main():
    # Function to generate tokens from standard input
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word

    # Read input tokens
    tokens = iterate_tokens()

    # Read number of test cases
    N = int(next(tokens))

    # Read number of elements in the array and number of queries
    M = int(next(tokens))
    Q = int(next(tokens))

    # Read the arrays a, b, c, and d
    a = [int()] * Q
    b = [int()] * Q
    c = [int()] * Q
    d = [int()] * Q
    for i in range(Q):
        a[i] = int(next(tokens))
        b[i] = int(next(tokens))
        c[i] = int(next(tokens))
        d[i] = int(next(tokens))

    # Call the solve function with the given input
    solve(N, M, Q, a, b, c, d)

# Run the main function if the script is executed directly
if __name__ == '__main__':
    main()


Translate the above Python code to C++ and end with comment "