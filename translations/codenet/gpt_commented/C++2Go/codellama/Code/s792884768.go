// <START-OF-CODE>
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
	FMemo [][]int // Memoization table to store intermediate results
	FChain []TSize // Reference to the chain of matrices
}

// Function to calculate the cost of multiplying two matrices
func Count(Left, Right TSize) int {
	return Left.r * Right.c * Left.c // Cost = rows of Left * columns of Right * columns of Left
}

// Recursive function to solve the matrix chain multiplication problem
func (this *TMcmSolver) Solve(s, l int) int {
	assert(s <= l) // Ensure the start index is less than or equal to the end index
	if s == l {
		return 0 // Base case: no cost if there is only one matrix
	}
	if this.FMemo[s][l] != 0 {
		return this.FMemo[s][l] // Return cached result if already computed
	}
	if s+1 == l {
		// If there are two matrices, calculate the cost directly
		this.FMemo[s][l] = Count(this.FChain[s], this.FChain[l])
	} else {
		min := math.MaxInt32 // Initialize minimum cost to maximum possible value
		// Try every possible split point to find the minimum cost
		for i := s; i < l; i++ {
			// Calculate cost of multiplying the two parts and add the cost of multiplying the resulting matrices
			c := this.Solve(s, i) + Count(TSize{this.FChain[s].r, this.FChain[i].c}, TSize{this.FChain[i+1].r, this.FChain[l].c}) + this.Solve(i+1, l)
			min = int(math.Min(float64(min), float64(c))) // Update minimum cost
		}
		this.FMemo[s][l] = min // Store the minimum cost in the memoization table
	}
	// fmt.Println("Solve! [" + strconv.Itoa(s) + "], [" + strconv.Itoa(l) + "]")
	return this.FMemo[s][l] // Return the computed minimum cost
}

// Constructor to initialize the solver with a chain of matrices
func NewTMcmSolver(Chain []TSize) *TMcmSolver {
	this := new(TMcmSolver)
	this.FChain = Chain
	// Resize the memoization table based on the size of the chain
	this.FMemo = make([][]int, len(Chain))
	for i := 0; i < len(this.FMemo); i++ {
		this.FMemo[i] = make([]int, len(Chain))
	}
	return this
}

// Function to get the final answer (minimum multiplication cost)
func (this *TMcmSolver) Answer() int {
	return this.Solve(0, len(this.FMemo)-1) // Solve for the entire chain
}

// Function to print the memoization table (for debugging purposes)
func (this *TMcmSolver) Print() {
	for s := 0; s < len(this.FMemo); s++ {
		for l := 0; l < len(this.FMemo[0]); l++ {
			fmt.Printf("%d\t", this.FMemo[s][l]) // Print each value in the table
		}
		fmt.Println() // New line after each row
	}
}

func main() {
	var n int // Number of matrices
	fmt.Scan(&n) // Input the number of matrices
	if n == 1 {
		fmt.Println(0) // If there is only one matrix, no multiplication is needed
		return // Exit the program
	}

	Chain := make([]TSize, n) // Vector to hold the sizes of the matrices
	for i := 0; i < n; i++ {
		fmt.Scan(&Chain[i].r, &Chain[i].c) // Input the dimensions of each matrix
	}

	Solver := NewTMcmSolver(Chain) // Create an instance of the solver with the matrix chain

	fmt.Println(Solver.Answer()) // Output the minimum multiplication cost
	// Solver.Print() // Uncomment to print the memoization table
}
// 