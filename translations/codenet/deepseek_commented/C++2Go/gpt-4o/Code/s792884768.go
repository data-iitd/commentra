package main

// TSize structure
type TSize struct {
    r int
    c int
}

// Default constructor
func NewTSize() TSize {
    return TSize{r: 0, c: 0}
}

// Parameterized constructor
func NewTSizeWithValues(Ar, Ac int) TSize {
    return TSize{r: Ar, c: Ac}
}

// Example usage
func main() {
    size1 := NewTSize()            // Default constructor
    size2 := NewTSizeWithValues(5, 10) // Parameterized constructor
}

// <END-OF-CODE>
