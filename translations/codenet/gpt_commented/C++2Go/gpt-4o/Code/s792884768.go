package main

import (
	"fmt"
	"math"
)

// Structure to represent the size of a matrix
type TSize struct {
	r int // Number of rows
	c int // Number of columns
}

// Class to solve the Matrix Chain Multiplication problem
type TMcmSolver struct {
	FMemo  [][]int   // Memoization table to store intermediate results
	FChain []TSize   // Slice to hold the chain of matrices
}

// Function to calculate the cost of multiplying two matrices
func Count(left, right TSize) int {
	return left.r * right.c * left.c // Cost = rows of Left * columns of Right * columns of Left
}

// Recursive function to solve the matrix chain multiplication problem
func (solver *TMcmSolver) Solve(s, l int) int {
	if s == l {
		return 0 // Base case: no cost if there is only one matrix
	}
	if solver.FMemo[s][l] != 0 {
		return solver.FMemo[s][l] // Return cached result if already computed
	}
	if s+1 == l {
		// If there are two matrices, calculate the cost directly
		solver.FMemo[s][l] = Count(solver.FChain[s], solver.FChain[l])
	} else {
		minCost := math.MaxInt32 // Initialize minimum cost to maximum possible value
		// Try every possible split point to find the minimum cost
		for i := s; i < l; i++ {
			c := solver.Solve(s, i) + Count(TSize{solver.FChain[s].r, solver.FChain[i].c}, TSize{solver.FChain[i+1].r, solver.FChain[l].c}) + solver.Solve(i+1, l)
			if c < minCost {
				minCost = c // Update minimum cost
			}
		}
		solver.FMemo[s][l] = minCost // Store the minimum cost in the memoization table
	}
	return solver.FMemo[s][l] // Return the computed minimum cost
}

// Constructor to initialize the solver with a chain of matrices
func NewTMcmSolver(chain []TSize) *TMcmSolver {
	memo := make([][]int, len(chain))
	for i := range memo {
		memo[i] = make([]int, len(chain))
	}
	return &TMcmSolver{FMemo: memo, FChain: chain}
}

// Function to get the final answer (minimum multiplication cost)
func (solver *TMcmSolver) Answer() int {
	return solver.Solve(0, len(solver.FMemo)-1) // Solve for the entire chain
}

func main() {
	var n int // Number of matrices
	fmt.Scan(&n) // Input the number of matrices
	if n == 1 {
		fmt.Println(0) // If there is only one matrix, no multiplication is needed
		return
	}

	chain := make([]TSize, n) // Slice to hold the sizes of the matrices
	for i := 0; i < n; i++ {
		fmt.Scan(&chain[i].r, &chain[i].c) // Input the dimensions of each matrix
	}

	solver := NewTMcmSolver(chain) // Create an instance of the solver with the matrix chain

	fmt.Println(solver.Answer()) // Output the minimum multiplication cost
	// Uncomment to print the memoization table
	// solver.Print()
}

// Uncomment to print the memoization table (for debugging purposes)
// func (solver *TMcmSolver) Print() {
//     for s := 0; s < len(solver.FMemo); s++ {
//         for l := 0; l < len(solver.FMemo[0]); l++ {
//             fmt.Printf("%d\t", solver.FMemo[s][l]) // Print each value in the table
//         }
//         fmt.Println() // New line after each row
//     }
// }

