// Importing the fmt module for printing output
import "fmt"

// Function to read a single line from standard input and return it as a string
// with the trailing newline character removed
func rs ( ) string {
    var s string
    fmt.Scanln ( &s )
    return s
}

// Function to read a single integer from standard input
func ri ( ) int {
    return int ( rs ( ) )
}

// Function to read a list of integers from standard input
// Each line of input is assumed to contain space-separated integers
func ri_ ( ) []int {
    var a []int
    for _, s := range rs ( ).Split ( " " ) {
        a = append ( a, int ( s ) )
    }
    return a
}

// Read the number of test cases from standard input
N := ri ( )

// Initialize the answer to 0
ans := 0

// Iterate through all numbers from 1 to N
for i := 1; i <= N; i++ {
    // Calculate the contribution of i to the answer
    // The formula is given by the problem statement
    ans += i * ( N / i ) * ( N / i + 1 ) / 2
}

// Print the answer
fmt.Println ( ans )

