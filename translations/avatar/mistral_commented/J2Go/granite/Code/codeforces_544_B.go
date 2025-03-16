
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

// Function to check if it's possible to place the required number of 'L' islands in the grid
func printIsland(n int, count int) {
    a := (n + 1) / 2
    b := n / 2
    max := a*a + b*b

    // Check if the count is greater than the maximum number of 'L' islands that can be placed in the grid
    if count > max {
        fmt.Println("NO") // If yes, print "NO" and return from the function
        return
    }

    fmt.Println("YES") // If not, print "YES" to indicate that it's possible to place the required number of 'L' islands in the grid

    // Initialize a Scanner object'scan' to read input from the standard input stream
    scan := bufio.NewScanner(os.Stdin)
    // Initialize a StringBuilder object'sb' to store a row of the grid
    for i := 0; i < n; i++ {
        sb := &strings.Builder{}
        for j := 0; j < n; j++ {
            // If the cell is in the position where an 'L' island can be placed, append an 'L' character to the StringBuilder object and decrement the count
            if (i+j)%2 == 0 && count > 0 {
                sb.WriteString("L")
                count--
            } else {
                // Otherwise, append an 'S' character to the StringBuilder object
                sb.WriteString("S")
            }
        }
        // Print the contents of the StringBuilder object to represent a row of the grid
        fmt.Println(sb.String())
    }
}

// Entry point of the program
func main() {
    // Initialize a Scanner object'scan' to read input from the standard input stream
    scan := bufio.NewScanner(os.Stdin)
    // Read the first integer 'n' from the input
    scan.Scan()
    n, _ := strconv.Atoi(scan.Text())
    // Read the second integer 'count' from the input
    scan.Scan()
    count, _ := strconv.Atoi(scan.Text())
    // Call the printIsland function with the arguments 'n' and 'count'
    printIsland(n, count)
}

// Translate the above Go code to C++ and end with comment "