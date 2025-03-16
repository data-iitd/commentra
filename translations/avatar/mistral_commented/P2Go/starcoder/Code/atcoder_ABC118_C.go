// Ask the user for the number of elements in the list
N := int(input())

// Get a list of integers from the user input
A := []int{}
for i := 0; i < N; i++ {
    A = append(A, int(input()))
}

// Import the math/big and math/rand modules
import (
    "math/big"
    "math/rand"
)

// Define a function to calculate the greatest common divisor (GCD) of two integers
func gcd(a, b int) int {
    if b == 0 {
        return a
    }
    return gcd(b, a % b)
}

// Use big.Int.GCD() to calculate the GCD of all integers in the list A
var gcd big.Int
for _, a := range A {
    gcd.GCD(gcd.SetInt64(a), gcd.SetInt64(0))
}

// Print the result, which is the GCD of all the integers in the list A
fmt.Println(gcd)

