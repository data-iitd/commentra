package main

import "fmt"

// Define the TSize structure
type TSize struct {
	r int
	c int
}

// Default constructor
func NewTSize() TSize {
	return TSize{r: 0, c: 0}
}

// Parameterized constructor
func NewTSizeWithParams(r int, c int) TSize {
	return TSize{r: r, c: c}
}

func main() {
	// Example usage
	size1 := NewTSize()
	size2 := NewTSizeWithParams(3, 4)

	fmt.Println("Size1:", size1)
	fmt.Println("Size2:", size2)
}

