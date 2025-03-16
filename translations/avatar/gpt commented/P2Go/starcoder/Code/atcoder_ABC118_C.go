// Read an integer input N, which represents the number of elements in the list
N := int(input())

// Read a line of input, split it into individual string elements, convert them to integers,
// and store them in a list A
var A []int
for _, v := range strings.Split(input(), " ") {
    A = append(A, int(v))
}

// Import necessary modules for calculating the greatest common divisor (GCD)
import "math"

// Calculate the GCD of all elements in the list A using math.GCD
var gcd int
for i := 0; i < len(A); i++ {
    gcd = math.GCD(gcd, A[i])
}

// Print the calculated GCD
fmt.Println(gcd)

