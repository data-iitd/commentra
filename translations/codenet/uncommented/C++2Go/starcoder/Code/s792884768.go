package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

type TSize struct {
    r int
    c int
}

type TMcmSolver struct {
    Chain []TSize
    FMemo [][]int
}

func (this *TMcmSolver) Count(left, right TSize) int {
    return left.r * right.c * left.c
}

func (this *TMcmSolver) Solve(s, l int) int {
    if s == l {
        return 0
    }
    if this.FMemo[s][l]!= 0 {
        return this.FMemo[s][l]
    }
    if s+1 == l {
        this.FMemo[s][l] = this.Count(this.Chain[s], this.Chain[l])
    } else {
        min := 1<<31 - 1
        for i := s; i < l; i++ {
            c := this.Solve(s, i) + this.Count(TSize{this.Chain[s].r, this.Chain[i].c}, TSize{this.Chain[i+1].r, this.Chain[l].c}) + this.Solve(i+1, l)
            if c < min {
                min = c
            }
        }
        this.FMemo[s][l] = min
    }
    return this.FMemo[s][l]
}

func (this *TMcmSolver) Answer() int {
    return this.Solve(0, len(this.Chain)-1)
}

func main() {
    var n int
    fmt.Scanf("%d\n", &n)
    if n == 1 {
        fmt.Println(0)
        return
    }
    chain := make([]TSize, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d %d\n", &chain[i].r, &chain[i].c)
    }
    solver := TMcmSolver{chain, make([][]int, n)}
    fmt.Println(solver.Answer())
}

