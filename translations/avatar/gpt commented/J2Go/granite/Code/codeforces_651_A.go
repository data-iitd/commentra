
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Create a scanner for input and a writer for output
    scanner := bufio.NewScanner(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    // Read two integers from input
    scanner.Scan()
    a, _ := strconv.Atoi(scanner.Text())
    scanner.Scan()
    b, _ := strconv.Atoi(scanner.Text())
    c := 0 // Initialize counter for the number of operations

    // Check for the special case where both a and b are 1
    if a == 1 && b == 1 {
        fmt.Fprintln(writer, 0) // Output 0 operations needed
    } else {
        // Loop until both a and b are non-positive
        for a >= 1 || b >= 1 {
            // If a is greater than or equal to b, perform operation on a
            if a >= b {
                b++ // Increment b
                a -= 2 // Decrement a by 2
            } else {
                // If b is greater than a, perform operation on b
                a++ // Increment a
                b -= 2 // Decrement b by 2
            }

            // Check if either a or b has become non-positive
            if a <= 0 || b <= 0 {
                c++ // Increment operation counter and break
                break
            }
            c++ // Increment operation counter
        }
        // Output the total number of operations performed
        fmt.Fprintln(writer, c)
    }

    // Flush the writer and close the file
    writer.Flush()
}

// Debug method for printing objects (not used in this code)
func debug(args...interface{}) {
    a := fmt.Sprintln(args...)
    a = a[:len(a)-1]
    fmt.Fprintln(os.Stderr, a)
}

// Swap method (not used in this code)
func swap(a, b int) (int, int) {
    return b, a
}

// END-OF-CODE