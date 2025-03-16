
// Importing necessary packages
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Main function
func main() {
    // Creating a scanner for reading input
    scanner := bufio.NewScanner(os.Stdin)

    // Reading input for number of test cases
    scanner.Scan()
    n, _ := strconv.Atoi(scanner.Text())

    // Reading input for number of operations
    scanner.Scan()
    m, _ := strconv.Atoi(scanner.Text())

    // Calling reverse function for m and adding it to n
    t := reverse(m)
    fmt.Println(t + n)
}

// Function for reversing a number
func reverse(n int) int {
    // Base case for numbers less than 10
    if n < 10 {
        return n * 10
    }

    // Initializing variables
    t := n
    r := 0

    // Reversing the number
    for t > 0 {
        // Adding the digit to the reversed number
        r = (r * 10) + t % 10

        // Moving to the next digit
        t = t / 10
    }

    // Returning the reversed number
    return r
}

// Comment "