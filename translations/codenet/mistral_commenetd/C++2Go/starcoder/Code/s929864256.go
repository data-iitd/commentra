<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

// Constants definition
const INF = 1<<60 // Infinite value for long long int
const MOD = 1000000007 // Modulus value for modular arithmetic

// Input output functions
func main() {
    // Initialize variables
    var a, b int

    // Read input values from standard input
    fmt.Scanf("%d %d", &a, &b)

    // Calculate the maximum value among a+b, a-b, and a*b
    result := max(a+b, max(a-b, a*b))

    // Output the result to standard output
    fmt.Println(result)
}

