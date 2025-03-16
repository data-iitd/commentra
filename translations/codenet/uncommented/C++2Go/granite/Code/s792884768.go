
package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

type TSize struct {
    r int
    c int
}

func NewTSize(r int, c int) *TSize {
    return &TSize{r, c}
}

func Count(left *TSize, right *TSize) int {
    return left.r * right.c * left.c
}

type TMcmSolver struct {
    chain []TSize
    memo  [][]int
}

func NewTMcmSolver(chain []TSize) *TMcmSolver {
    return &TMcmSolver{chain, make([][]int, len(chain))}
}

func (solver *TMcmSolver) Solve(s int, l int) int {
    if s == l {
        return 0
    }
    if solver.memo[s][l]!= 0 {
        return solver.memo[s][l]
    }
    if s+1 == l {
        solver.memo[s][l] = Count(&solver.chain[s], &solver.chain[l])
    } else {
        min := 1 << 30
        for i := s; i < l; i++ {
            c := solver.Solve(s, i) + Count(NewTSize(solver.chain[s].r, solver.chain[i].c), NewTSize(solver.chain[i+1].r, solver.chain[l].c)) + solver.Solve(i+1, l)
            if c < min {
                min = c
            }
        }
        solver.memo[s][l] = min
    }
    return solver.memo[s][l]
}

func (solver *TMcmSolver) Answer() int {
    return solver.Solve(0, len(solver.chain)-1)
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    chain := make([]TSize, n)
    for i := 0; i < n; i++ {
        a := strings.Split(readLine(reader), " ")
        r, _ := strconv.Atoi(a[0])
        c, _ := strconv.Atoi(a[1])
        chain[i] = *NewTSize(r, c)
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

