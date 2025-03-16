#######
# Code
#######

// Import necessary libraries
import "fmt"

// Define constants
const (
    inf = 1000000000000000000
    mod = 1000000007
    dd = [4][2]int{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} }
    ddn = [8][2]int{ {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} }
)

// Function to read an integer list from standard input
func LI() []int {
    var a []int
    fmt.Scan(&a)
    return a
}

// Function to read an integer from standard input
func I() int {
    var a int
    fmt.Scan(&a)
    return a
}

// Function to read a float from standard input
func F() float64 {
    var a float64
    fmt.Scan(&a)
    return a
}

// Function to read a list from standard input, split by space
func LS() []string {
    var a []string
    fmt.Scan(&a)
    return a
}

// Function to read a string from standard input
func S() string {
    var a string
    fmt.Scan(&a)
    return a
}

// Main function
func main() {
    // Read input values
    a, b, c, d := LI()

    // Calculate the maximum product of pairs of numbers
    result := max(a*c, b*d, a*d, b*c)

    // Print the result
    fmt.Println(result)
}

// Function to calculate the maximum of two integers
func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

// Call the main function
main()

