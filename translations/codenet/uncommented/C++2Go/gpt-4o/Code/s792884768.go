package main

import (
	"fmt"
	"math"
)

type TSize struct {
	r int
	c int
}

type TMcmSolver struct {
	FMemo  [][]int
	FChain []TSize
}

func NewTMcmSolver(chain []TSize) *TMcmSolver {
	memo := make([][]int, len(chain))
	for i := range memo {
		memo[i] = make([]int, len(chain))
	}
	return &TMcmSolver{FMemo: memo, FChain: chain}
}

func (solver *TMcmSolver) Count(left, right TSize) int {
	return left.r * right.c * left.c
}

func (solver *TMcmSolver) Solve(s, l int) int {
	if s == l {
		return 0
	}
	if solver.FMemo[s][l] != 0 {
		return solver.FMemo[s][l]
	}
	if s+1 == l {
		solver.FMemo[s][l] = solver.Count(solver.FChain[s], solver.FChain[l])
	} else {
		min := math.MaxInt32
		for i := s; i < l; i++ {
			c := solver.Solve(s, i) + solver.Count(TSize{solver.FChain[s].r, solver.FChain[i].c}, TSize{solver.FChain[i+1].r, solver.FChain[l].c}) + solver.Solve(i+1, l)
			if c < min {
				min = c
			}
		}
		solver.FMemo[s][l] = min
	}
	return solver.FMemo[s][l]
}

func (solver *TMcmSolver) Answer() int {
	return solver.Solve(0, len(solver.FMemo)-1)
}

func main() {
	var n int
	fmt.Scan(&n)
	if n == 1 {
		fmt.Println(0)
		return
	}
	chain := make([]TSize, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&chain[i].r, &chain[i].c)
	}
	solver := NewTMcmSolver(chain)
	fmt.Println(solver.Answer())
	// solver.Print() // Uncomment if you want to print the memoization table
}

// <END-OF-CODE>
