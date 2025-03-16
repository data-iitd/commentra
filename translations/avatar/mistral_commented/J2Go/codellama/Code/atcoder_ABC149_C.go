// Importing necessary libraries
package main

import (
    "fmt"
    "math"
)

// Main method is the entry point of the Go application
func main() {
    // Creating a Scanner object to read input from the standard input
    var stdIn = new(Scanner)

    // Reading an integer input from the user
    var x int
    fmt.Scan(&x)

    // Checking if the number is even and not equal to 2
    if x != 2 && x % 2 == 0 {
        x++
    }

    // Starting an infinite loop
    for {
        var i int
        sqrtNum := math.Sqrt(float64(x))

        // Checking for prime numbers using trial division method
        for i = 3; i <= sqrtNum; i += 2 {
            if x%i == 0 {
                break
            }
        }

        // If 'i' is greater than the square root, then the number 'x' is prime
        if i > sqrtNum {
            break
        }

        // If the loop didn't break, then the number 'x' is not prime, so we need to find the next prime number
        x += 2
    }

    // Printing the prime number found
    fmt.Println(x)
}

// Scanner is a struct that contains the input stream
type Scanner struct {
    in *bufio.Scanner
}

// NewScanner returns a new Scanner that reads from standard input
func NewScanner() *Scanner {
    return &Scanner{in: bufio.NewScanner(os.Stdin)}
}

// Next returns the next token from the input
func (s *Scanner) Next() string {
    s.in.Scan()
    return s.in.Text()
}

// END-OF-CODE
