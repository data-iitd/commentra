package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// TSize represents the size of a matrix
type TSize struct {
	r int // Number of rows
	c int // Number of columns
}

// TMcmSolver solves the Matrix Chain Multiplication problem
type TMcmSolver struct {
	chain []TSize // Matrix chain
	memo  [][]int  // Memoization table
}

// NewTMcmSolver creates a new instance of the TMcmSolver
func NewTMcmSolver(chain []TSize) *TMcmSolver {
	return &TMcmSolver{chain: chain, memo: make([][]int, len(chain))}
}

// Count calculates the cost of multiplying two matrices
func Count(left, right TSize) int {
	return left.r*right.c*left.c
}

// Solve solves the matrix chain multiplication problem
func (solver *TMcmSolver) Solve(s, l int) int {
	if s == l {
		return 0
	}
	if solver.memo[s][l]!= 0 {
		return solver.memo[s][l]
	}
	if s+1 == l {
		solver.memo[s][l] = Count(solver.chain[s], solver.chain[l])
	} else {
		min := int(^uint(0) >> 1) // Initialize minimum cost to maximum possible value
		for i := s; i < l; i++ {
			c := solver.Solve(s, i) + Count(TSize{solver.chain[s].r, solver.chain[i].c}, TSize{solver.chain[i+1].r, solver.chain[l].c}) + solver.Solve(i+1, l)
			if c < min {
				min = c
			}
		}
		solver.memo[s][l] = min
	}
	return solver.memo[s][l]
}

// Answer returns the final answer (minimum multiplication cost)
func (solver *TMcmSolver) Answer() int {
	return solver.Solve(0, len(solver.chain)-1)
}

// Print prints the memoization table (for debugging purposes)
func (solver *TMcmSolver) Print() {
	for _, row := range solver.memo {
		for _, v := range row {
			fmt.Printf("%d\t", v)
		}
		fmt.Println()
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	if n == 1 {
		fmt.Println(0)
		return
	}
	chain := make([]TSize, n)
	for i := 0; i < n; i++ {
		line := strings.Split(readLine(reader), " ")
		chain[i].r, _ = strconv.Atoi(line[0])
		chain[i].c, _ = strconv.Atoi(line[1])
	}
	solver := NewTMcmSolver(chain)
	fmt.Println(solver.Answer())
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return strings.TrimRight(string(str), "\r\n")
}

