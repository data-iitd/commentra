// Import the Go standard library package "fmt" for printing
import "fmt"

// Read the number of elements 'N' from the user
var N int
fmt.Scanf("%d", &N)

// Read 'N' integers from the user and store them in a Go slice 'A'
var A []int64
for i := 0; i < N; i++ {
    var x int64
    fmt.Scanf("%d", &x)
    A = append(A, x)
}

// Initialize the result variable to zero
result := int64(0)

// Iterate through each bit position 'b' from 0 to 59
for b := 0; b < 60; b++ {
    
    // Calculate the sum of bits in position 'b' in all numbers of 'A'
    bs := int64(0)
    for _, x := range A {
        bs += x >> b & 1
    }
    
    // Calculate the contribution of this bit position 'b' to the result
    contribution := bs * (N - bs) * (1 << b)
    
    // Add this contribution to the result
    result += contribution
}

// Print the final result
fmt.Printf("%d\n", result%1000000007)

