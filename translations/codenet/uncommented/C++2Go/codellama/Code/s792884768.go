// #include <cassert>
// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <climits>

type TSize struct {
    r int
    c int
}

func NewTSize(Ar, Ac int) TSize {
    return TSize{Ar, Ac}
}

type TMcmSolver struct {
    FMemo [][]int
    FChain []TSize
}

func NewTMcmSolver(Chain []TSize) TMcmSolver {
    FMemo := make([][]int, len(Chain))
    for i := range FMemo {
        FMemo[i] = make([]int, len(Chain))
    }
    return TMcmSolver{FMemo, Chain}
}

func (this *TMcmSolver) Count(Left, Right TSize) int {
    return Left.r * Right.c * Left.c
}

func (this *TMcmSolver) Solve(s, l int) int {
    assert(s <= l)
    if s == l {
        return 0
    }
    if s+1 == l {
        this.FMemo[s][l] = this.Count(this.FChain[s], this.FChain[l])
    } else {
        min := INT_MAX
        for i := s; i < l; i++ {
            c := this.Solve(s, i) + this.Count(NewTSize(this.FChain[s].r, this.FChain[i].c), NewTSize(this.FChain[i+1].r, this.FChain[l].c)) + this.Solve(i+1, l)
            if c < min {
                min = c
            }
        }
        this.FMemo[s][l] = min
    }
    // std::cout << "Solve! [" << s << "], [" << l << "]" << std::endl; 
    return this.FMemo[s][l]
}

func (this *TMcmSolver) Answer() int {
    return this.Solve(0, len(this.FMemo)-1)
}

func (this *TMcmSolver) Print() {
    for s := 0; s < len(this.FMemo); s++ {
        for l := 0; l < len(this.FMemo[0]); l++ {
            fmt.Printf("%d\t", this.FMemo[s][l])
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
    Chain := make([]TSize, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&Chain[i].r, &Chain[i].c)
    }
    Solver := NewTMcmSolver(Chain)
    
    fmt.Println(Solver.Answer())
    // Solver.Print()
}

