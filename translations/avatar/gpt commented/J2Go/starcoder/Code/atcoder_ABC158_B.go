package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read input from stdin
	fmt.Print("Enter N: ")
	input, _ := reader.ReadString('\n')
	N, _ := strconv.ParseInt(strings.TrimSpace(input), 10, 64)
	fmt.Print("Enter A: ")
	input, _ = reader.ReadString('\n')
	A, _ := strconv.ParseInt(strings.TrimSpace(input), 10, 64)
	fmt.Print("Enter B: ")
	input, _ = reader.ReadString('\n')
	B, _ := strconv.ParseInt(strings.TrimSpace(input), 10, 64)

	// Initialize a variable k to count how many complete cycles of (A + B) can fit into N
	var k int64 = 0

	// Check if the input values are within the specified constraints
	if 1 <= N && N <= int64(math.Pow(10, 18)) && 0 <= A && 0 <= B && 0 < A+B && A+B <= int64(math.Pow(10, 18)) {

		// Case 1: If the sum of A and B is less than or equal to N
		if A+B <= N {
			// Calculate how many complete cycles of (A + B) fit into N
			k = N / (A + B)

			// Check if the remaining part after k cycles is greater than A
			if N-k*(A+B) > A {
				// Print the total amount produced using k cycles and the remaining part
				fmt.Println(A*k + (N-k*(A+B)) - (N-(k*(A+B)+A)))
			} else {
				// Print the total amount produced using k cycles and the remaining part
				fmt.Println(A*k + (N-k*(A+B)))
			}
		}
		// Case 2: If the sum of A and B is greater than N but A is less than or equal to N
		else if A+B > N && A <= N {
			// If A is less than or equal to N, print A
			fmt.Println(A)
		}
		// Case 3: If A + B is greater than N and A is greater than N
		else {
			// Print the total amount N, as no complete cycles can be formed
			fmt.Println(N)
		}
	}
}

