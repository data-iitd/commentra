
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Creating Scanner object for reading input from the standard input
    in := bufio.NewScanner(os.Stdin)
    // Creating PrintWriter object for writing output to the standard output
    pw := bufio.NewWriter(os.Stdout)

    // Reading two integers 'a' and 'b' from the standard input
    a, _ := strconv.Atoi(in.Text())
    b, _ := strconv.Atoi(in.Text())

    // Initializing variable 'c' to 0
    c := 0

    // Checking if both 'a' and 'b' are equal to 1. If yes, then print 0 and exit
    if a == 1 && b == 1 {
        fmt.Println(0)
        os.Exit(0)
    }

    // If 'a' is not equal to 1 and 'b' is not equal to 1, then perform the following steps
    else {
        // Performing the loop until either 'a' or 'b' becomes 0
        for a >= 1 || b >= 1 {
            // If 'a' is greater than or equal to 'b', then decrement 'b' and increment 'a' by 2
            if a >= b {
                b++
                a -= 2
            }
            // If 'a' is less than 'b', then increment 'a' and decrement 'b' by 2
            else {
                a++
                b--
            }

            // Checking if either 'a' or 'b' has become 0. If yes, then increment 'c' and break the loop
            if a <= 0 || b <= 0 {
                c++
                break
            }

            // Incrementing 'c' for each iteration of the loop
            c++
        }

        // Printing the final result 'c' as the output
        fmt.Println(c)
    }

    // Closing the PrintWriter object
    pw.Flush()
}

// Static method for swapping two integers
func swap(a, b int) {
    // Swapping 'a' and 'b' by using a temporary variable 't'
    t := b
    b = a
    a = t
}

// Static method for debugging purposes
func debug(obj ...interface{}) {
    // Printing the debug information using Arrays.deepToString() method
    fmt.Println(obj)
}

// Helper method for exiting the main function
func exitMainFunction() {
    os.Exit(0)
}

