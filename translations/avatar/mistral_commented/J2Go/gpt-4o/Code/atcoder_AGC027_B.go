package main // Defining the main package

import (
	"fmt" // Importing the fmt package for formatted I/O
)

const INF = int(^uint(0) >> 1) // Initializing INF with the maximum value of an integer

func main() { // Main function to start the program
	solve() // Calling the solve function
}

func solve() { // Function to solve the problem
	var N int
	var X int64
	fmt.Scan(&N) // Reading the number of elements in the array from the console
	fmt.Scan(&X) // Reading the value of X from the console

	x := make([]int64, N) // Creating a slice of size N to store the elements
	xsum := make([]int64, N+1) // Creating a slice of size N+1 to store the sum of elements up to that index

	for i := 0; i < N; i++ { // Loop to read and store the elements in the slice
		fmt.Scan(&x[i]) // Reading the element
		xsum[i+1] = xsum[i] + x[i] // Updating the sum of elements up to the current index
	}

	ans := X*int64(N) + 5*xsum[N] // Initializing the answer with the first calculation

	for i := 1; i < N; i++ { // Loop to find the minimum cost
		cost := X*int64(i) + 5*(xsum[N]-xsum[N-i]) // Calculating the cost for the current i
		for j, k := int64(5), N-i; k >= 0; j += 2 {
			if k < i {
				break // If k is less than i, break the loop
			}
			cost += j * (xsum[k] - xsum[max(k-i, 0)]) // Updating the cost with the sum of elements between k and k-i
			k -= i // Decrement k by i
		}
		if cost < ans { // Updating the answer with the minimum cost found so far
			ans = cost
		}
	}

	fmt.Println(ans + int64(N)*X) // Printing the final answer
}

// max function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
