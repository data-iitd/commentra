package main

import (
	"fmt"
)

type TSize struct {
	r int
	c int
}

func (ts TSize) String() string {
	return fmt.Sprintf("(%d, %d)", ts.r, ts.c)
}

type TMcmSolver struct {
	// Define the fields for TMcmSolver
}

func main() {
	// Example usage
	size := TSize{30, 35}
	fmt.Println("Size:", size)
	// Add more code here
