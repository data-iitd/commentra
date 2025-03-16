
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type TSize struct {
	r int
	c int
}

type TMcmSolver struct {
	FMemo   [][]int
	FChain  []TSize
}

func Count(Left, Right TSize) int {
	return Left.r * Right.c * Left.c
}

func (solver *TMcmSolver) Solve(s, l int) int {
	if s == l {
		return 0
	}
	if solver.FMemo[s][l]!= 0 {
		return solver.FMemo[s][l]
	}
	if s+1 == l {
		solver.FMemo[s][l] = Count(solver.FChain[s], solver.FChain[l])
	} else {
		min := 1 << 30
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

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of matrices:")
	n, _ := strconv.Atoi(reader.ReadLine()[0:1])
	if n == 1 {
		fmt.Println(0)
		return
	}
	chain := make([]TSize, n)
	for i := 0; i < n; i++ {
		fmt.Println("Enter the dimensions of matrix", i+1, "(r c):")
		r, _ := strconv.Atoi(reader.ReadLine()[0:1])
		c, _ := strconv.Atoi(reader.ReadLine()[0:1])
		chain[i] = TSize{r, c}
	}
	solver := TMcmSolver{make([][]int, n), chain}
	fmt.Println(solver.Solve(0, n-1))
}

