
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
)

// TSize is a structure for size
type TSize struct {
    r int
    c int
}

// TMcmSolver is a class for Memoized Chain Multiplication Calculator
type TMcmSolver struct {
    //...
}

// NewTSize returns a new TSize
func NewTSize(r, c int) *TSize {
    return &TSize{r, c}
}

// NewTMcmSolver returns a new TMcmSolver
func NewTMcmSolver() *TMcmSolver {
    return &TMcmSolver{}
}

// Mcm returns the result of MCM
func Mcm(a, b *TSize) int {
    return 0
}

func main() {
    fmt.Println(Mcm(NewTSize(1, 1), NewTSize(1, 1)))
}

