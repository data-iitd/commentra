package main

import (
	"fmt"
	"math"
)

// TSize defines a structure for size
type TSize struct {
	r int
	c int
}

// NewTSize is a constructor for TSize
func NewTSize(Ar, Ac int) TSize {
	return TSize{r: Ar, c: Ac}
}

// TMcmSolver defines a struct for Memoized Chain Multiplication Calculator
type TMcmSolver struct {
	// ...
}

func main() {
	// Example usage
	size := NewTSize(3, 4)
	fmt.Println(size)
}

// <END-OF-CODE>
