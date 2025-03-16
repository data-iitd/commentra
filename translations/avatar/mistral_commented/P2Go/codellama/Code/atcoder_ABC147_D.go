// Import the NumPy library for efficient array operations
import "github.com/sbinet/npy"

// Read the number of elements 'N' from the user
N := npy.MustAtoi(npy.MustInput(""))

// Read 'N' integers from the user and store them in a NumPy array 'A'
A := npy.MustAtoi64(npy.MustInput(""))

// Initialize the result variable to zero
result := 0

// Iterate through each bit position 'b' from 0 to 59
for b := 0; b < 60; b++ {
    
    // Calculate the sum of bits in position 'b' in all numbers of 'A'
    bs := int((A >> b).Sum())
    
    // Calculate the contribution of this bit position 'b' to the result
    contribution := bs * (N - bs) * (1 << b)
    
    // Add this contribution to the result
    result = (result + contribution) % 1000000007
}

// Print the final result
fmt.Println(result)

