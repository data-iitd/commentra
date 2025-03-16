package main

import (
	"fmt"
	"math"
)

type TSize struct {
	r, c int
}

type TMcmSolver struct {
	FChain []TSize
	FMemo  [][]int
}

func Count(left, right TSize) int {
	return left.r * right.c * left.c
}

func (solver TMcmSolver) Solve(s, l int) int {
	if s == l {
		return 0
	}
	if solver.FMemo[s][l] != 0 {
		return solver.FMemo[s][l]
	}
	if s+1 == l {
		solver.FMemo[s][l] = Count(solver.FChain[s], solver.FChain[l])
	} else {
		min := math.MaxInt64
		for i := s; i < l; i++ {
			c := solver.Solve(s, i) + Count(TSize{solver.FChain[s].r, solver.FChain[i].c}, TSize{solver.FChain[i+1].r, solver.FChain[l].c}) + solver.Solve(i+1, l)
			if c < min {
				min = c
			}
		}
		solver.FMemo[s][l] = min
	}
	return solver.FMemo[s][l]
}

func NewTMcmSolver(chain []TSize) TMcmSolver {
	n := len(chain)
	memo := make([][]int, n)
	for i := range memo {
		memo[i] = make([]int, n)
	}
	return TMcmSolver{FChain: chain, FMemo: memo}
}

func (solver TMcmSolver) Answer() int {
	return solver.Solve(0, len(solver.FChain)-1)
}

func (solver TMcmSolver) Print() {
	for s := 0; s < len(solver.FMemo); s++ {
		for l := 0; l < len(solver.FMemo[s]); l++ {
			fmt.Printf("%d\t", solver.FMemo[s][l])
		}
		fmt.Println()
	}
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
	// solver.Print()
}

