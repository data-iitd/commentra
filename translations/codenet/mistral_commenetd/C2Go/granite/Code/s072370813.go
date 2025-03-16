
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables
	N := 0                  // Number of elements in the array
	i := 0                 // Loop counter
	sum := 0               // Sum of all elements in the array
	wa := 0                // Sum of all indices from 1 to N
	A := make([]int, N)   // Array to store input elements
	sa := make([]int, N)   // Array to store differences between adjacent elements
	ans := 0               // Answer flag
	shou := 0              // Quotient of sum and wa

	// Read input
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &N)
	// Read N integers into the array A
	for i = 0; i < N; i++ {
		fmt.Fscanf(reader, "%d", &A[i])
		// Add current element to sum
		sum += A[i]
		// Add current index to wa
		wa += i + 1
	}

	// Check if sum is divisible by wa
	if sum%wa!= 0 {
		ans = 0
	} else {
		// Calculate quotient of sum and wa
		shou = sum / wa
		// Calculate differences between adjacent elements and store in array sa
		for i = 0; i < N; i++ {
			sa[i] = A[(i+1)%N] - A[i] - shou
		}

		// Check if any difference is less than or equal to 0 and divisible by N
		for i = 0; i < N-1; i++ {
			if sa[i] <= 0 && sa[i]%N == 0 {
				ans = 1
			} else {
				ans = 0
				break
			}
		}
	}

	// Print answer
	if ans == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
