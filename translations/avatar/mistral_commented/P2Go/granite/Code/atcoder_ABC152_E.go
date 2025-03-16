
// Importing the math module and defining a function lcm to calculate the least common multiple of two numbers a and b.
import "math"
func lcm(a, b int) int {
    // Calculate the greatest common divisor of a and b using the Gcd function.
    g := math.Gcd(a, b)
    // Return the product of a and b divided by their greatest common divisor.
    return a * b / g
}

// Setting the value of MOD to 10^9 + 7.
const MOD = 100000007

// Reading the input N and storing the list A of N integers.
var N int
fmt.Scan(&N)
A := make([]int, N)
for i := 0; i < N; i++ {
    fmt.Scan(&A[i])
}

// Initializing the variable _lcm to 1.
_lcm := 1

// Iterating through each number a in the list A and updating the value of _lcm using the lcm function.
for _, a := range A {
    // Update the value of _lcm using the lcm function.
    _lcm = lcm(_lcm, a)
}

// Calculating the answer ans using the formula _lcm * sum ( [ pow ( s, MOD - 2, MOD ) for s in A ] ) % MOD.
ans := int64(_lcm) * func() int64 {
    sum := int64(0)
    for _, s := range A {
        sum += int64(pow(s, MOD-2, MOD))
    }
    return sum % MOD
}() % MOD

// Printing the final answer.
fmt.Println(ans)
